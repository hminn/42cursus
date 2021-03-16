echo;
echo " ========================"
echo "|    Setting minikube    |"
echo " ========================"
echo;

minikube delete
minikube start --driver=docker
eval $(minikube docker-env)

echo;
echo " ====================="
echo "|    MetalLB Setup    |"
echo " ====================="
echo;

minikube addons enable metallb
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"
kubectl apply -f srcs/metallb/config.yaml

echo;
echo " ==================="
echo "|    Nginx Setup    |"
echo " ==================="
echo;

docker build --network host -t hyeokim_nginx srcs/nginx
kubectl apply -f srcs/nginx/nginx.yaml

echo;
echo " =================="
echo "|    FTPS Setup    |"
echo " =================="
echo;

docker build -t hyeokim_ftps srcs/ftps
kubectl apply -f srcs/ftps/ftps.yaml

echo;
echo " ==================="
echo "|    MySQL Setup    |"
echo " ==================="
echo;

docker build -t hyeokim_mysql srcs/mysql
kubectl apply -f srcs/mysql/mysql.yaml

echo;
echo " ======================="
echo "|    Wordpress Setup    |"
echo " ======================="
echo;

docker build -t hyeokim_wordpress srcs/wordpress
kubectl apply -f srcs/wordpress/wordpress.yaml

echo;
echo " ========================"
echo "|    Phpmyadmin Setup    |"
echo " ========================"
echo;

docker build -t hyeokim_phpmyadmin srcs/phpmyadmin
kubectl apply -f srcs/phpmyadmin/phpmyadmin.yaml

echo;
echo " ======================"
echo "|    influxDB Setup    |"
echo " ======================"
echo;

docker build -t hyeokim_influxdb srcs/influxdb
kubectl apply -f srcs/influxdb/influxdb.yaml

echo;
echo " ======================"
echo "|    telegraf Setup    |"
echo " ======================"
echo;

docker build -t hyeokim_telegraf srcs/telegraf
kubectl apply -f srcs/telegraf/telegraf.yaml

echo;
echo " ====================="
echo "|    grafana Setup    |"
echo " ====================="
echo;

docker build -t hyeokim_grafana srcs/grafana
kubectl apply -f srcs/grafana/grafana.yaml

echo;
echo " ======================="
echo "|    minikube addons    |"
echo " ======================="
echo;
minikube addons enable metrics-server
minikube addons enable dashboard

echo;
echo " ======================"
echo "|    Open Dashboard    |"
echo " ======================"

minikube dashboard