/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   so_long.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: silee <silee@student.42seoul.kr>		   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/05/30 18:42:06 by silee			 #+#	#+#			 */
/*   Updated: 2022/06/02 18:08:10 by silee			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "so_long.h"

int	destroy_game(t_data *g_data)
{
	printf ("END\n");
	mlx_destroy_window (g_data->mlx, g_data->win);
	exit (0);
}

int	key_press(int key, t_data *g_data)
{
	if (key == KEY_ESC)
		game_exit (g_data);
	if (key == KEY_W)
		key_w(g_data);
	if (key == KEY_A)
		key_a(g_data);
	if (key == KEY_S)
		key_s(g_data);
	if (key == KEY_D)
		key_d(g_data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*g_data;

	g_data = malloc(sizeof(t_data));
	if (g_data == 0)
		error_exit(0);
	if (argc != 2)
		error_exit(1);
	check_valid_map(g_data, argv[1]);
	g_data->move = 0;
	g_data->mlx = mlx_init();
	g_data->img = img_input(g_data->mlx);
	g_data->win = mlx_new_window(g_data->mlx, g_data->width * 64, \
		g_data->height * 64, "so_long");
	map_draw(g_data);
	mlx_hook(g_data->win, X_EVENT_KEY_PRESS, 0, &key_press, g_data);
	mlx_hook(g_data->win, X_EVENT_KEY_EXIT, 0, &destroy_game, g_data);
	mlx_loop(g_data->mlx);
	return (0);
}
