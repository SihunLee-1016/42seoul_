#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUF_SIZE 42 * 4092

typedef struct client{
    int id;
    char msg[110000];
} t_client;

t_client cli_arr[1024];

int max, next_id;

fd_set fd_active, fd_read, fd_write;

char write_buf[BUF_SIZE], read_buf[BUF_SIZE];

int errorexit(char *str)
{
    write(2, str, strlen(str));
    exit(1);
}

void sendall(int es)
{
    //i <= max임을 잊지마라!!!!!!!!!!!!!!!!!!!
    for (int i = 0; i <= max; i++)
    {   
        //여기서는 fd_write다!!!!!!!!!!!!!!!!!!!
        if (FD_ISSET(i, &fd_write) && i != es)
            send(i, write_buf, strlen(write_buf), 0);
    }
}


int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;

    int port = atoi(argv[1]);

    //비제로에서 &가 빠졌음...
    bzero(&cli_arr, sizeof(cli_arr));
    FD_ZERO(&fd_active);

    int s_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (s_socket < 0)  
        return 1;
    max = s_socket;
    FD_SET(s_socket, &fd_active);

    struct sockaddr_in servaddr;
    socklen_t len = sizeof(servaddr);
    servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(port);

    if (bind(s_socket, (const struct sockaddr*)&servaddr, len) < 0)
        return 1;
    if (listen(s_socket, 128) < 0)
        return 1;

    while (1)
    {
        fd_read = fd_active;
        fd_write = fd_active;

        if (select(max + 1 , &fd_read, &fd_write, NULL,  NULL) < 0)
            continue ;
        
        // s <= max 다!!!!!!!!!!!!!!!!!!!!!
        for (int s = 0; s <= max ; s++){
            if(FD_ISSET(s, &fd_read) && s == s_socket) {
                // 이부분은 서버와의 연결을 시키는 부분이므로, accept에 s_socket이 들어간다.
                int c_socket = accept(s_socket, (struct sockaddr*)&servaddr, &len);
                if (c_socket < 0)
                    continue ;
                max = c_socket > max ? c_socket : max;
                cli_arr[c_socket].id = next_id++;
                FD_SET(c_socket, &fd_active);
                sprintf(write_buf, "server: client %d just arrived\n", cli_arr[c_socket].id);
                sendall(c_socket);
                break ;
            }

            if(FD_ISSET(s, &fd_read) && s != s_socket)
            {
                int res = recv(s, read_buf, BUF_SIZE, 0);
                //이부분은 떠나는 부분.
                if(res <= 0)
                {
                    sprintf(write_buf, "~leave~~%d", cli_arr[s].id);
                    sendall(s);
                    FD_CLR(s,&fd_active);
                    close(s);
                    //브레이크 까먹지말자
                break ;
                }
                else {
                    for (int i = 0, j = strlen(cli_arr[s].msg); i < res; i++, j++)
                    {
                        cli_arr[s].msg[j] = read_buf[i];
                        //개행일때만 이렇게한다...
                        if (cli_arr[s].msg[j] == '\n')
                        {
                            //마지막 문자를 널로 바꿔준다.
                            cli_arr[s].msg[j] = '\0';
                            sprintf(write_buf, "client %d: %s\n", cli_arr[s].id, cli_arr[s].msg);
                            sendall(s);
                            //여기에서 비제로 함수를 통해서 메세지의 값을 초기화한다.
                            bzero(&cli_arr[s].msg, strlen(cli_arr[s].msg));
                            j = -1;
                        }
                        //브레이크 위치는 바깥 for문에서!!!!!!!!!!!!!!!
                    }
                        break ;
                }

            }
        }
        
        
    }

}