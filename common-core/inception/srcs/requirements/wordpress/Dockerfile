FROM debian:bullseye

RUN apt update && apt upgrade -y
RUN apt install php \
                php-fpm \
                php-mysql \
                mariadb-client \
                php-json \
                php-curl \
                php-xml \
                php-phar \
                php-intl \
                php-dom \
                php-xmlreader \
                php-ctype \
                php-mbstring \
                php-gd \
                curl \
    -y

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

WORKDIR /var/www/inception

RUN wp core download --allow-root

RUN chown -R root:root /var/www/inception

COPY ./tools/wordpress_script.sh /wordpress_script.sh
COPY ./conf/inception.conf /etc/php/7.4/fpm/pool.d/inception.conf

ENTRYPOINT ["bash", "/wordpress_script.sh"]

