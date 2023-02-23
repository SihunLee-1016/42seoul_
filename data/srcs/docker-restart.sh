sudo docker-compose -f docker-compose.yml down
sudo docker volume rm $(sudo docker volume ls -q)
sudo docker-compose -f docker-compose.yml up --build
sudo docker exec -it mariadb sh
