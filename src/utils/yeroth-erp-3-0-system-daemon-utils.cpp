/*
 * yeroth-erp-3-0-system-daemon-utils.cpp
 *
 *      Author: PROF. DR.-ING. DIPL.-INF. Xavier Noumbissi Noundou
 */

#include "yeroth-erp-3-0-system-daemon-utils.hpp"


#include "src/yeroth-erp-3-0-system-daemon-logger.hpp"

#include <QtCore/QDebug>
#include <QtCore/QDate>
#include <QtCore/QBuffer>
#include <QtCore/QProcess>

#include <QtSql/QSqlRecord>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

#include <QtWidgets/QLabel>
#include <QtGui/QPainter>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>

QString YerothERPAlertUtils::_mainWorkingDirectory("");

QString YerothERPAlertUtils::_logFileName("yeroth-erp-3-0-system-daemon.log");

const QString YerothERPAlertUtils::USERS("users");
const QString YerothERPAlertUtils::TITRES("titres");
const QString YerothERPAlertUtils::LOCALISATIONS("localisations");
const QString YerothERPAlertUtils::CATEGORIES("categories");
const QString YerothERPAlertUtils::CLIENTS("clients");
const QString YerothERPAlertUtils::FOURNISSEURS("fournisseurs");
const QString YerothERPAlertUtils::ALERTES("alertes");
const QString YerothERPAlertUtils::CONDITIONS_ALERTES("conditions_alertes");
const QString YerothERPAlertUtils::COURRIERS_ALERTES("courriers_alertes");
const QString YerothERPAlertUtils::STOCKS("stocks");
const QString YerothERPAlertUtils::STOCKS_VENDU("stocks_vendu");

const QString YerothERPAlertUtils::DATE_FORMAT("dd.MM.yyyy");

const QString YerothERPAlertUtils::TIME_FORMAT("HH:mm:ss");

const QString YerothERPAlertUtils::DB_DATE_FORMAT("yyyy-MM-dd");

const QString YerothERPAlertUtils::LOCALHOST("localhost");

const QString YerothERPAlertUtils::LOCALHOST_IP_ADDRESS("127.0.0.1");

const QString YerothERPAlertUtils::STRING_OUI("oui");

const QString YerothERPAlertUtils::STRING_NON("non");

const unsigned int YerothERPAlertUtils::FACTURE_PETIT_NOM_ARTICLE_MAX_CHARS(12);

const unsigned int YerothERPAlertUtils::STRING_MAX_CHARS(18);

const QString YerothERPAlertUtils::INFERIEUR_OU_EGAL("<=");

const QString YerothERPAlertUtils::SUPERIEUR(">");

const QChar YerothERPAlertUtils::SLASH_CHAR('/');


void YerothERPAlertUtils::YEROTH_CREATE_FOLDER(const QString &aFullPathDir)
{
    QFileInfo aFullPathDirInfo(aFullPathDir);

    if (!aFullPathDirInfo.exists())
    {
        qDebug() << "[YerothERPAlertUtils] YEROTH_CREATE_FOLDER"
                 << QString("Folder '%1' does not exist !").arg(aFullPathDir);

        QDir tempFileDir;

        if (tempFileDir.mkpath(aFullPathDir))
        {
            qDebug() << "[YerothERPAlertUtils] YEROTH_CREATE_FOLDER"
                     << QString("Created folder '%1' !").arg(aFullPathDir);
        }
        else
        {
            qDebug() << "[YerothERPAlertUtils] YEROTH_CREATE_FOLDER"
                     << QString("Could not Create folder '%1' !").arg(aFullPathDir);
        }
    }
}


int YerothERPAlertUtils::start_PROCESS_AND_GET_PROCESS_output_AS_QSTRING(const
                                                                         QString
                                                                         &
                                                                         program_executable_location_full_path,
                                                                         const
                                                                         QStringList
                                                                         &
                                                                         program_executable_args,
                                                                         QString
                                                                         &
                                                                         program_output_IN_OUT)
{
    program_output_IN_OUT.clear();

    QProcess A_YEROTH_PROCESS;

    A_YEROTH_PROCESS.start(program_executable_location_full_path,
                           program_executable_args);

//    qDebug() << "program_executable_location_full_path: " << program_executable_location_full_path;
//    qDebug() << "program_executable_args: " << program_executable_args;

    if (!A_YEROTH_PROCESS.waitForFinished())
    {
        return -1;
    }

    program_output_IN_OUT.append(A_YEROTH_PROCESS.readAllStandardOutput().
                                 trimmed());

    return program_output_IN_OUT.size();
}


int YerothERPAlertUtils::start_PROCESS_AND_READ_PROCESS_output_INTO_FILE(const
                                                                         QString
                                                                         &
                                                                         program_executable_location_full_path,
                                                                         const
                                                                         QString
                                                                         &
                                                                         output_file_full_path,
                                                                         const
                                                                         QStringList
                                                                         &
                                                                         program_executable_args)
{
    QProcess A_YEROTH_PROCESS;

    A_YEROTH_PROCESS.start(program_executable_location_full_path,
                           program_executable_args);

    if (!A_YEROTH_PROCESS.waitForFinished())
    {
        return -1;
    }

    QFile tmpFile(output_file_full_path);

    if (tmpFile.open(QFile::WriteOnly))
    {
        tmpFile.write(A_YEROTH_PROCESS.readAllStandardOutput().trimmed());
    }
    else
    {
        return -1;
    }

    int output_file_size = tmpFile.size();

    tmpFile.close();

    return output_file_size;
}


