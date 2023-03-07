NAME = inception

SRC_DIR = ./srcs

DOCKER_COMPOSE_FILE = $(SRC_DIR)/docker-compose.yml

DOCKER_COMPOSE = sudo docker-compose -f $(DOCKER_COMPOSE_FILE)

$(NAME)	:
	sudo mkdir -p ${HOME}/data/wordpress ${HOME}/data/mariadb 
	
all : $(NAME)
# install docker

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
.PHONY	:	clear
clear:
	sudo docker-compose -f docker-compose.yml down
	sudo docker volume rm $(sudo docker volume ls -q)
