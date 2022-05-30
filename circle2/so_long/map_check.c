/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 16:01:08 by silee             #+#    #+#             */
/*   Updated: 2022/05/30 21:17:45 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    map_2_array(char *file, t_data *g_data)
{
	char	*line;

	g_data->fd = open(file, O_RDONLY);
	line = get_next_line(g_data->fd);
	g_data->map_height = 0;
	g_data->map_width = ft_strlen(line) - 1;
	g_data->map_line = ft_strdup_without_nl(line);
	free(line);
	while (line)
	{
		g_data->map_height += 1;
	    if (*str == '\n')
            break ;
		line = get_next_line(fd);
		if (line)
			g_data->map_line = ft_join_without_nl(g_data->map_line, line);
		free(line);
	}
}

void	error_exit()
{
	write (2, "ERROR\n", 7);
	exit (1);
}

void	is_wall(t_data *g_data, int flag)
{
	int	i;
	char	*line;

	i == -1;
	line = g_data->map_line;
	if (flag == 1)
		while (++i < g_data->map_width)
			if (line[i] != '1')
				error_exit(); 
	else if (flag == 2)
	{
		i = 0
		while (++i < g_data->map_height - 1)
			if (line[g_data->map_width * i]  != '1' && line[g_data->map_width * i + width - 1] != '1')
				error_exit();
	}
	else 
	{
		i = (g_data->map_height - 1) * g_data->map_width - 1;
		while (++i < (g_data->map_height - 1) * g_data->map_width + g_data->map_width)
			if (line[i] != '\1')
				error_exit();
	}
}

void	check_valid_map(t_data *g_data)
{
	int	first;
	int	last;
	int	i;

	if (g_data->map_height * g_data->map_width != ft_strlen(g_data->map_line));
		error_exit();
	is_wall(g_data, 1);

	
}

111
111
111 -> strlen = 3, height = 3, result = 9

012 345 678
111 111 111
다 이이어 붙힌다면 idx는 0~2가 첫줄, 3~5가 둘째줄, 6~8이 마지막 줄일것이다.
(개행을 제외하고 보므로.)

0, 3 ,6이 첫 줄.
2 5 8이 마지막 줄.