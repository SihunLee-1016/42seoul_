/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   key.c											  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: silee <silee@student.42seoul.kr>		   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/06/02 14:38:09 by silee			 #+#	#+#			 */
/*   Updated: 2022/06/02 17:38:45 by silee			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "so_long.h"

void	game_exit(t_data *g_data)
{
	g_data->move += 1;
	printf ("move : %d\n", g_data->move);
	printf ("END\n");
	exit (0);
}

void	key_w(t_data *g_data)
{
	int	i;

	i = -1;
	while (++i < ft_strlen (g_data->line))
		if (g_data->line[i] == 'P')
			break ;
	if (g_data->line[i - g_data->width] == 'C')
		g_data->noc -= 1;
	if (g_data->line[i - g_data->width] == 'M' || (g_data->line[i - g_data->width] == 'E' && g_data->noc == 0))
		game_exit(g_data);
	else if (g_data->line[i - g_data->width] != '1' && \
		g_data->line[i - g_data->width] != 'E')
	{
		g_data->line[i] = '0';
		g_data->line[i - g_data->width] = 'P';
		g_data->move += 1;
		printf ("move : %d\n", g_data->move);
		map_draw(g_data);
	}
}

void	key_a(t_data *g_data)
{
	int	i;

	i = -1;
	while (++i < ft_strlen (g_data->line))
		if (g_data->line[i] == 'P')
			break ;
	if (g_data->line[i - 1] == 'C')
		g_data->noc -= 1;
	if (g_data->line[i - 1] == 'M' || (g_data->line[i - 1] == 'E' && g_data->noc == 0))
		game_exit (g_data);
	else if (g_data->line[i - 1] != '1' && g_data->line[i - 1] != 'E')
	{
		g_data->line[i] = '0';
		g_data->line[i - 1] = 'P';
		g_data->move += 1;
		printf ("move : %d\n", g_data->move);
		map_draw(g_data);
	}
}

void	key_s(t_data *g_data)
{
	int	i;

	i = -1;
	while (++i < ft_strlen (g_data->line))
		if (g_data->line[i] == 'P')
			break ;
	if (g_data->line[i + g_data->width] == 'C')
		g_data->noc -= 1;
	if (g_data->line[i + g_data->width] == 'M' || (g_data->line[i + g_data->width] == 'E' && g_data->noc == 0))
		game_exit(g_data);
	else if (g_data->line[i + g_data->width] != '1' \
		&& g_data->line[i + g_data->width] != 'E')
	{
		g_data->line[i] = '0';
		g_data->line[i + g_data->width] = 'P';
		g_data->move += 1;
		printf ("move : %d\n", g_data->move);
		map_draw(g_data);
	}
}

void	key_d(t_data *g_data)
{
	int	i;

	i = -1;
	while (++i < ft_strlen(g_data->line))
		if (g_data->line[i] == 'P')
			break ;
	if (g_data->line[i + 1] == 'C')
		g_data->noc -= 1;
	if (g_data->line[i + 1] == 'M' || (g_data->line[i + 1] == 'E' && g_data->noc == 0))
		game_exit (g_data);
	else if (g_data->line[i + 1] != '1' && g_data->line[i + 1] != 'E')
	{
		g_data->line[i] = '0';
		g_data->line[i + 1] = 'P';
		g_data->move += 1;
		printf ("move : %d\n", g_data->move);
		map_draw(g_data);
	}
}
