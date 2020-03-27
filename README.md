# DOCKER SHEET
## Connect (putty or ssh)
user: docker
pwd:tcuser
ifconfig eth1

### putty
paste : ctrl + shift + V

# set VM azerty
su docker
tce-load -wi kmaps
sudo loadkmap < /usr/share/kmap/azerty/fr-latin9.kmap

# SSH : ssh docker@192.168.99.103

# Tutorial
install nginx server: docker run -d -p 8080:80 nginx
open webpage: http://192.168.99.103:8080/

# Get docker contner id
in Linux: sudo docker ps -aqf "name=containername"
in Windows: docker ps -aqf "name=containername"

# Operational bash cmd: docker exec -ti 2769d51daeb2 bash

# Edit nginx webpage:
cd /usr/share/nginx/html

get nano:
apt-get update
apt-get install apt-file
apt-file update
apt-get install nano

# Stop contener: docker stop 2769d51daeb2 

# Remove docker: docker rm 2769d51daeb2 

# Pull contner: docker pull hello-world

# List of running contners : docker ps

# List of images : docker images -a

# Clean and remove all contners : docker system prune
