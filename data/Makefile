NAME = inception

SRC_DIR = ./srcs

DOCKER_COMPOSE_FILE = $(SRC_DIR)/docker-compose.yml

DOCKER_COMPOSE = sudo docker-compose -f $(DOCKER_COMPOSE_FILE)

$(NAME)	:
	sudo mkdir -p ${HOME}/data/wordpress ${HOME}/data/mariadb 
	
all : $(NAME)
# install docker
install:
	@echo "INSTALL DOCKER"
	sudo chmod 777 /etc/resolv.conf 
	echo "search 8.8.4.4\nnameserver 8.8.8.8" > /etc/resolv.conf 
	sudo curl -4 -fsSL https://get.docker.com -o get-docker.sh
	sudo sh get-docker.sh
	@echo "INSTALL DOCKER-COMPOSE"
	sudo curl -4 -SL "https://github.com/docker/compose/releases/download/v2.15.1/docker-compose-$(shell uname -s)-$(shell uname -m)" -o /usr/local/bin/docker-compose
	sudo chmod +x /usr/local/bin/docker-compose
	sudo docker-compose --version
	sudo chmod 777 /etc/hosts
	echo "127.0.0.1 chpark.42.fr" >> /etc/hosts

$(NAME) : all

.PHONY	:	re
re: fclean all up
	
.PHONY	:	clean
clean:
	sudo docker-compose -f srcs/docker-compose.yml down -v --rmi all --remove-orphans

.PHONY	:	fclean
fclean: clean
	sudo rm -rf ${HOME}/data
	sudo docker system prune --volumes --all --force
	sudo docker network prune --force
	sudo docker volume prune --force

.PHONY	:	up
up	:
	$(DOCKER_COMPOSE) up -d
.PHONY	:	down
down :
	$(DOCKER_COMPOSE) down
.PHONY	:	stop
stop :
	$(DOCKER_COMPOSE) stop
.PHONY	:	start
start :
	$(DOCKER_COMPOSE) start
.PHONY	:	restart
restart :
	$(DOCKER_COMPOSE) restart
.PHONY	:	clear
clear:
	sudo docker-compose -f docker-compose.yml down
	sudo docker volume rm $(sudo docker volume ls -q)
