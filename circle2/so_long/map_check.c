/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   check.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: silee <silee@student.42seoul.kr>		   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/05/28 16:01:08 by silee			 #+#	#+#			 */
/*   Updated: 2022/05/31 15:30:00 by silee			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "so_long.h"

void	map_2_array(t_data *g_data, char *file)
{
	char	*line;
	int		fd;

	fd = open (file, O_RDONLY);
	if (fd < 0)
		error_exit (2);
	line = get_next_line(fd);
	g_data->width = ft_strlen(line) - 1;
	g_data->height = 0;
	g_data->line = ft_strdup_without_nl(line);
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		g_data->height += 1;
		if (line == 0)
			break ;
		if (line)
			g_data->line = ft_join_without_nl(g_data->line, line);
	}
	close (fd);
}

void	is_wall(t_data *g_data, int flag)
{
	int		i;

	i = -1;
	if (flag == 1)
	{
		while (++i < g_data->width)
			if (g_data->line[i] != '1')
				error_exit(4);
	}
	else if (flag == g_data->height)
	{
		i = (g_data->height - 1) * g_data->width;
		while (++i <= (g_data->height - 1) * g_data->width + g_data->width -1)
			if (g_data->line[i] != '1')
				error_exit(4);
	}
	else
	{
		i = 1;
		while (++i < g_data->height - 1)
			if (g_data->line[g_data->width * i] != '1' \
				|| g_data->line[g_data->width * i + g_data->width - 1] != '1')
				error_exit(4);
	}
}

t_cnt	*count_init(void)
{
	t_cnt	*count;

	count = malloc(sizeof(t_cnt));
	if (count == 0)
		error_exit (0);
	count->coin = 0;
	count->exit = 0;
	count->start = 0;
	return (count);
}

void	parameter_check(t_cnt *count)
{
	if (count->coin < 1)
		error_exit (5);
	if (count->exit == 0)
		error_exit (6);
	if (count->start != 1)
		error_exit (7);
}

void	check_valid_map(t_data *g_data, char *file)
{
	int		i;
	t_cnt	*count;

	i = 0;
	count = count_init();
	map_2_array (g_data, file);
	if (g_data->height * g_data->width != ft_strlen (g_data->line))
		error_exit (3);
	while (++i <= g_data->height)
		is_wall (g_data, i);
	i = -1;
	while (++i <= g_data->height * g_data->width - 1)
	{
		if (g_data->line[i] == 'C')
			count->coin += 1;
		else if (g_data->line[i] == 'E')
			count->exit += 1;
		else if (g_data->line[i] == 'P')
			count->start += 1;
	}
	parameter_check(count);
	g_data->noc = count->coin;
	free (count);
}
