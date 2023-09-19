/*
 * yeroth-erp-3-0-system-daemon-periode.cpp
 *
 *      Author: PROF. DR.-ING. DIPL.-INF. Xavier Noumbissi Noundou
 */

#include "yeroth-erp-3-0-system-daemon-periode.hpp"


#include "src/entities/yeroth-erp-3-0-system-daemon-entity-alert-quantity-period-time.hpp"

#include "src/utils/yeroth-erp-3-0-system-daemon-utils.hpp"

#include "src/utils/yeroth-erp-database-table-column.hpp"

#include "yeroth-erp-3-0-system-daemon-logger.hpp"


YEROTH_ERP_SYSTEM_DAEMON_ALERT_PERIOD_TIME::YEROTH_ERP_SYSTEM_DAEMON_ALERT_PERIOD_TIME(YEROTH_ERP_SYSTEM_DAEMON_LOGGER *logger):YEROTH_ERP_SYSTEM_DAEMON_ALERT_ABSTRACT_ENTITY
    (logger)
{
    //qDebug() << "[YerenAlertPeriode][YerenAlertPeriode]";
    //*_logger << "[YerenAlertPeriode][YerenAlertPeriode]\n";

    _alertesTimer = new QTimer(this);

    doChecks();

    QObject::connect(_alertesTimer,
                     SIGNAL(timeout()), this, SLOT(doChecks()));

    //ALERT_PERIOD_TIME_INTERVAL
    QString strQuery("SELECT valeur_configuration FROM configurations"
             	 	 " WHERE nom_configuration = 'ALERT_PERIOD_TIME_INTERVAL'");

    QSqlQuery query;

    int querySize = YerothERPAlertUtils::execQuery(query, strQuery);


	_dbusServer->YR_slot_refresh_SELECT_DB_MYSQL__CALLED
					(QString("%1;%2;%3")
						.arg("configurations.ALERT_PERIOD_TIME_INTERVAL",
							 "yeroth-erp-3-0-system-daemon-periode.cpp",
							 QString::number(38)));


    bool success = (querySize > 0);

    if (!success)
    {
        qDebug() << "\t\treason for failing | couldn't read "
                 "the time interval for checking alerts over time periods: " << query.
                 lastError();
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


YEROTH_ERP_SYSTEM_DAEMON_ALERT_PERIOD_TIME::
~YEROTH_ERP_SYSTEM_DAEMON_ALERT_PERIOD_TIME()
{
    delete _alertesTimer;
}


void YEROTH_ERP_SYSTEM_DAEMON_ALERT_PERIOD_TIME::doChecks()
{
    QString TODAY = DATE_TO_DB_FORMAT_STRING(GET_CURRENT_DATE);

    QString
    strQuery(QString
             ("select * from %1 where %2='-1' AND %3='0' AND (%4 <= '%5' AND %6 >= '%7') ").
             arg(YerothERPAlertUtils::ALERTES,
                 YerothDatabaseTableColumn::QUANTITE,
                 YerothDatabaseTableColumn::ALERTE_RESOLUE,
                 YerothDatabaseTableColumn::DATE_DEBUT, TODAY,
                 YerothDatabaseTableColumn::DATE_FIN, TODAY));

    QSqlQuery query;

//      QDEBUG_STRING_OUTPUT_2("strQuery", strQuery);

    int querySize = YerothERPAlertUtils::execQuery(query, strQuery);


	_dbusServer->YR_slot_refresh_SELECT_DB_MYSQL__CALLED
					(QString("%1;%2;%3")
						.arg(YerothERPAlertUtils::ALERTES,
							 "yeroth-erp-3-0-system-daemon-periode.cpp",
							 QString::number(100)));


//      QDEBUG_STRING_OUTPUT_2_N("querySize", querySize);

    bool success = (querySize > 0);

    if (!success)
    {
        qDebug() << "\t\treason for failing | " << query.lastError();
    }
    else
    {
        QList < _StockRecord__FOR_ALERT_QUANTITY * >stocks_to_check;

        QSqlRecord alertes__PERIOD__TIME__Record;

        _StockRecord__FOR_ALERT_QUANTITY *_aStockForAlertData = 0;

        while (query.next())
        {
            alertes__PERIOD__TIME__Record.clear();

            alertes__PERIOD__TIME__Record = query.record();

            _aStockForAlertData = new _StockRecord__FOR_ALERT_QUANTITY;

            _aStockForAlertData->_date_debut =
                            alertes__PERIOD__TIME__Record.
                            value(YerothDatabaseTableColumn::DATE_DEBUT).toDate();

            _aStockForAlertData->_date_fin =
                            alertes__PERIOD__TIME__Record.
                            value(YerothDatabaseTableColumn::DATE_FIN).toDate();

            _aStockForAlertData->_notifications =
                            GET_SQL_RECORD_DATA(alertes__PERIOD__TIME__Record,
                                                YerothDatabaseTableColumn::NOTIFICATIONS).
                            toInt();

            _aStockForAlertData->_quantite =
                            GET_SQL_RECORD_DATA(alertes__PERIOD__TIME__Record,
                                                YerothDatabaseTableColumn::QUANTITE).
                            toDouble();

            _aStockForAlertData->_alerte_resolue =
                            GET_SQL_RECORD_DATA(alertes__PERIOD__TIME__Record,
                                                YerothDatabaseTableColumn::ALERTE_RESOLUE).
                            toInt();

            _aStockForAlertData->_designation =
                            GET_SQL_RECORD_DATA(alertes__PERIOD__TIME__Record,
                                                YerothDatabaseTableColumn::DESIGNATION);

            _aStockForAlertData->_destinataire =
                            GET_SQL_RECORD_DATA(alertes__PERIOD__TIME__Record,
                                                YerothDatabaseTableColumn::DESTINATAIRE);

            _aStockForAlertData->_nom_complet_destinataire =
                            GET_SQL_RECORD_DATA(alertes__PERIOD__TIME__Record,
                                                YerothDatabaseTableColumn::
                                                NOM_COMPLET_DESTINATAIRE);

            _aStockForAlertData->_designation_alerte =
                            GET_SQL_RECORD_DATA(alertes__PERIOD__TIME__Record,
                                                YerothDatabaseTableColumn::
                                                DESIGNATION_ALERTE);

            _aStockForAlertData->_message_alerte =
                            GET_SQL_RECORD_DATA(alertes__PERIOD__TIME__Record,
                                                YerothDatabaseTableColumn::MESSAGE_ALERTE);

            _aStockForAlertData->_condition_alerte =
                            GET_SQL_RECORD_DATA(alertes__PERIOD__TIME__Record,
                                                YerothDatabaseTableColumn::CONDITION_ALERTE);

            _aStockForAlertData->_id_alerte =
                            GET_SQL_RECORD_DATA(alertes__PERIOD__TIME__Record,
                                                YerothDatabaseTableColumn::ID);

            _aStockForAlertData->_stockDesignation =
                            GET_SQL_RECORD_DATA(alertes__PERIOD__TIME__Record,
                                                YerothDatabaseTableColumn::DESIGNATION);

            stocks_to_check.append(_aStockForAlertData);
        }

        QString A_QUANTITY_TRIGGER_CONDITION;

        for (int i = 0; i < stocks_to_check.size(); ++i)
        {
            _aStockForAlertData = stocks_to_check.at(i);

            A_QUANTITY_TRIGGER_CONDITION.clear();

            A_QUANTITY_TRIGGER_CONDITION.
            append(QString("%1='%2' AND %3='%4' AND %5='-1'").
                   arg(YerothDatabaseTableColumn::DESTINATAIRE,
                       _aStockForAlertData->_destinataire,
                       YerothDatabaseTableColumn::DESIGNATION_ALERTE,
                       _aStockForAlertData->_designation_alerte,
                       YerothDatabaseTableColumn::QUANTITE));

            process_courrier_alertes(A_QUANTITY_TRIGGER_CONDITION,
                                     *_aStockForAlertData);
        }

        for (int i = 0; i < stocks_to_check.size(); ++i)
        {
            _aStockForAlertData = stocks_to_check.at(i);

            delete _aStockForAlertData;
        }
    }
}


void
YEROTH_ERP_SYSTEM_DAEMON_ALERT_PERIOD_TIME::process_courrier_alertes
(const QString &TRIGGER_CONDITION,
 const _StockRecord__FOR_ALERT_QUANTITY &aStockQuantiteAlerteData)
{
//      QDEBUG_STRING_OUTPUT_2("YEROTH_ERP_SYSTEM_DAEMON_ALERT_PERIOD_TIME::process_courrier_alertes",
//                                                      TRIGGER_CONDITION);

    YEROTH_ERP_SYSTEM_DAEMON_ALERT_ABSTRACT_ENTITY::process_courrier_alertes
    (TRIGGER_CONDITION, aStockQuantiteAlerteData);
}
