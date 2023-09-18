/*
 * YEROTH_RUNTIME_VERIFIER.hpp
 *
 *  Created on: Dec 10, 2022
 *      Author: yer
 */

#ifndef SRC_DBUS_YEROTH_RUNTIME_VERIFIER_HPP_
#define SRC_DBUS_YEROTH_RUNTIME_VERIFIER_HPP_


#include "src/IYRruntimeverificationAdaptor_interface.h"


#include <QtCore/QObject>


using namespace com::yeroth::rd;


class YEROTH_RUNTIME_VERIFIER : public QObject
{
	Q_OBJECT

public:

	YEROTH_RUNTIME_VERIFIER();

	inline virtual ~YEROTH_RUNTIME_VERIFIER()
	{
	}

protected:

    inline void timerEvent(QTimerEvent *event)
    {
    //    Q_UNUSED(event);
    //
    //    if (0 != a_YR_DB_RUNTIME_VERIF_instance &&
    //    	a_YR_DB_RUNTIME_VERIF_instance->isValid())
    //    {
    //        qDebug() << "connected";
    //    }
    //    else
    //    {
    //    	qDebug() << "disconnected";
    //    }
    }

public Q_SLOTS:

	void YR_slot_refresh_DELETE_DB_MYSQL__CALLED(QString SQL_modified_CHANGED_table = "",
	   											 uint qty_DATA_modified_CHANGED = 1);

	void YR_slot_refresh_INSERT_DB_MYSQL__CALLED(QString SQL_modified_CHANGED_table = "",
	 											 uint qty_DATA_modified_CHANGED = 1);

	void YR_slot_refresh_SELECT_DB_MYSQL__CALLED(QString SQL_modified_CHANGED_table = "",
	   											 uint qty_DATA_modified_CHANGED = 1);

	void YR_slot_refresh_UPDATE_DB_MYSQL__CALLED(QString SQL_modified_CHANGED_table = "",
	   											 uint qty_DATA_modified_CHANGED = 1);


public:

	static uint _MAX_LAST_SIGNALS_SOURCE_TARGET_COUNT;

	static uint _current_MAX_LAST_SIGNALS_SOURCE_TARGET_index;

	static QStringList _LAST_SIGNALS_source_target_strings;

	static const QString DBUS_TIME_FORMAT_WITH_MILLISECONDS;

	static const QString YEROTH_ERP_PGI_SYSTEM_DAEMOM_dbus_verifier_tester_ID;

private:

	com::yeroth::rd::IYRruntimeverification *a_YR_DB_RUNTIME_VERIF_instance;

};


#define DBUS_FORMAT_TIME_WITH_MS        "HH:mm:ss:zzz"

#define DBUS_CURRENT_TIME_WITH_MILLISECONDS QTime::currentTime().toString(YEROTH_RUNTIME_VERIFIER::DBUS_TIME_FORMAT_WITH_MILLISECONDS)


#endif /* SRC_DBUS_YEROTH_RUNTIME_VERIFIER_HPP_ */
