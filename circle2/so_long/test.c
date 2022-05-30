#include "so_long.h"
#include <stdio.h>
int main()
{
    char    *str;
    char    *line;
    int     fd;
    int     height = 0;
    int     width;

    fd = open ("test.txt", O_RDONLY);
    str = get_next_line(fd);
    width = ft_strlen(str) - 1;
    line = ft_strdup_without_nl(str);
    free (str);
    while (str)
    {
        height += 1;
        if (*str == '\n')
            break ;
        str = get_next_line(fd);
        if (str)
            line = ft_join_without_nl(line,str);

    }
    printf("line  = %s",line);
    printf("line len = %d",ft_strlen(line));
    printf("height = %d, width = %d\n",height,width);

    close(fd);
    free(line);
}

	// char	*line;

	// game_data->fd = open(file, O_RDONLY);
	// line = get_next_line(game_data->fd);
	// game_data->map_height = 0;

	// game_data->map_width = ft_strlen(line) - 1;
	
    // game_data->map_line = ft_strdup_without_nl(line);
	
    // free(line);
	// while (line)
	// {
	// 	game_data->map_height += 1;
	// 	line = get_next_line(fd);
	// 	if (line)
	// 		game_data->map_line = ft_join_without_nl(game_data->map_line, line);
	// 	free(line);
	// }
	