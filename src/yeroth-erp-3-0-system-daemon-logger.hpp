/*
 * yeren-erp-alert-logger.hpp
 *
 *      Author: Dr.-Ing. (ABD) Xavier Noumbissi Noundou
 */

#ifndef SRC_YEROTH_LOGGER_HPP_
#define SRC_YEROTH_LOGGER_HPP_

#include <QtCore/QString>

class QDebug;
class QFile;

class YEROTH_ERP_SYSTEM_DAEMON_LOGGER
{
public:

    typedef enum _YEROTH_LOG_LEVEL
    {
        YEROTH_DEBUG = 0,
        YEROTH_LOG,
        YEROTH_WARN
    } YEROTH_LOG_LEVEL;

    YEROTH_ERP_SYSTEM_DAEMON_LOGGER(QString cppClassName,
                                    YEROTH_LOG_LEVEL logLevel = YEROTH_LOG);

    ~YEROTH_ERP_SYSTEM_DAEMON_LOGGER();

    void debug(const char *cppMethodName, const char *msg = "");

    void debug(const char *cppMethodName, QString msg);

    void log(const char *cppMethodName, const char *msg = "");

    void log(const char *cppMethodName, QString msg);

    YEROTH_ERP_SYSTEM_DAEMON_LOGGER &operator<< (const char *s);
    YEROTH_ERP_SYSTEM_DAEMON_LOGGER &operator<< (QString s);
    YEROTH_ERP_SYSTEM_DAEMON_LOGGER &operator<< (bool s);
    YEROTH_ERP_SYSTEM_DAEMON_LOGGER &operator<< (int s);
    YEROTH_ERP_SYSTEM_DAEMON_LOGGER &operator<< (char s);
    YEROTH_ERP_SYSTEM_DAEMON_LOGGER &operator<< (QByteArray s);

    inline void *operator  new[](size_t size)
    {
        return malloc(size);
    }

    inline void *operator  new (size_t size)
    {
        return malloc(size);
    }

    inline void operator  delete[](void *ptr)
    {
        free(ptr);
    }

    inline void operator  delete[](void *ptr, size_t)
    {
        free(ptr);
    }

    inline void operator  delete (void *ptr)
    {
        free(ptr);
    }

    inline void operator  delete (void *ptr, size_t)
    {
        free(ptr);
    }

private:

    YEROTH_LOG_LEVEL _logLevel;

    QString _cppClassName;

    QDebug *_qDebug;
    QFile *_logFile;
};


#endif //SRC_YEROTH_LOGGER_HPP_
