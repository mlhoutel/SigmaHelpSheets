# DOCKER SHEET
## Docker Setup
[Docker Hub](https://hub.docker.com/)
[Docker Hub](https://www.docker.com//)



## Connect to the VM
```
user: docker
pwd:tcuser
```

Get the VM ip with ```ifconfig eth1```

Set the azert keyboard
```
su docker
tce-load -wi kmaps
sudo loadkmap < /usr/share/kmap/azerty/fr-latin9.kmap
```

### Use Putty
```
Session\Window\Selection\Action = Compromise
paste : ctrl + shift + V
```
### Use SSH
```
ssh docker@192.168.99.103
```
## Tutorial
```
install nginx server: docker run -d -p 8080:80 nginx
open webpage: http://192.168.99.103:8080/
```

### Get docker contner id
in Linux: ```sudo docker ps -aqf "name=containername"```
in Windows: ```docker ps -aqf "name=containername"```

### Operational bash cmd: 
```
docker exec -ti 2769d51daeb2 bash
```

### Edit nginx webpage:
```cd /usr/share/nginx/html```

Get Nano:
```
apt-get update
apt-get install apt-file
apt-file update
apt-get install nano
```

# Helps
Stop contener: ```docker stop 2769d51daeb2 ```
Remove docker: ```docker rm 2769d51daeb2 ```
Pull contner: ```docker pull hello-world```
List of running contners : ```docker ps```
List of images : ```docker images -a```
Clean and remove all contners : ```docker system prune```
