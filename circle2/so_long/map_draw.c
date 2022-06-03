/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihunlee <sihunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:01:12 by silee             #+#    #+#             */
/*   Updated: 2022/06/03 18:15:40 by sihunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	img_input(void *mlx)
{
	t_img	tmp;
	int		wid;
	int		hei;

	tmp.coin = mlx_xpm_file_to_image(mlx, "./img/coin.xpm", &wid, &hei);
	tmp.ground = mlx_xpm_file_to_image(mlx, "./img/grass.xpm", &wid, &hei);
	tmp.player = mlx_xpm_file_to_image(mlx, "./img/player.xpm", &wid, &hei);
	tmp.wall = mlx_xpm_file_to_image(mlx, "./img/wall.xpm", &wid, &hei);
	tmp.exit = mlx_xpm_file_to_image(mlx, "./img/exit.xpm", &wid, &hei);
	tmp.monster = mlx_xpm_file_to_image(mlx, "./img/monster.xpm", &wid, &hei);
	return (tmp);
}

void	img_2_window(t_data *g, int w, int h)
{
	if (g->line[h * g->width + w] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img.wall, w * 64, h * 64);
	else if (g->line[h * g->width + w] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->img.coin, w * 64, h * 64);
	else if (g->line[h * g->width + w] == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->img.player, w * 64, h * 64);
	else if (g->line[h * g->width + w] == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->img.exit, w * 64, h * 64);
	else if (g->line[h * g->width + w] == 'M')
		mlx_put_image_to_window(g->mlx, g->win, g->img.monster, w * 64, h * 64);
	else
		mlx_put_image_to_window(g->mlx, g->win, g->img.ground, w * 64, h * 64);
}

void	map_draw(t_data *g)
{
	int	h;	
	int	w;

	h = 0;
	while (h < g->height)
	{
		w = 0;
		while (w < g->width)
		{
			img_2_window(g, w, h);
			w++;
		}
		h++;
	}
}
