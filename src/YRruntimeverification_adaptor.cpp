/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -a src/YRruntimeverification_adaptor src/dbus/yr.db-runtime.verif.xml
 *
 * qdbusxml2cpp is Copyright (C) 2020 The Qt Company Ltd.
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#include "src/YRruntimeverification_adaptor.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

/*
 * Implementation of adaptor class IYRruntimeverificationAdaptor
 */

IYRruntimeverificationAdaptor::IYRruntimeverificationAdaptor(QObject *parent)
    : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

IYRruntimeverificationAdaptor::~IYRruntimeverificationAdaptor()
{
    // destructor
}

bool IYRruntimeverificationAdaptor::YR_slot_refresh_DELETE_DB_MYSQL(const QString &in0, uint in1)
{
    // handle method call com.yeroth.rd.IYRruntimeverification.YR_slot_refresh_DELETE_DB_MYSQL
    bool out0;
    QMetaObject::invokeMethod(parent(), "YR_slot_refresh_DELETE_DB_MYSQL", Q_RETURN_ARG(bool, out0), Q_ARG(QString, in0), Q_ARG(uint, in1));
    return out0;
}

bool IYRruntimeverificationAdaptor::YR_slot_refresh_INSERT_DB_MYSQL(const QString &in0, uint in1)
{
    // handle method call com.yeroth.rd.IYRruntimeverification.YR_slot_refresh_INSERT_DB_MYSQL
    bool out0;
    QMetaObject::invokeMethod(parent(), "YR_slot_refresh_INSERT_DB_MYSQL", Q_RETURN_ARG(bool, out0), Q_ARG(QString, in0), Q_ARG(uint, in1));
    return out0;
}

bool IYRruntimeverificationAdaptor::YR_slot_refresh_SELECT_DB_MYSQL(const QString &in0, uint in1)
{
    // handle method call com.yeroth.rd.IYRruntimeverification.YR_slot_refresh_SELECT_DB_MYSQL
    bool out0;
    QMetaObject::invokeMethod(parent(), "YR_slot_refresh_SELECT_DB_MYSQL", Q_RETURN_ARG(bool, out0), Q_ARG(QString, in0), Q_ARG(uint, in1));
    return out0;
}

bool IYRruntimeverificationAdaptor::YR_slot_refresh_UPDATE_DB_MYSQL(const QString &in0, uint in1)
{
    // handle method call com.yeroth.rd.IYRruntimeverification.YR_slot_refresh_UPDATE_DB_MYSQL
    bool out0;
    QMetaObject::invokeMethod(parent(), "YR_slot_refresh_UPDATE_DB_MYSQL", Q_RETURN_ARG(bool, out0), Q_ARG(QString, in0), Q_ARG(uint, in1));
    return out0;
}

