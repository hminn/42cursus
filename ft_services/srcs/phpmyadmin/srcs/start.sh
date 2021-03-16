
#!/bin/sh

tar -xvf /phpMyAdmin-5.0.2.tar.gz > /dev/null
rm -rf /phpMyAdmin-5.0.2.tar.gz
mv /phpMyAdmin-5.0.2 /var/www/pma
mkdir /var/www/pma/tmp
chmod -R 777 /var/www/pma/tmp

php-fpm7 && nginx -g "daemon off;"