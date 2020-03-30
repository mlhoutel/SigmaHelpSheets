# :whale: DOCKER SHEET
[Return to the menu](../README.md)
# Fast Help
Instruction | Command
------------ | -------------
**Pull image** | ```docker pull hello-world```
**List of containers images** | ```docker images -a```
**Create container** | ```docker create --name prismatic ubuntu```
**Run container** | ```docker run hello-world```
**Get container id (Linux)** | ```sudo docker ps -aqf "name=containername"```
**Get container id (Windows)** | ```docker ps -aqf "name=containername"```
**Run a saved image** | ```docker run -it -p 8091:8091 prismatic```
**Operational bash cmd** | ```docker exec -ti 2769d51daeb2 bash```
**Stop container** | ```docker stop 2769d51daeb2``` 
**Remove container** | ```docker rm 2769d51daeb2 ```
**List of running container** | ```docker ps```
**Clean and remove all container** | ```docker system prune```

## Docker Setup
https://hub.docker.com/

https://www.docker.com/

OS | Installation Link
------------ | -------------
Linux |  ```sudo apt-get install docker-ce docker-ce-cli containerd.io```
Mac | https://hub.docker.com/editions/community/docker-ce-desktop-mac/
Windows Pro | https://hub.docker.com/editions/community/docker-ce-desktop-windows/
Windows Family | https://github.com/docker/toolbox/releases

## Connect to the VM
```
user: docker
pwd: tcuser
```
Get the VM ip with 
```
ifconfig eth1
```
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
### Install nginx server
```
install nginx server: docker run -d -p 8080:80 nginx
open webpage: http://192.168.99.103:8080/
```
### Edit nginx webpage:
```
cd /usr/share/nginx/html
```
Get Nano:
```
apt-get update
apt-get install apt-file
apt-file update
apt-get install nano
```

