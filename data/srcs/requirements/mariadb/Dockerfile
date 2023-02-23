# second latest mariadb dokcer image
FROM	alpine:3.16.3
# add user and group
RUN apk update && \
	apk add curl mariadb mariadb-client net-tools&& \
	mkdir -p /run/mysqld /var/lib/mysql && \
    chown -R mysql:mysql /var/lib/mysql /run/mysqld && \
	apk add  dumb-init && \
	mariadb-install-db --datadir=/var/lib/mysql --auth-root-authentication-method=normal && \
	chmod +x /usr/bin/dumb-init

COPY ./conf/init.sql /data/application/init.sql
COPY ./conf/my.cnf /etc/mysql/my.cnf
COPY ./tools/docker-entrypoint.sh /usr/bin/docker-entrypoint.sh
RUN chmod +x /usr/bin/docker-entrypoint.sh

EXPOSE 3306

ENTRYPOINT  ["/usr/bin/dumb-init", "--"]

CMD ["sh", "-c","/usr/bin/docker-entrypoint.sh"]