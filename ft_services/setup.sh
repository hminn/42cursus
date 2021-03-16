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
echo " =============================="
echo "|    Building Docker Images    |"
echo " =============================="
echo;

docker build -t hyeokim_influxdb srcs/influxdb
docker build -t hyeokim_mysql srcs/mysql
docker build -t hyeokim_telegraf srcs/telegraf
docker build --network host -t hyeokim_nginx srcs/nginx
docker build -t hyeokim_wordpress srcs/wordpress
docker build -t hyeokim_phpmyadmin srcs/phpmyadmin
docker build -t hyeokim_ftps srcs/ftps
docker build -t hyeokim_grafana srcs/grafana


echo;
echo " =================="
echo "|    Deployment    |"
echo " =================="
echo;

kubectl apply -f srcs/influxdb/influxdb.yaml
kubectl apply -f srcs/mysql/mysql.yaml
kubectl apply -f srcs/telegraf/telegraf.yaml
kubectl apply -f srcs/nginx/nginx.yaml
kubectl apply -f srcs/wordpress/wordpress.yaml
kubectl apply -f srcs/phpmyadmin/phpmyadmin.yaml
kubectl apply -f srcs/ftps/ftps.yaml
kubectl apply -f srcs/grafana/grafana.yaml

echo;
echo " ======================="
echo "|    minikube addons    |"
echo " ======================="
echo;

minikube addons enable metrics-server
minikube addons enable dashboard

echo;
echo " ========================"
echo "|    Hyeokim minikube    |"
echo " ========================"
echo;

echo "[Minikube ip] : $(minikube ip)"
echo "[ftps] : user/passwd"
echo "[wordpress, phpmyamin] root/passwd "
echo "[grafana] admin/admin "

echo;
echo " ======================"
echo "|    Open Dashboard    |"
echo " ======================"

minikube dashboard