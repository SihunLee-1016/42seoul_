FROM debian:buster
ARG DOMAIN_NAME
ARG NGINX_CONF
ARG COUNTRY_NAME
ARG STATE_NAME
ARG LOCALITY_NAME
ARG ORGANIZATION_NAME
ARG COMMON_NAME
ENV DOMAIN_NAME=$DOMAIN_NAME
ENV NGINX_CONF=$NGINX_CONF
ENV COUNTRY_NAME=$COUNTRY_NAME
ENV STATE_NAME=$STATE_NAME
ENV LOCALITY_NAME=$LOCALITY_NAME
ENV ORGANIZATION_NAME=$ORGANIZATION_NAME
ENV COMMON_NAME=$COMMON_NAME
RUN apt-get update && apt-get install -y nginx && apt-get install -y openssl && apt-get install -y gettext
COPY ./conf/nginx.template /etc/nginx
COPY ./tools/* /
RUN chmod +x /tools.sh && ./tools.sh
RUN apt-get install -y net-tools
CMD ["nginx", "-g", "daemon off;"]
EXPOSE 443