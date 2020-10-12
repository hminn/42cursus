# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeokim <hyeokim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/12 21:37:16 by hyeokim           #+#    #+#              #
#    Updated: 2020/10/12 21:37:39 by hyeokim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM    debian:buster

LABEL maintainer="hyeokim@student.42seoul.kr"

RUN apt-get update && apt-get install -y \
    nginx \
    mariadb-server \
    php7.3-fpm \
    php7.3-common \
    php7.3-mysql \
    php7.3-mbstring \
    openssl \
    vim


# Copy configuration files
COPY    srcs/default /etc/nginx/sites-available/default
COPY	srcs/config.inc.php /var/www/html/phpmyadmin/config.inc.php
COPY	srcs/wp-config.php /var/www/html/wordpress/wp-config.php

# Copy installation files
COPY	srcs/phpMyAdmin-5.0.2.tar.gz ./
COPY    srcs/wordpress-5.5.1.tar.gz ./

# Copy bash command file
COPY	srcs/init_container.sh ./

EXPOSE 80 443

CMD bash init_container.sh