#!/bin/bash

rm -f yeroth-erp-3-0-system-daemon.deb

cp bin/yeroth-erp-3-0-system-daemon yeroth-erp-3-0-system-daemon/opt/yeroth-erp-3-0-system-daemon/bin

chmod go+rw yeroth-erp-3-0-system-daemon/opt/yeroth-erp-3-0-system-daemon/yeroth-erp-3-0-system-daemon.log

chmod 755 yeroth-erp-3-0-system-daemon/DEBIAN/postinst

dpkg-deb --build yeroth-erp-3-0-system-daemon
