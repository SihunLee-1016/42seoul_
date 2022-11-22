/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:31:56 by silee             #+#    #+#             */
/*   Updated: 2022/11/13 17:41:36 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_minirt	info;

	info = (t_minirt){0};
	if (argc != 2)
		err_exit("check your input again");
	parse_main(&info, argv[1]);
	info_init(&info);
	mlx_hook(info.mlx.win, X_EVENT_DESTROY, 0, minirt_end, &info);
	mlx_hook(info.mlx.win, X_EVENT_KEY_PRESS, 0, press_key, &info);
	mlx_loop_hook(info.mlx.mlx, rt_loop_hook, &info);
	mlx_loop(info.mlx.mlx);
	return (0);
}

int	rt_loop_hook(t_minirt *info)
{
	draw_img(info);
	mlx_put_image_to_window(info->mlx.mlx, info->mlx.win, info->mlx.img, 0, 0);
	return (0);
}
