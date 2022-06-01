#include "so_long.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_data	*g_data;


	g_data = malloc(sizeof(t_data));
	if (argc != 2)
		exit(1);
	// g_data->fd = open(argv[1], O_RDONLY);
	check_valid_map(g_data, argv[1]);
	g_data->mlx = mlx_init();
	g_data->img = img_input(g_data->mlx);
	g_data->win = mlx_new_window(g_data->mlx, g_data->map_width * 64, g_data->map_height * 64, "so_long");
	map_draw(g_data);
	// mlx_loop_hook(mlx_ptr,/*맵그리는함수넣기*/,/*data*/);
	mlx_loop(g_data->mlx);
}