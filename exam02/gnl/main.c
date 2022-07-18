#include "get_next_line.h"
#include <stdio.h>
int main()
{
    int fd;
    char    *tmp;
    int  i;
    i = 1;
    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
        return (0);
    while ( (tmp = get_next_line(fd)) != 0)
    {
        printf("idx : %d\n", i++);
        printf("-----------------\n");
        printf("%s", tmp);
        printf("-----------------\n\n");
        free(tmp);
        if (i == 19)
            break ;
    }
    close (fd);
    return (0);
}