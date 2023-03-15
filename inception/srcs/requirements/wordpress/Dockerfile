FROM debian:buster
ARG MARIADB_DB_NAME
ARG MARIADB_USER_NAME
ARG MARIADB_USER_PASSWD
ENV MARIADB_DB_NAME=$MARIADB_DB_NAME
ENV MARIADB_USER_NAME=$MARIADB_USER_NAME
ENV MARIADB_USER_PASSWD=$MARIADB_USER_PASSWD
RUN apt-get update && apt-get install -y php-fpm php-mysql wget
RUN wget http://wordpress.org/latest.tar.gz -P /var/www/html 
RUN tar -xzvf /var/www/html/latest.tar.gz -C /var/www/html/ && cp -r /var/www/html/wordpress/* /var/www/html && rm -rf /var/www/html/wordpress /var/www/html/latest.tar.gz index.nginx-debian.html
COPY ./conf/wp-config.php /var/www/html
COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d
RUN mkdir /run/php
RUN apt-get install -y net-tools
CMD ["php-fpm7.3", "-F"]