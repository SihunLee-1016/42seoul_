FROM alpine:3.16.3

# install nginx
RUN apk update && \
	apk add nginx && \
	apk add dumb-init && \
	apk add nginx openssl && \
	chmod +x /usr/bin/dumb-init && \
	mkdir -p /etc/nginx/ssl && \
	openssl	req -new -newkey rsa:4096 -x509 -sha256 -days 365 \
			-nodes -out /etc/nginx/ssl/nginx-ssl.crt \
			-keyout /etc/nginx/ssl/nginx-ssl.key \
			-subj "/C=KR/ST=Seoul/L=Gangnam-gu/O=42/OU=42Seoul/CN=chpark.42.fr"

# copy nginx config file
COPY ./conf/default.conf "/etc/nginx/http.d/default.conf"

# will be use port:443
EXPOSE 443

ENTRYPOINT  ["/usr/bin/dumb-init", "--"]

CMD ["nginx", "-g", "daemon off;"]
