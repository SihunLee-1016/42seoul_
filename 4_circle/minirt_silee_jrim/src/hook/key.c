/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:31:21 by silee             #+#    #+#             */
/*   Updated: 2022/11/13 18:07:20 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	press_key(int key_num, t_minirt *info)
{
	if (key_num == K_ESC)
		minirt_end(info);
	cam_rotate(info, key_num);
	cam_trans(info, key_num);
	light_trans(info, key_num);
	sp_key(info, key_num);
	pl_key(info, key_num);
	cy_key(info, key_num);
	obj_size_key(info, key_num);
	draw_img(info);
	return (0);
}

int	minirt_end(t_minirt *info)
{
	printf("bye!\n");
	mlx_destroy_window(info->mlx.mlx, info->mlx.win);
	system("leaks miniRT");
	exit(0);
}
