#include "so_long.h"

t_img   img_input(void *mlx)
{
    t_img   tmp;
    int     wid;
    int     hei;

    tmp.coin = mlx_xpm_file_to_image(mlx, "./img/cheeze.xpm",&wid,&hei);
    tmp.ground = mlx_xpm_file_to_image(mlx, "./img/grass.xpm",&wid,&hei);
    tmp.player = mlx_xpm_file_to_image(mlx, "./img/dino.xpm",&wid,&hei);
    tmp.wall = mlx_xpm_file_to_image(mlx, "./img/wall.xpm",&wid,&hei);
    tmp.exit = mlx_xpm_file_to_image(mlx, "./img/exit.xpm",&wid,&hei);
    return (tmp);
}

void    map_draw(t_data *g)
{
    int hei;
    int wid;

    hei = 0;
	while (hei < g->map_height)
	{
		wid = 0;
		while (wid < g->map_width)
		{
			if (g->map_line[hei * g->map_width + wid] == '1')
				mlx_put_image_to_window(g->mlx, g->win, g->img.wall, wid * 64, hei * 64);
			else if (g->map_line[hei * g->map_width + wid] == 'C')
				mlx_put_image_to_window(g->mlx, g->win, g->img.coin, wid * 64, hei * 64);
			else if (g->map_line[hei * g->map_width + wid] == 'P')
				mlx_put_image_to_window(g->mlx, g->win, g->img.player, wid * 64, hei * 64);
			else if (g->map_line[hei * g->map_width + wid] == 'E')
				mlx_put_image_to_window(g->mlx, g->win, g->img.exit, wid * 64, hei * 64);
			else
				mlx_put_image_to_window(g->mlx, g->win, g->img.ground, wid * 64, hei * 64);
			wid++;
		}
		hei++;
	}
}
