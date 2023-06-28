/*
 * yeroth-erp-3-0-system-daemon-abstract-entity.hpp
 *
 *      Author: Dr.-Ing. (ABD) Xavier Noumbissi Noundou
 */

#ifndef YEROTH_ERP_3_0_SYSTEM_DAEMON_ABSTRACT_ENTITY_HPP_
#define YEROTH_ERP_3_0_SYSTEM_DAEMON_ABSTRACT_ENTITY_HPP_


#include "src/include/yeroth-erp-3-0-definition-oo-class-operators.hpp"

#include "src/utils/yeroth-erp-3-0-system-daemon-utils.hpp"


#include <QtCore/QTimer>

#include <QtSql/QSqlRecord>

#include <QtSql/QSqlQuery>

#include <QtSql/QSqlError>

#include <QtCore/QObject>

#include <QtCore/QString>


class QTimer;

class YEROTH_ERP_SYSTEM_DAEMON_LOGGER;


class YEROTH_ERP_SYSTEM_DAEMON_ABSTRACT_ENTITY:public QObject
{
Q_OBJECT public:

    YEROTH_CLASS_OPERATORS
    inline YEROTH_ERP_SYSTEM_DAEMON_ABSTRACT_ENTITY()
	:_dbusServer(0),
	 _alertesTimeIntervall(0),
     _alertesTimer(0),
	 _logger(0)
    {
    	_dbusServer = new YEROTH_RUNTIME_VERIFIER;
    }

    inline YEROTH_ERP_SYSTEM_DAEMON_ABSTRACT_ENTITY(YEROTH_ERP_SYSTEM_DAEMON_LOGGER *aLogger)
    :_dbusServer(0),
	 _alertesTimeIntervall(0),
	 _alertesTimer(0),
	 _logger(aLogger)
    {
    	_dbusServer = new YEROTH_RUNTIME_VERIFIER;
    }

    inline virtual ~YEROTH_ERP_SYSTEM_DAEMON_ABSTRACT_ENTITY()
    {
    	delete _dbusServer;
    }


    inline YEROTH_RUNTIME_VERIFIER *dbusServer()
    {
        return _dbusServer;
    }


protected:

    YEROTH_RUNTIME_VERIFIER *_dbusServer;

    int _alertesTimeIntervall;

    QTimer *_alertesTimer;

    YEROTH_ERP_SYSTEM_DAEMON_LOGGER *_logger;
};


#endif /* YEROTH_ERP_3_0_SYSTEM_DAEMON_ABSTRACT_ENTITY_HPP_ */
