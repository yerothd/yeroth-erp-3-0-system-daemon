/*
 * yeroth-erp-3-0-system-daemon-daemon-quantite.hpp
 *
 *      Author: PROF. DR.-ING. DIPL.-INF. Xavier Noumbissi Noundou
 */

#ifndef YEROTH_ERP_3_0_SYSTEM_DAEMON_QUANTITE_HPP_
#define YEROTH_ERP_3_0_SYSTEM_DAEMON_QUANTITE_HPP_

#include "src/include/yeroth-erp-3-0-system-daemon-alert-abstract-entity.hpp"

#include "src/include/yeroth-erp-3-0-software-text-configuration.hpp"


class _StockRecord__FOR_ALERT_QUANTITY;

class YEROTH_ERP_SYSTEM_DAEMON_LOGGER;


class YEROTH_ERP_SYSTEM_DAEMON_ALERT_OVER_STOCK_QUANTITY :
		public YEROTH_ERP_SYSTEM_DAEMON_ALERT_ABSTRACT_ENTITY
{
	Q_OBJECT

public:

    YEROTH_CLASS_OPERATORS

	YEROTH_ERP_SYSTEM_DAEMON_ALERT_OVER_STOCK_QUANTITY(YEROTH_ERP_SYSTEM_DAEMON_LOGGER *logger);

    inline ~YEROTH_ERP_SYSTEM_DAEMON_ALERT_OVER_STOCK_QUANTITY()
    {
        delete _alertesTimer;
    }

public slots:

    void doChecks();

protected:

    virtual void checkAlertes(const _StockRecord__FOR_ALERT_QUANTITY &
                              aStockQuantiteAlerteData);

    virtual void process_courrier_alertes
					(const QString &TRIGGER_CONDITION,
					 const _StockRecord__FOR_ALERT_QUANTITY &aStockQuantiteAlerteData);
};


#endif /* YEROTH_ERP_3_0_SYSTEM_DAEMON_QUANTITE_HPP_ */
