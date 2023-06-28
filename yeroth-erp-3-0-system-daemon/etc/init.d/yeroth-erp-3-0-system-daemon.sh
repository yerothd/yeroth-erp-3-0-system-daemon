#! /bin/sh
# /etc/init.d/yeroth-erp-3-0-system-daemon.sh
#

### BEGIN INIT INFO
# Provides: yeroth-erp-3-0-system-daemon.sh
# Required-Start:    $local_fs $syslog $remote_fs networking mysql
# Required-Stop:     $local_fs $syslog $remote_fs
# Default-Start:     2 3 4 5
# Default-Stop:      0 1 6
# Short-Description: Enable alert system of ''Yeroth-erp-3.0''
### END INIT INFO

export DISPLAY=:0.0

killYerothERPAlertDaemon()
{
		pgrep -a yeroth-erp-3-0- \
				| grep "${YEROTH_ERP_3_0_SYSTEM_DAEMON_HOME_FOLDER}"/bin/yeroth-erp-3-0-system-daemon \
				| awk '//{print $1}' | xargs kill -9 > /dev/null 2>&1
}

[ -f /etc/environment ] && . /etc/environment

# Carry out specific functions when asked to by the system
case "$1" in
  start)
    echo "Starting script yeroth-erp-3-0-system-daemon.sh"
    xvfb-run --auto-servernum nice -n -12 "${YEROTH_ERP_3_0_SYSTEM_DAEMON_HOME_FOLDER}"/bin/yeroth-erp-3-0-system-daemon > /dev/null 2>&1 
    ;;
  stop)
    echo "Stopping script yeroth-erp-3-0-system-daemon.sh"
    killYerothERPAlertDaemon
    ;;
  restart)
    echo "Restarting script yeroth-erp-3-0-system-daemon.sh"
    killYerothERPAlertDaemon
    xvfb-run --auto-servernum nice -n -12 "${YEROTH_ERP_3_0_SYSTEM_DAEMON_HOME_FOLDER}"/bin/yeroth-erp-3-0-system-daemon > /dev/null 2>&1
    ;;
  force-reload)
    echo "Force reload script yeroth-erp-3-0-system-daemon.sh"
    killYerothERPAlertDaemon
    xvfb-run --auto-servernum nice -n -12 "${YEROTH_ERP_3_0_SYSTEM_DAEMON_HOME_FOLDER}"/bin/yeroth-erp-3-0-system-daemon > /dev/null 2>&1
    ;;
  status)
    echo "Check status of script yeroth-erp-3-0-system-daemon.sh"
    pgrep -a yeroth-erp-3-0- | grep "${YEROTH_ERP_3_0_SYSTEM_DAEMON_HOME_FOLDER}"/bin/yeroth-erp-3-0-system-daemon 
    ;;
  *)
    echo "Usage: /etc/init.d/yeroth-erp-3-0-system-daemon.sh {start|stop|restart|force-reload|status}"
    exit 1
    ;;
esac

exit 0
