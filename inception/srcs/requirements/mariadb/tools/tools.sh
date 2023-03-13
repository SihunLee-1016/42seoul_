#!/bin/bash
install -m 755 -o mysql -g root -d /var/run/mysqld
if [ ! -d "/var/lib/mysql/mysql" ]; then
    mysql_install_db --datadir=/var/lib/mysql --auth-root-authentication-method=normal --skip-test-db
    mysqld --user=root &
    MARIADB_PID=$!
    sleep 3
    mysql -e "DELETE FROM mysql.user WHERE host!='localhost';"
    mysql -e "CREATE DATABASE ${MARIADB_DB_NAME};"
    mysql -e "CREATE USER ${MARIADB_USER_NAME}@'%' IDENTIFIED BY '${MARIADB_USER_PASSWD}';"
    mysql -e "GRANT ALL PRIVILEGES ON ${MARIADB_DB_NAME}.* TO ${MARIADB_USER_NAME}@'%';"
    mysql -e "UPDATE mysql.user SET password=PASSWORD('${MARIADB_ROOT_PASSWD}') WHERE user='root';"
    kill "$MARIADB_PID"
    wait "$MARIADB_PID"
fi
exec mysqld --user=root
