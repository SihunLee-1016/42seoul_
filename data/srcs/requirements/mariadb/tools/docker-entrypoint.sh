#!/bin/sh

# check setup file is set
cat .setup 2> /dev/null
# if init is needed
if [ $? -ne 0 ]; then
	echo "INITIAL SET MARIADB"
	# set init to mysql
	/usr/bin/mysqld_safe --datadir=/var/lib/mysql &
	  # Change Config to Use Not Only Socket But Also Network
	sed -i "s/skip-networking/# skip-networking/g" /etc/my.cnf.d/mariadb-server.cnf
	# Change Config to Allow Every Host
	sed -i "s/.*bind-address\s*=.*/bind-address=0.0.0.0\nport=3306/g" /etc/my.cnf.d/mariadb-server.cnf
	# wait for run sql if not use this code, it will be get socker error
  	if ! mysqladmin --wait=30 ping; then
   		printf "MariaDB Daemon Unreachable\n"
    	exit 1
  	fi
	# inject init sql to mariadb
	eval "echo \"$(cat /data/application/init.sql)\"" | mariadb
	pkill mariadb
	touch .setup
fi
/usr/bin/mysqld_safe --datadir=/var/lib/mysql
