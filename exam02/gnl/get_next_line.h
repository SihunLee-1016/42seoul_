#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# define BUFFER_SIZE 1
char *get_next_line(int fd);
char    *ft_strdup(char *str);
int ft_strlen(char *str);
#endif