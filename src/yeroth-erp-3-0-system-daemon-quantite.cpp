/*
 * yeroth-erp-3-0-system-daemon-quantite.cpp
 *
 *      Author: Dr.-Ing. (ABD) Xavier Noumbissi Noundou
 */

#include "yeroth-erp-3-0-system-daemon-quantite.hpp"


#include "src/entities/yeroth-erp-3-0-system-daemon-entity-alert-quantity-period-time.hpp"

#include "src/utils/yeroth-erp-3-0-system-daemon-utils.hpp"

#include "yeroth-erp-3-0-system-daemon-logger.hpp"

#include "src/utils/yeroth-erp-database-table-column.hpp"


YEROTH_ERP_SYSTEM_DAEMON_ALERT_OVER_STOCK_QUANTITY::
	YEROTH_ERP_SYSTEM_DAEMON_ALERT_OVER_STOCK_QUANTITY(YEROTH_ERP_SYSTEM_DAEMON_LOGGER *logger)
:YEROTH_ERP_SYSTEM_DAEMON_ALERT_ABSTRACT_ENTITY(logger)
{
    //qDebug() << "[YerenAlertDaemonQuantite][YerenAlertDaemonQuantite]";
    *_logger << "[erenAlertDaemonQuantite | YerenAlertDaemonQuantite]\n";

    _alertesTimer = new QTimer(this);

    doChecks();

    connect(_alertesTimer, SIGNAL(timeout()), this, SLOT(doChecks()));

    //ALERT_QUANTITY_TIME_INTERVAL
    QString strQuery("SELECT valeur_configuration FROM configurations");

    strQuery.append(" WHERE nom_configuration = 'ALERT_QUANTITY_TIME_INTERVAL'");

    QSqlQuery query;

    int querySize = YerothERPAlertUtils::execQuery(query, strQuery);


	_dbusServer->YR_slot_refresh_SELECT_DB_MYSQL__CALLED
					(QString("%1;%2;%3")
						.arg("configurations.ALERT_QUANTITY_TIME_INTERVAL",
							 "yeroth-erp-3-0-system-daemon-quantite.cpp",
							 QString::number(39)));


    bool success = (querySize > 0);

    if (!success)
    {
        qDebug() << "\t\t[reason for failing] couldn't read "
                 "the time interval for checking alerts over quantity of stocks: " <<
                 query.lastError();
    }
    else
    {
        if (query.next())
        {
            QSqlRecord
            stockRecord = query.record();

            _alertesTimeIntervall = 1000 *
                                    GET_SQL_RECORD_DATA(stockRecord,
                                                        "valeur_configuration").toInt();
            //qDebug() << "_alertesTimeIntervall: " << _alertesTimeIntervall;
        }

    }

    //doChecks() is called every _alertesTimeIntervall ms
    _alertesTimer->start(_alertesTimeIntervall);
}


void YEROTH_ERP_SYSTEM_DAEMON_ALERT_OVER_STOCK_QUANTITY::doChecks()
{
    QString strQuery(QString("select * from %1 where %2 > -1 AND %3='0'").
                     arg(YerothERPAlertUtils::ALERTES,
                         YerothDatabaseTableColumn::QUANTITE,
                         YerothDatabaseTableColumn::ALERTE_RESOLUE));

    QSqlQuery query;

//      QDEBUG_STRING_OUTPUT_2("strQuery", strQuery);

    int querySize = YerothERPAlertUtils::execQuery(query, strQuery);


	_dbusServer->YR_slot_refresh_SELECT_DB_MYSQL__CALLED
					(QString("%1;%2;%3")
						.arg(YerothERPAlertUtils::ALERTES,
							 "yeroth-erp-3-0-system-daemon-quantite.cpp",
							 QString::number(87)));


    bool success = (querySize > 0);

    if (!success)
    {
        qDebug() << "\t\t[reason for failing] " << query.lastError();
    }
    else
    {
        QList < _StockRecord__FOR_ALERT_QUANTITY * >stocks_to_check;

        QSqlRecord alertes_QUANTITY_Record;

        _StockRecord__FOR_ALERT_QUANTITY *_aStockForAlertData = 0;

        while (query.next())
        {
            alertes_QUANTITY_Record.clear();

            alertes_QUANTITY_Record = query.record();

            _aStockForAlertData = new _StockRecord__FOR_ALERT_QUANTITY;

            _aStockForAlertData->_notifications =
                            GET_SQL_RECORD_DATA(alertes_QUANTITY_Record,
                                                YerothDatabaseTableColumn::NOTIFICATIONS).
                            toInt();

            _aStockForAlertData->_quantite =
                            GET_SQL_RECORD_DATA(alertes_QUANTITY_Record,
                                                YerothDatabaseTableColumn::QUANTITE).
                            toDouble();

            _aStockForAlertData->_alerte_resolue =
                            GET_SQL_RECORD_DATA(alertes_QUANTITY_Record,
                                                YerothDatabaseTableColumn::ALERTE_RESOLUE).
                            toInt();

            _aStockForAlertData->_designation =
                            GET_SQL_RECORD_DATA(alertes_QUANTITY_Record,
                                                YerothDatabaseTableColumn::DESIGNATION);

            _aStockForAlertData->_destinataire =
                            GET_SQL_RECORD_DATA(alertes_QUANTITY_Record,
                                                YerothDatabaseTableColumn::DESTINATAIRE);

            _aStockForAlertData->_nom_complet_destinataire =
                            GET_SQL_RECORD_DATA(alertes_QUANTITY_Record,
                                                YerothDatabaseTableColumn::
                                                NOM_COMPLET_DESTINATAIRE);

            _aStockForAlertData->_designation_alerte =
                            GET_SQL_RECORD_DATA(alertes_QUANTITY_Record,
                                                YerothDatabaseTableColumn::
                                                DESIGNATION_ALERTE);

            _aStockForAlertData->_message_alerte =
                            GET_SQL_RECORD_DATA(alertes_QUANTITY_Record,
                                                YerothDatabaseTableColumn::MESSAGE_ALERTE);

            _aStockForAlertData->_condition_alerte =
                            GET_SQL_RECORD_DATA(alertes_QUANTITY_Record,
                                                YerothDatabaseTableColumn::CONDITION_ALERTE);

            _aStockForAlertData->_id_alerte =
                            GET_SQL_RECORD_DATA(alertes_QUANTITY_Record,
                                                YerothDatabaseTableColumn::ID);

            _aStockForAlertData->_stockDesignation =
                            GET_SQL_RECORD_DATA(alertes_QUANTITY_Record,
                                                YerothDatabaseTableColumn::DESIGNATION);

            stocks_to_check.append(_aStockForAlertData);
        }

        for (int i = 0; i < stocks_to_check.size(); ++i)
        {
            _aStockForAlertData = stocks_to_check.at(i);

            checkAlertes(*_aStockForAlertData);
        }

        for (int i = 0; i < stocks_to_check.size(); ++i)
        {
            _aStockForAlertData = stocks_to_check.at(i);

            delete _aStockForAlertData;
        }
    }
}


