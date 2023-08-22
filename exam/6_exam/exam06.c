// 소켓 관련 헤더 파일들
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

// 메시지 버퍼 크기 설정
#define BUF_SIZE 42 * 4092

// 클라이언트 구조체 정의
typedef struct client {
	int id;               // 클라이언트 ID
	char msg[110000];     // 클라이언트 메시지를 저장할 버퍼
}	t_client;

// 전역 변수 및 전역 배열 선언
t_client client_arr[1024]; // 최대 1024개의 클라이언트를 저장할 수 있는 배열

int max, next_id;
// fd_set은 파일 디스크립터 집합을 저장할 구조체입니다.
// 리눅스에서는 소켓을 하나의 파일로 처리하기 때문에 파일 디스크립터로 소켓들을 관리합니다.
// fd_set 구조체를 사용하여 각각의 소켓이 읽기, 쓰기, 에러를 처리할 수 있는지 확인합니다.
fd_set fd_active, fd_read, fd_write;

// 오류 시 메시지를 출력하고 exit하는 함수
int error_exit(char *str) {
	write(2, str, strlen(str));
	exit(1);
}

// 읽기 및 쓰기를 위한 버퍼
char read_buf[BUF_SIZE], write_buf[BUF_SIZE];

// 클라이언트에게 메시지 전송 함수
void send_all(int es) {
    // 모든 클라이언트에게 메시지 전송. es는 제외합니다.
	for (int i = 0; i <= max; i++) {
		if(FD_ISSET(i, &fd_write) && i != es)
            send(i, write_buf, strlen(write_buf), 0);
	}
}

// 메인 함수
int main(int argc, char **argv) {
    // 인자가 2개가 아닌 경우 오류 출력
	if (argc != 2)
		error_exit("Wrong number of arguments\n");

    // 포트 번호를 문자열에서 정수로 변환
	int port = atoi(argv[1]);

    // 클라이언트 배열 초기화
	bzero(&client_arr, sizeof(client_arr));

    // fd_set 초기화
	FD_ZERO(&fd_active);

    // 서버 소켓 생성
	int server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket < 0)
		error_exit("Fatal error\n");

    // max와 next_id는 전역 변수입니다. max에는 현재 가장 큰 소켓 파일 디스크립터의 값을 저장합니다. (처음엔 서버 소켓이 됩니다.)
	max = server_socket;
    // fd_active에 서버 소켓 추가
	FD_SET(server_socket, &fd_active);

    // 서버 주소 정보 구조체 초기화
	struct sockaddr_in servaddr;
	socklen_t addr_len = sizeof(servaddr);
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(port);

    // 서버 소켓 바인딩 및 오류 확인
	// if (bind(server_socket, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
	if (bind(server_socket, (const struct sockaddr *)&servaddr, addr_len) < 0)
		error_exit("Fatal error\n");
    // 서버 소켓이 연결을 수신 대기
	if (listen(server_socket, 128) < 0)
		error_exit("Fatal error\n");

    // 계속해서 클라이언트 연결을 대기 및 처리
	while (1) {
		fd_read = fd_active;
		fd_write = fd_active;

        // select를 사용하여 읽기, 쓰기 가능한 소켓 확인
		if (select(max + 1, &fd_read, &fd_write, NULL, NULL) < 0)
			continue ;

        // 각 파일 디스크립터에 대하여 수행할 작업 확인
		for (int s = 0; s <= max; s++) {
            // 새로운 클라이언트 연결 수락
			if (FD_ISSET(s, &fd_read) && s == server_socket) {
				int client_socket = accept(server_socket, (struct sockaddr *)&servaddr, &addr_len);
				if (client_socket < 0)
					continue ;
                // 새로 접속한 클라이언트의 소켓과 연결 정보를 저장. 전체 클라이언트 배열에 저장
				max = client_socket > max ? client_socket : max;
				client_arr[client_socket].id = next_id++;
				FD_SET(client_socket, &fd_active);
                //클라이언트가 연결됨을 알리는 메세지 생성. 이를 다른 클라이언트에 전송
				sprintf(write_buf, "server: client %d just arrived\n", client_arr[client_socket].id);
				send_all(client_socket);
				break ;
			}

            // @기존@ 클라이언트가 보낸 메시지 처리
			if (FD_ISSET(s, &fd_read) && s != server_socket) {
				int res = recv(s, read_buf, BUF_SIZE, 0);
                // 받은 메시지가 없는 경우 클라이언트 연결 종료 처리
				if (res <= 0) {
					sprintf(write_buf, "server: client %d just left\n", client_arr[s].id);
					send_all(s);
					FD_CLR(s, &fd_active);
					close(s);
					break ;
				} else {
                    // 받은 메시지를 다른 클라이언트에게 전송
                    //개행을 만난 경우 메세지의 끝으로 인식하고, 이를 전송할 메세지로 생성하고 다른 클라이언트에게 전달.
					for (int i = 0, j = strlen(client_arr[s].msg); i < res; i++, j++) {
                        client_arr[s].msg[j] = read_buf[i];
                        if (client_arr[s].msg[j] == '\n') {
                            client_arr[s].msg[j] = '\0';
                            sprintf(write_buf, "client %d: %s\n", client_arr[s].id, client_arr[s].msg);
                            send_all(s);
                            //그리고 버퍼 초기화.   
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
