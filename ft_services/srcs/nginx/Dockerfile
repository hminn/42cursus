FROM        alpine:3.12

RUN         apk --update --no-cache add nginx
RUN         mkdir -p /run/nginx; mkdir -p /var/www
RUN         echo "root:ftservice" | chpasswd

RUN         apk --update --no-cache add openssh-server openssl
RUN         openssl req -x509 -nodes -days 365 -newkey rsa:2048 -subj "/CN=nginxsvc/O=nginxsvc" -keyout /etc/ssl/private/nginx.key -out /etc/ssl/certs/nginx.crt

COPY	    /srcs/default.conf /etc/nginx/conf.d/
COPY	    /srcs/index.html /var/www/
COPY	    /srcs/start.sh /

EXPOSE      80 443
ENTRYPOINT  ["sh", "start.sh"]