bool
YerothERPAlertUtils::
GZIP_YEROTH_FILE(const QString &program_working_directory_full_path,
                 const QString &file_full_path)
{
    QStringList gzipPROG_ARGS;

    gzipPROG_ARGS.append(file_full_path);

    int file_size =
                    YerothERPAlertUtils::start_PROCESS_AND_READ_PROCESS_output_INTO_FILE
                    ("/usr/bin/gzip",
                     program_working_directory_full_path,
                     QString("%1.gz").arg(file_full_path),
                     gzipPROG_ARGS);
    return (file_size >= 0);
}


QString YerothERPAlertUtils::generateSqlIs(const char *sqlTableColumn,
                                           QString searchStr)
{
    QString result;

    YerothERPAlertUtils::prepareSqlStr(searchStr);

    result.append(sqlTableColumn).append(" = \'").append(searchStr).
    append("\'");

    return result;
}


bool YerothERPAlertUtils::execQuery(const QString &strQuery,
                                    YEROTH_ERP_SYSTEM_DAEMON_LOGGER *logger)
{
    //qDebug() << "[YerothERPAlertUtils][execQuery]";

    QSqlQuery query;
    query.prepare(strQuery);
    bool success = query.exec();

    //qDebug() << "\t[" << success << "]" << query.executedQuery();

    if (logger)
    {
        logger->log("execQuery",
                    QString("[%1] %2").arg(BOOL_TO_STRING(success),
                                           query.executedQuery()));
    }

    if (!success)
    {
        if (logger)
        {
            *logger << "\t\t[reason for failing] " << query.lastError().
                    text() << "\n";
        }
        else
        {
            qDebug() << "\t\t[reason for failing] " << query.lastError();
        }
    }

    return success;
}


int YerothERPAlertUtils::execQuery(QSqlQuery &query, const QString &strQuery,
                                   YEROTH_ERP_SYSTEM_DAEMON_LOGGER *logger)
{
    //qDebug() << "[YerothERPAlertUtils][execQuery]";

    query.prepare(strQuery);
    bool success = query.exec();

    //qDebug() << "\t[" << success << "]" << query.executedQuery();

    if (logger)
    {
        logger->log("execQuery",
                    QString("[%1] %2").arg(BOOL_TO_STRING(success),
                                           query.executedQuery()));
    }

    if (!success)
    {
        if (logger)
        {
            *logger << "\t\t[reason for failing] " << query.lastError().
                    text() << "\n";
        }
        else
        {
            qDebug() << "\t\t[reason for failing] " << query.lastError();
        }
        return -1;
    }

    return query.size();
}

int YerothERPAlertUtils::execQuery(QSqlQuery &query,
                                   YEROTH_ERP_SYSTEM_DAEMON_LOGGER *logger)
{
    //qDebug() << "[YerothERPAlertUtils][execQuery]";

    bool success = query.exec();

    //qDebug() << "\t[" << success << "]" << query.executedQuery();

    if (logger)
    {
        logger->log("execQuery",
                    QString("[%1] %2").arg(BOOL_TO_STRING(success),
                                           query.executedQuery()));
    }

    if (!success)
    {
        if (logger)
        {
            *logger << "\t\t[reason for failing] " << query.lastError().
                    text() << "\n";
        }
        else
        {
            qDebug() << "\t\t[reason for failing] " << query.lastError();
        }
        return -1;
    }

    return query.size();
}


int YerothERPAlertUtils::getNextIdFromTable(const QString &tableName)
{
    //qDebug() << "[YerenUtils::getLastIdFromTable()] : next id from table '" << tableName << "'";
    QString strQuery("SELECT id FROM ");
    strQuery.append(tableName);

    QSqlQuery query(strQuery);
    QSqlRecord rec = query.record();

    if (query.last())
    {
        int lastId = query.value(0).toInt();
        ++lastId;
        //qDebug() << "\t next id 1: " << lastId;
        return lastId;
    }

    return 0;
}

QString YerothERPAlertUtils::get_text(const QVariant &qv)
{
    QString retStr;

    switch (qv.type())
    {
    case QVariant::UInt:
        return QString::number(qv.toUInt());

    case QVariant::Int:
        return QString::number(qv.toInt());

    case QVariant::Double:
        return QString::number(qv.toDouble(), 'f', 2);

    case QVariant::ULongLong:
        return QString::number(qv.toULongLong());

    case QVariant::LongLong:
        return QString::number(qv.toLongLong());

    case QVariant::Char:
        retStr = QString(qv.toChar());
        break;

    case QVariant::String:
        retStr = QString(qv.toString());
        break;

    case QVariant::Bool:
        retStr.append(qv.toBool());
        break;

    case QVariant::Date:
        retStr = DATE_TO_STRING(qv.toDate());
        break;

    case QVariant::Time:
        retStr = TIME_TO_STRING(qv.toTime());
        break;

    default:
        retStr = QString(qv.type());
        break;
    }

    return YerothERPAlertUtils::prepareSqlStr(retStr);
}
