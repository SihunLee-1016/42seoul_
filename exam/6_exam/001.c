#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>


#define BUF_SIZE 42 * 4092

typedef struct client{
    int id;
    char msg[110000];
}   t_client;

int max, next_id;

t_client cli_arr[1024];

fd_set fd_active, fd_read, fd_write;

char read_buf[BUF_SIZE], write_buf[BUF_SIZE];

int exit_error(char *str)
{
    write(2, str, strlen(str));
    exit(1);
}
//send다!!!!!!!!!!!!!
void send_all(int es)
{
    for (int i = 0; i <= max; i++)
    {
        if (FD_ISSET(i, &fd_write) && i != es)
            send(i, write_buf,strlen(write_buf), 0);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;
    int port = atoi(argv[1]);
    FD_ZERO(&fd_active);
    bzero(&cli_arr, sizeof(cli_arr));

    int s_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (socket < 0)
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

        if (select (max + 1, &fd_read, &fd_write, NULL, NULL) < 0)
            continue ;
        for (int s = 0; s <= max; s++)
        {
            if (FD_ISSET(s, &fd_read) && s == s_socket)
            {
                int c_socket = accept(s_socket, (struct sockaddr*)&servaddr, &len);
                if (c_socket < 0)
                    continue ;
                max = c_socket > max ? c_socket:max;
                cli_arr[c_socket].id = next_id++;
                FD_SET(c_socket, &fd_active);
                sprintf(write_buf, "~~~%d~~", cli_arr[c_socket].id);
                send_all(c_socket);
                break ;
            }

            if (FD_ISSET(s, &fd_read) && s != s_socket)
            {
                int res = recv(s, read_buf, BUF_SIZE, 0);
                if (res <= 0)
                {
                    sprintf(write_buf, "~~~~leave %d\n", cli_arr[s].id);
                    send_all(s);
                    FD_CLR(s, &fd_active);
                    close(s);
                    break ;
                }
                else {
                    for (int i = 0, j = strlen(cli_arr[s].msg); i < res; i++, j++)
                    {
                        cli_arr[s].msg[j] = read_buf[i];
                        if (cli_arr[s].msg[j] == '\n')
                        {
                            cli_arr[s].msg[j] = '\0';
                            sprintf(write_buf, "~~~%d : %s\n", cli_arr[s].id, cli_arr[s].msg);
                            send_all(s);
                            bzero(&cli_arr[s].msg, strlen(cli_arr[s].msg));
                            j = -1;
                        }
                    }
                    break ;
                }

            }
        }

    }


}