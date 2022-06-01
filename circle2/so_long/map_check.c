/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   map_check.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: silee <silee@student.42seoul.kr>		   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/05/28 16:01:08 by silee			 #+#	#+#			 */
/*   Updated: 2022/05/31 15:30:00 by silee			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "so_long.h"	
#include <stdio.h>
void	map_2_array(t_data *g_data,char *file)
{
	char	*line;
	int		fd;

	fd = open (file, O_RDONLY);
	line = get_next_line(fd);
	g_data->map_width = ft_strlen(line) - 1;
	g_data->map_height = 0;
	g_data->map_line = ft_strdup_without_nl(line);
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		g_data->map_height += 1;
		if (line == 0)
			break ;
		if (line)
			g_data->map_line = ft_join_without_nl(g_data->map_line, line);
	}
	printf("\nresult = %s\n",g_data->map_line);
	close (fd);
}

void	error_exit(void)
{
	write (2, "ERROR\n", 7);
	exit (1);
}

void	is_wall(t_data *g_data, int flag)
{
	int		i;
	char	*line;

	i = -1;
	line = g_data->map_line;
	if (flag == 1)
	{
		while (++i < g_data->map_width)
			if (line[i] != '1')
			{
				printf("first\n");
				error_exit ();
			}
	}
	else if (flag == g_data->map_height)
	{
		i = (g_data->map_height - 1) * g_data->map_width;
		while (++i <= (g_data->map_height - 1) * g_data->map_width + \
			g_data->map_width -1)
			if (line[i] != '1')
			{
				printf("last\n");
				printf("error index = %d",i);
				error_exit();
			}
	}
	else
	{
		i = 1;
		while (++i < g_data->map_height - 1)
			if (line[g_data->map_width * i] != '1' \
				|| line[g_data->map_width * i + g_data->map_width - 1] != '1')
				{
					printf("middle\n");
				error_exit();
				}
	}
}

t_cnt	*count_init(void)
{
	t_cnt *count;

	count = malloc(sizeof(t_cnt));
	count->coin = 0;
	count->exit = 0;
	count->start = 0;
	return (count);
}

void	map_parameter_check(t_cnt *count)
{
	if (count->coin < 1)
		error_exit ();
	if (count->exit == 0)
		error_exit ();
	if (count->start != 1)
		error_exit ();
}

void	check_valid_map(t_data *g_data, char *file)
{
	int		i;
	t_cnt	*count;

	i = 0;
	count = count_init();
	map_2_array(g_data,file);
	if (g_data->map_height * g_data->map_width != ft_strlen (g_data->map_line))
	{
		printf("hei : %d wid : %d\nstrlen : %d",g_data->map_height,g_data->map_width,ft_strlen(g_data->map_line));
		printf("map_check\n");
		error_exit ();
	}
	while (++i <= g_data->map_height)
		is_wall (g_data, i);
	i = -1;
	while (++i <= g_data->map_height * g_data->map_width - 1)
	{
		if (g_data->map_line[i] == 'C')
			count->coin += 1;
		else if (g_data->map_line[i] == 'E')
			count->exit += 1;
		else if (g_data->map_line[i] == 'P')
			count->start += 1;
		}
	map_parameter_check(count);
	printf("coin %d\nexit %d\nstart %d\n",count->coin,count->exit,count->start);
}
