/*
 * yeroth-erp-3-0-system-daemon-alert-abstract-entity.cpp
 *
 *      Author: PROF. DR.-ING. DIPL.-INF. Xavier Noumbissi Noundou
 */


#include "yeroth-erp-3-0-system-daemon-alert-abstract-entity.hpp"


#include "src/entities/yeroth-erp-3-0-system-daemon-entity-alert-quantity-period-time.hpp"

#include "src/utils/yeroth-erp-database-table-column.hpp"


void YEROTH_ERP_SYSTEM_DAEMON_ALERT_ABSTRACT_ENTITY::
		process_courrier_alertes(const QString	 						&TRIGGER_CONDITION,
								 const _StockRecord__FOR_ALERT_QUANTITY &aStockQuantiteAlerteData)
{
    //We need to send an alert message to the recipient so he handle
    //alert. But we first check if such a notice is present; if yes,
    //we then only increment the field 'notification' of table 'alertes'.

    QString strCourriersQuery(QString("select * from %1 where (%2) AND (%3='%4')")
                      	  	  	  .arg(YerothERPAlertUtils::COURRIERS_ALERTES,
                      	  	  		   TRIGGER_CONDITION,
									   YerothDatabaseTableColumn::DESIGNATION,
									   aStockQuantiteAlerteData._stockDesignation));

    QSqlQuery queryCourriersAlertes;

    bool successAlertInsert = false;

    int courriersQuerySize = YerothERPAlertUtils::execQuery(queryCourriersAlertes,
    														strCourriersQuery);

//      QDEBUG_STRING_OUTPUT_2_N("courriersQuerySize", courriersQuerySize);

    if (courriersQuerySize <= 0)
    {
//              QDEBUG_STRING_OUTPUT_2("strCourriersQuery", strCourriersQuery);

        //Precondition: there is only one message to each recipient for an alert
        QSqlRecord courrierRecord = queryCourriersAlertes.record();


        QString strCourrierInsertQuery
					(QString("INSERT INTO %1 (%2, %3, %4, %5, %6, %7,")
                         .arg(YerothERPAlertUtils::COURRIERS_ALERTES,
                              YerothDatabaseTableColumn::ID,
                              YerothDatabaseTableColumn::DESIGNATION,
                              YerothDatabaseTableColumn::DESTINATAIRE,
                              YerothDatabaseTableColumn::NOM_COMPLET_DESTINATAIRE,
                              YerothDatabaseTableColumn::DESIGNATION_ALERTE,
                              YerothDatabaseTableColumn::MESSAGE_ALERTE));


        strCourrierInsertQuery
			.append(QString(" %1, %2, %3, %4, %5, %6)")
                         .arg(YerothDatabaseTableColumn::CONDITION_ALERTE,
                              YerothDatabaseTableColumn::ID_ALERTE,
                              YerothDatabaseTableColumn::ALERTE_RESOLUE,
                              YerothDatabaseTableColumn::DATE_DEBUT,
                              YerothDatabaseTableColumn::DATE_FIN,
                              YerothDatabaseTableColumn::QUANTITE));


        strCourrierInsertQuery
			.append(QString(" VALUES (:%1, :%2, :%3, :%4, :%5, :%6, :%7, :%8, :%9,")
						.arg(YerothDatabaseTableColumn::ID,
							 YerothDatabaseTableColumn::DESIGNATION,
							 YerothDatabaseTableColumn::DESTINATAIRE,
							 YerothDatabaseTableColumn::NOM_COMPLET_DESTINATAIRE,
							 YerothDatabaseTableColumn::DESIGNATION_ALERTE,
							 YerothDatabaseTableColumn::MESSAGE_ALERTE,
							 YerothDatabaseTableColumn::CONDITION_ALERTE,
							 YerothDatabaseTableColumn::ID_ALERTE,
							 YerothDatabaseTableColumn::ALERTE_RESOLUE));

        strCourrierInsertQuery
			.append(QString(" :%1, :%2, :%3) ")
                        .arg(YerothDatabaseTableColumn::DATE_DEBUT,
                             YerothDatabaseTableColumn::DATE_FIN,
                             YerothDatabaseTableColumn::QUANTITE));


//              QDEBUG_STRING_OUTPUT_2("strCourrierInsertQuery", strCourrierInsertQuery);


        QSqlQuery insertQuery;

        insertQuery.prepare(strCourrierInsertQuery);

        insertQuery.bindValue(QString(":%1").
                              arg(YerothDatabaseTableColumn::ID),
                              YerothERPAlertUtils::
                              getNextIdFromTable(YerothERPAlertUtils::
                                                 COURRIERS_ALERTES));

        insertQuery.bindValue(QString(":%1").
                              arg(YerothDatabaseTableColumn::DESIGNATION),
                              aStockQuantiteAlerteData._stockDesignation);

        insertQuery.bindValue(QString(":%1").
                              arg(YerothDatabaseTableColumn::DESTINATAIRE),
                              aStockQuantiteAlerteData._destinataire);

        insertQuery.bindValue(QString(":%1").
                              arg(YerothDatabaseTableColumn::
                                  NOM_COMPLET_DESTINATAIRE),
                              aStockQuantiteAlerteData.
                              _nom_complet_destinataire);

        insertQuery.bindValue(QString(":%1").
                              arg(YerothDatabaseTableColumn::
                                  DESIGNATION_ALERTE),
                              aStockQuantiteAlerteData._designation_alerte);

        insertQuery.bindValue(QString(":%1").
                              arg(YerothDatabaseTableColumn::MESSAGE_ALERTE),
                              aStockQuantiteAlerteData._message_alerte);

        insertQuery.bindValue(QString(":%1").
                              arg(YerothDatabaseTableColumn::
                                  CONDITION_ALERTE),
                              aStockQuantiteAlerteData._condition_alerte);

        insertQuery.bindValue(QString(":%1").
                              arg(YerothDatabaseTableColumn::ID_ALERTE),
                              aStockQuantiteAlerteData._id_alerte);

        insertQuery.bindValue(QString(":%1").
                              arg(YerothDatabaseTableColumn::ALERTE_RESOLUE),
                              aStockQuantiteAlerteData._alerte_resolue);

        insertQuery.bindValue(QString(":%1").
                              arg(YerothDatabaseTableColumn::DATE_DEBUT),
                              aStockQuantiteAlerteData._date_debut);

        insertQuery.bindValue(QString(":%1").
                              arg(YerothDatabaseTableColumn::DATE_FIN),
                              aStockQuantiteAlerteData._date_fin);

        insertQuery.bindValue(QString(":%1").
                              arg(YerothDatabaseTableColumn::QUANTITE),
                              aStockQuantiteAlerteData._quantite);

        successAlertInsert = YerothERPAlertUtils::execQuery(insertQuery);
    }
    else
    {
        successAlertInsert = true;
    }


    if (successAlertInsert && courriersQuerySize <= 0)
    {
        QString
        msg(QString
            ("Une nouvelle alerte '%1' a été envoyée à l'utilisateur '%2' (%3)").
            arg(aStockQuantiteAlerteData._designation_alerte,
                aStockQuantiteAlerteData._nom_complet_destinataire,
                aStockQuantiteAlerteData._destinataire));

        QDEBUG_STRING_OUTPUT_2("successAlertInsert, msg", msg);

        //                      *_logger << TO_UTF8_STRING(msg) << "\n";

        int notifications = aStockQuantiteAlerteData._notifications;

        notifications += 1;

        QString
        updateNotificationsAlertesQueryString(QString
                                              ("UPDATE %1 SET %2='%3' WHERE %4='%5'").
                                              arg(YerothERPAlertUtils::
                                                  ALERTES,
                                                  YerothDatabaseTableColumn::
                                                  NOTIFICATIONS,
                                                  QString::
                                                  number(notifications),
                                                  YerothDatabaseTableColumn::
                                                  ID,
                                                  aStockQuantiteAlerteData.
                                                  _id_alerte));

        YerothERPAlertUtils::execQuery(updateNotificationsAlertesQueryString);
    }
}
