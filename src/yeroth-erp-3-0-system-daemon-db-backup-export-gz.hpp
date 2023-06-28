/*
 * yeroth-erp-3-0-system-daemon-db-backup-export-gz.hpp
 *
 *      Author: Dr.-Ing. (ABD) Xavier Noumbissi Noundou
 */

#ifndef YEROTH_ERP_3_0_SYSTEM_DAEMON_DB_BACKUP_EXPORT_GZ_HPP_
#define YEROTH_ERP_3_0_SYSTEM_DAEMON_DB_BACKUP_EXPORT_GZ_HPP_


#include "src/include/yeroth-erp-3-0-system-daemon-abstract-entity.hpp"


class YEROTH_ERP_SYSTEM_DAEMON_DB_BACKUP_EXPORT_GZ:public
    YEROTH_ERP_SYSTEM_DAEMON_ABSTRACT_ENTITY
{
Q_OBJECT public:
    YEROTH_ERP_SYSTEM_DAEMON_DB_BACKUP_EXPORT_GZ();

    inline ~ YEROTH_ERP_SYSTEM_DAEMON_DB_BACKUP_EXPORT_GZ()
    {
    }

public slots:
    void do_backups();

protected:

    QString _YEROTH_ERP_3_0_BINARY_FULL_PATH_FOR_BACKUP_RESTORE;

    QString _YEROTH_ERP_3_0_SQL_BACKUP_DIRECTORY;
};


#endif /* YEROTH_ERP_3_0_SYSTEM_DAEMON_DB_BACKUP_EXPORT_GZ_HPP_ */
