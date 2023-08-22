// 소켓 관련 헤더 파일들
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

// 메시지 버퍼 크기 설정
#define BUF_SIZE 42 * 4092

typedef struct client {
	int id;               // 클라이언트 ID
	char msg[110000];     // 클라이언트 메시지를 저장할 버퍼
}	t_client;

t_client client_arr[1024]; // 최대 1024개의 클라이언트를 저장할 수 있는 배열

int max, next_id;
fd_set fd_active, fd_read, fd_write;

char read_buf[BUF_SIZE], write_buf[BUF_SIZE];

int error_exit(char *str) {
	write(2, str, strlen(str));
	exit(1);
}

void send_all(int es) {
	for (int i = 0; i <= max; i++) {
		if(FD_ISSET(i, &fd_write) && i != es)
            send(i, write_buf, strlen(write_buf), 0);
	}
}

// 메인 함수
int main(int argc, char **argv) {

	if (argc != 2)
		error_exit("Wrong number of arguments\n");

	int port = atoi(argv[1]);
	bzero(&client_arr, sizeof(client_arr));
	FD_ZERO(&fd_active);

	int s_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (s_socket < 0)
		error_exit("Fatal error\n");
	max = s_socket;
	FD_SET(s_socket, &fd_active);

	struct sockaddr_in servaddr;
	socklen_t addr_len = sizeof(servaddr);
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(port);

	if (bind(s_socket, (const struct sockaddr *)&servaddr, addr_len) < 0)
		error_exit("Fatal error\n");
	if (listen(s_socket, 128) < 0)
		error_exit("Fatal error\n");

	while (1) {
		fd_read = fd_active;
		fd_write = fd_active;

		if (select(max + 1, &fd_read, &fd_write, NULL, NULL) < 0)
			continue ;

		for (int s = 0; s <= max; s++) {
			if (FD_ISSET(s, &fd_read) && s == s_socket) {
				int c_socket = accept(s_socket, (struct sockaddr *)&servaddr, &addr_len);
				if (c_socket < 0)
					continue ;
				max = c_socket > max ? c_socket : max;
				client_arr[c_socket].id = next_id++;
				FD_SET(c_socket, &fd_active);
				sprintf(write_buf, "server: client %d just arrived\n", client_arr[c_socket].id);
				send_all(c_socket);
            break ;
			}
			if (FD_ISSET(s, &fd_read) && s != s_socket) {
				int res = recv(s, read_buf, BUF_SIZE, 0);
				if (res <= 0) {
					sprintf(write_buf, "server: client %d just left\n", client_arr[s].id);
					send_all(s);
					FD_CLR(s, &fd_active);
					close(s);
                break ;
				} 
                else {
					for (int i = 0, j = strlen(client_arr[s].msg); i < res; i++, j++) {
                        client_arr[s].msg[j] = read_buf[i];
                        if (client_arr[s].msg[j] == '\n') {
                            client_arr[s].msg[j] = '\0';
                            sprintf(write_buf, "client %d: %s\n", client_arr[s].id, client_arr[s].msg);
                            send_all(s);
							bzero(&client_arr[s].msg, strlen(client_arr[s].msg));
                            j = -1;
                        }
					}
            break;
				}
			}
		}
	}
}
