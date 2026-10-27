FROM debian:bullseye

RUN apt-get update && apt-get upgrade -y
RUN apt-get install openssl nginx -y

RUN mkdir -p /etc/nginx/ssl
RUN openssl req -x509 -nodes \
        -keyout /etc/nginx/ssl/inception.key \
        -out /etc/nginx/ssl/inception.crt \
        -subj "/C=IT/ST=Lazio/L=Rome/O=42/OU=42/CN=doriani.42.fr/UID=doriani"
RUN mkdir -p /var/log/nginx/inception
RUN mkdir -p /var/run/nginx /var/www/inception
COPY ./conf/inception /etc/nginx/sites-available/inception
RUN ln -s /etc/nginx/sites-available/inception /etc/nginx/sites-enabled/inception
RUN chmod 755 /var/www/inception
RUN chown -R www-data:www-data /var/www/inception


RUN unset MARIADB_USER_PASSWORD MARIADB_ROOT_PASSWORD WP_ADMIN_PASSWORD WP_USER_PASSWORD

ENTRYPOINT ["nginx", "-g", "daemon off;"]

