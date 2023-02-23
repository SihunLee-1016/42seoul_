#!/bin/sh

# sleep to wait forrun mariadb
sleep 10
if ! mysqladmin -h mariadb -u $MARIADB_USER --password=$MARIADB_PWD --wait=60 ping > /dev/null; then
    printf "MariaDB Daemon Unreachable\n"
    exit 1
fi
# setup..
if [ ! -f '/.wp-issetup' ]; then
	wp core install --url="$WP_URL" \
		--title="$WP_TITLE" \
		--admin_user="$WP_ADMIN_USER_NAME" \
		--admin_password="$WP_ADMIN_USER_PASSWORD" \
		--admin_email="$WP_ADMIN_USER_EMAIL" \
		--skip-email \
		--path=/var/www/html/wp-content
	wp user create $WP_USER_NAME $WP_USER_EMAIL --role=author --user_pass=$WP_USER_PASSWORD --path=/var/www/html/wp-content
	echo "env[MYSQL_HOST] = \$MYSQL_HOST" >> /etc/php8/php-fpm.d/www.conf
	echo "env[MYSQL_DATABASE] = \$MYSQL_DATABASE" >> /etc/php8/php-fpm.d/www.conf
	echo "env[MYSQL_USER] = \$MYSQL_USER" >> /etc/php8/php-fpm.d/www.conf
	echo "env[MYSQL_PASSWORD] = \$MYSQL_PASSWORD" >> /etc/php8/php-fpm.d/www.conf
	echo "listen = 9000" >> /etc/php8/php-fpm.d/www.conf
	touch /.wp-issetup
fi

# run
php-fpm8 --nodaemonize
