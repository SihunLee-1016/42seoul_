NAME = inception

SRC_DIR = ./srcs

DOCKER_COMPOSE_FILE = $(SRC_DIR)/docker-compose.yml

DOCKER_COMPOSE = docker compose -f $(DOCKER_COMPOSE_FILE)

$(NAME)	:
	sudo chmod 666 /var/run/docker.sock
	mkdir -p ${HOME}/data/wordpress ${HOME}/data/mariadb 

all : $(NAME)

.PHONY	:	re
re: fclean all up
	
.PHONY	:	fclean
fclean: down
	sudo rm -rf ${HOME}/data
	docker rmi $$(docker images -qa)
	docker volume rm $$(docker volume ls -q)
	docker network rm $$(docker network ls -q) 2>/dev/nul
.PHONY	:	build
build	:
	$(DOCKER_COMPOSE) build
.PHONY	:	up
up	:
	$(DOCKER_COMPOSE) up -d
.PHONY	:	down
down :
	$(DOCKER_COMPOSE) down
.PHONY	:	clean
clean:
	docker volume rm $$(docker volume ls -q)
	docker rmi $$(docker images -qa)

