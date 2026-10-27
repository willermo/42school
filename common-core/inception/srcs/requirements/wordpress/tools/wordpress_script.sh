sleep 20

mkdir -p /run/php

if [ ! -f "wp-config.php" ]; then
	wp config create 	--dbhost=mariadb:3306 --dbname=$MARIADB_DATABASE \
						--dbuser=$MARIADB_USER --dbpass=$MARIADB_USER_PASSWORD \
						--path="/var/www/inception" --allow-root

	wp core install	--url=$WP_URL --title=$WP_TITLE \
					--admin_user=$WP_ADMIN --admin_password=$WP_ADMIN_PASSWORD \
					--admin_email="$WP_ADMIN_EMAIL" --allow-root

	wp user create	$WP_USER "$WP_USER_EMAIL" --user_pass=$WP_USER_PASSWORD \
					--role=$WP_USER_ROLE --porcelain --allow-root
	
	wp theme install astra --activate --allow-root
fi

/usr/sbin/php-fpm7.4 -F