void YEROTH_ERP_SYSTEM_DAEMON_ALERT_OVER_STOCK_QUANTITY::checkAlertes(const
                                                                      _StockRecord__FOR_ALERT_QUANTITY
                                                                      &
                                                                      aStockQuantiteAlerteData)
{
    QString strQuery(QString("select %1 from %2 where %3='%4'").
                     arg(YerothDatabaseTableColumn::QUANTITE_TOTALE,
                         YerothERPAlertUtils::STOCKS,
                         YerothDatabaseTableColumn::DESIGNATION,
                         aStockQuantiteAlerteData._stockDesignation));

    QSqlQuery query;

    int querySize = YerothERPAlertUtils::execQuery(query, strQuery);


	_dbusServer->YR_slot_refresh_SELECT_DB_MYSQL__CALLED
					(QString("%1;%2;%3")
						.arg(YerothERPAlertUtils::STOCKS,
							 "yeroth-erp-3-0-system-daemon-quantite.cpp",
							 QString::number(194)));


    bool success = (querySize > 0);

    if (!success)
    {
        qDebug() << "\t\t[reason for failing] " << query.lastError();
    }
    else
    {
        double quantite_totale_dun_stock = 0.0;

        double quantite_totale_tout_stock = 0.0;

        QSqlRecord stockRecord;

        while (query.next())
        {
            stockRecord.clear();

            stockRecord = query.record();

            quantite_totale_dun_stock =
                            GET_SQL_RECORD_DATA(stockRecord,
                                                YerothDatabaseTableColumn::QUANTITE_TOTALE).
                            toDouble();

            quantite_totale_tout_stock += quantite_totale_dun_stock;
        }

        bool triggerAlert = false;

        if (YerothERPAlertUtils::
                isEqualCaseInsensitive(YerothERPAlertUtils::INFERIEUR_OU_EGAL,
                                       aStockQuantiteAlerteData._condition_alerte))
        {
            triggerAlert =
                            (quantite_totale_tout_stock <=
                             aStockQuantiteAlerteData._quantite);
        }
        else if (YerothERPAlertUtils::
                 isEqualCaseInsensitive(YerothERPAlertUtils::SUPERIEUR,
                                        aStockQuantiteAlerteData.
                                        _condition_alerte))
        {
            triggerAlert =
                            (quantite_totale_tout_stock > aStockQuantiteAlerteData._quantite);
        }

//              qDebug() << "\ttriggerAlert: " << triggerAlert;

        if (triggerAlert)
        {
            QString
            A_QUANTITY_TRIGGER_CONDITION(QString
                                         ("%1='%2' AND %3='%4' AND %5='%6'").
                                         arg(YerothDatabaseTableColumn::
                                             DESTINATAIRE,
                                             aStockQuantiteAlerteData.
                                             _destinataire,
                                             YerothDatabaseTableColumn::
                                             DESIGNATION_ALERTE,
                                             aStockQuantiteAlerteData.
                                             _designation_alerte,
                                             YerothDatabaseTableColumn::
                                             QUANTITE,
                                             QString::
                                             number
                                             (aStockQuantiteAlerteData.
                                              _quantite)));

            process_courrier_alertes(A_QUANTITY_TRIGGER_CONDITION,
                                     aStockQuantiteAlerteData);
        }
    }
}


void
YEROTH_ERP_SYSTEM_DAEMON_ALERT_OVER_STOCK_QUANTITY::process_courrier_alertes
(const QString &TRIGGER_CONDITION,
 const _StockRecord__FOR_ALERT_QUANTITY &aStockQuantiteAlerteData)
{
//      QDEBUG_STRING_OUTPUT_2("YEROTH_ERP_SYSTEM_DAEMON_ALERT_OVER_STOCK_QUANTITY::process_courrier_alertes",
//                                                      TRIGGER_CONDITION);

    YEROTH_ERP_SYSTEM_DAEMON_ALERT_ABSTRACT_ENTITY::process_courrier_alertes
    (TRIGGER_CONDITION, aStockQuantiteAlerteData);
}
