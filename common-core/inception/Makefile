# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/02 21:16:38 by doriani           #+#    #+#              #
#    Updated: 2024/08/03 12:15:11 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DATA_FOLDER = /home/doriani/data

all: up

setup:
	@if ! grep -q "127.0.0.1 doriani.42.fr" /etc/hosts; then \
		echo "127.0.0.1 doriani.42.fr" | sudo tee -a /etc/hosts; \
		echo "127.0.0.1 www.doriani.42.fr" | sudo tee -a /etc/hosts; \
	fi

up: setup build
	@mkdir -p $(DATA_FOLDER)/wordpress
	@mkdir -p $(DATA_FOLDER)/mariadb
	docker-compose -f srcs/docker-compose.yml up -d

down:
	docker-compose -f srcs/docker-compose.yml down

stop:
	docker-compose -f srcs/docker-compose.yml stop

start:
	docker-compose -f srcs/docker-compose.yml start

build:
	docker-compose -f srcs/docker-compose.yml build

clean:
	@docker stop $$(docker ps -qa) || true
	@docker rm $$(docker ps -qa) || true
	@docker rmi -f $$(docker images -qa) || true
	@docker volume rm $$(docker volume ls -q) || true
	@docker network rm $$(docker network ls -q) || true
	@rm -rf $(DATA_FOLDER) || true

re: clean up

prune: clean
	@docker system prune -a --volumes -f