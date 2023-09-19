/*
 * yeroth-erp-3-0-system-daemon-alert-abstract-entity.hpp
 *
 *      Author: PROF. DR.-ING. DIPL.-INF. Xavier Noumbissi Noundou
 */

#ifndef YEROTH_ERP_3_0_SYSTEM_DAEMON_ALERT_ABSTRACT_ENTITY_HPP_
#define YEROTH_ERP_3_0_SYSTEM_DAEMON_ALERT_ABSTRACT_ENTITY_HPP_


#include "src/include/yeroth-erp-3-0-system-daemon-abstract-entity.hpp"


#include "src/utils/yeroth-erp-3-0-system-daemon-utils.hpp"


class _StockRecord__FOR_ALERT_QUANTITY;


class YEROTH_ERP_SYSTEM_DAEMON_ALERT_ABSTRACT_ENTITY :
		public YEROTH_ERP_SYSTEM_DAEMON_ABSTRACT_ENTITY
{
	Q_OBJECT

public:

    YEROTH_CLASS_OPERATORS

    inline YEROTH_ERP_SYSTEM_DAEMON_ALERT_ABSTRACT_ENTITY
			(YEROTH_ERP_SYSTEM_DAEMON_LOGGER *aLogger)
    :YEROTH_ERP_SYSTEM_DAEMON_ABSTRACT_ENTITY(aLogger)
    {
    }

    inline virtual ~YEROTH_ERP_SYSTEM_DAEMON_ALERT_ABSTRACT_ENTITY()
    {
    }

protected:

    virtual void checkAlertes(const _StockRecord__FOR_ALERT_QUANTITY &
                              aStockQuantiteAlerteData)
    {
        QDEBUG_STRING_OUTPUT_2("checkAlertes",
                               "PLEASE IMPLEMENT THIS VIRTUAL ABSTRACT METHOD !!!");
    }

    virtual void process_courrier_alertes(const QString &TRIGGER_CONDITION,
                                          const
                                          _StockRecord__FOR_ALERT_QUANTITY &
                                          aStockQuantiteAlerteData);
};


#endif /* YEROTH_ERP_3_0_SYSTEM_DAEMON_ALERT_ABSTRACT_ENTITY_HPP_ */
