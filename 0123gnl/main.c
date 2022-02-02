#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
int	main(void)
{
    int     fd;
    char    *tmp;
    int     idx;

    fd = open("test", O_RDONLY);
    idx = 1;
    printf ("fd : %d\n", fd);
    while ((tmp = get_next_line(fd)) != 0)
    {
        printf("\n----- %d -----\n", idx);                               
        printf("%s", tmp);
        printf("-------------\n\n");
        idx++;
		free(tmp);
    }
    close(fd);
    // system("leaks a.out");
    return (0);
}

// int main()
// {
// 	int		j;
// 	char	*line = 0;

// 	j = 1;
// 	while ((line = get_next_line(0)) != 0)
// 	{ß
// 		printf("%s", line);
// 		free(line);
// 		j++;
// 	}
// 	free(line);
// }