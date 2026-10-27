#!/bin/bash

docker image rm mariadb:42 nginx:42 wordpress:42
docker volume rm mariadb wordpress
sudo rm -rf "/home/doriani/Desktop/inception/srcs/wordpress" "/home/doriani/Desktop/inception/srcs/mariadb"
docker system prune
sudo chmod -R a+w /etc/hosts
if sudo grep -q "127.0.0.1 doriani.42.fr" /etc/hosts; then
  sudo sed -i '/doriani/d' /etc/hosts
  echo "setup.sh: hosts file cleaned"
else
  echo "setup.sh: hosts file already cleaned"
fi
sudo chmod -R a-w /etc/hosts
