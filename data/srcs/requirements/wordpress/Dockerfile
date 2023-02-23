FROM	alpine:3.16.3

# image layer 1 : install wordpress envrionments
RUN		apk		update && apk upgrade && \
		apk		add php8 php8-phar php8-json php8-curl php8-fpm php8-mysqli php8-iconv \
					mariadb-client curl dumb-init && \
		chmod +x /usr/bin/dumb-init && \
		mkdir	-p /run/mysqld
		
# image layer 2 : install wordpress
RUN		mkdir	-p /var/www/html/wp-content && \
        curl	-s -L https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar --output /usr/bin/wp && \
        chmod	+x /usr/bin/wp && \
        wp		core download --version=5.8.1 --path=/var/www/html/wp-content && \
		curl	-O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
		mv		wp-cli.phar /usr/bin && \
		chmod	+x /usr/bin/wp-cli.phar && \
		ln		-sf /usr/bin/wp-cli.phar /usr/bin/wp-cli

# image layer 3 : copy entrypoint shell script
COPY	./tools/docker-entrypoint.sh /docker-entrypoint.sh
# image layer 4 : copy config file
COPY	./conf/wp-config.php /var/www/html/wp-content/wp-config.php
RUN		chmod	+x /docker-entrypoint.sh


ENTRYPOINT  [ "/usr/bin/dumb-init", "--" ]
CMD         [ "sh", "-c", "/docker-entrypoint.sh" ]
