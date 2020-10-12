service mysql start

################
# Autorization #
################
chown -R www-data /var/www/*
chmod -R 755 /var/www/*

#######
# SSL #
#######
openssl req -newkey rsa:4096 -days 365 -nodes -x509 \
            -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=hyeokim/CN=localhost" \
            -keyout localhost.dev.key -out localhost.dev.crt          
mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

##############
# phpmyadmin #
##############
tar -xvf phpMyAdmin-5.0.2.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin/* /var/www/html/phpmyadmin/

#########
# MySQL #
#########
echo "CREATE DATABASE IF NOT EXISTS wordpress;" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;" | mysql -u root --skip-password
echo "update mysql.user set plugin='mysql_native_password' where user='root';" | mysql -u root --skip-password
echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password

#############
# Wordpress #
#############
tar -xvf wordpress-5.5.1.tar.gz
mv wordpress/* /var/www/html/wordpress/

# Remove tar files
rm *.tar.gz

# Run services
service php7.3-fpm start
service nginx start

bash