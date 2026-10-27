#!/bin/bash

mkdir -p "/home/doriani/Desktop/inception/srcs/wordpress" "/home/doriani/Desktop/inception/srcs/mariadb"
if sudo grep -q "127.0.0.1 doriani.42.fr" /etc/hosts; then
  echo "setup.sh: hosts file already configured"
else
  sudo echo -e "127.0.0.1 doriani.42.fr" >> /etc/hosts
  echo -e "127.0.0.1 www.doriani.42.fr" >> /etc/hosts
  
  echo "setup.sh: hosts file configured"
fi
