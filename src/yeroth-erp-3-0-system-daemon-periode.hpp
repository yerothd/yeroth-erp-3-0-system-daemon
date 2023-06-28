/*
 * yeroth-erp-3-0-system-daemon-periode.hpp
 *
 *      Author: Dr.-Ing. (ABD) Xavier Noumbissi Noundou
 */

#ifndef YEROTH_ERP_3_0_SYSTEM_DAEMON_PERIOD_TIME_HPP_
#define YEROTH_ERP_3_0_SYSTEM_DAEMON_PERIOD_TIME_HPP_

#include "src/include/yeroth-erp-3-0-system-daemon-alert-abstract-entity.hpp"


class YEROTH_ERP_SYSTEM_DAEMON_LOGGER;


class YEROTH_ERP_SYSTEM_DAEMON_ALERT_PERIOD_TIME:public
    YEROTH_ERP_SYSTEM_DAEMON_ALERT_ABSTRACT_ENTITY
{
Q_OBJECT public:
    YEROTH_ERP_SYSTEM_DAEMON_ALERT_PERIOD_TIME(YEROTH_ERP_SYSTEM_DAEMON_LOGGER
                                               * logger);

    ~YEROTH_ERP_SYSTEM_DAEMON_ALERT_PERIOD_TIME();

public slots:
    void doChecks();

protected:

    virtual void process_courrier_alertes
    (const QString &TRIGGER_CONDITION,
     const _StockRecord__FOR_ALERT_QUANTITY &aStockQuantiteAlerteData);

};


#endif /* YEROTH_ERP_3_0_SYSTEM_DAEMON_PERIOD_TIME_HPP_ */
