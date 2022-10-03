/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:31:18 by silee             #+#    #+#             */
/*   Updated: 2022/09/24 10:31:19 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cam_rotate(t_minirt *info, int key_num)
{
	t_vt	*dir;

	dir = &info->scene.cam.dir;
	if (key_num == K_RT)
		*dir = vunit(vplus(*dir, vec3(0.1, 0, 0)));
	if (key_num == K_LF)
		*dir = vunit(vplus(*dir, vec3(-0.1, 0, 0)));
	if (key_num == K_UP)
		*dir = vunit(vplus(*dir, vec3(0, 0.1, 0)));
	if (key_num == K_DW)
		*dir = vunit(vplus(*dir, vec3(0, -0.1, 0)));
}

void	cam_trans(t_minirt *info, int key_num)
{
	t_pt	*orig;

	orig = &info->scene.cam.orig;
	if (key_num == K_NUM1)
		*orig = vplus(*orig, point3(1, 0, 0));
	if (key_num == K_NUM2)
		*orig = vplus(*orig, point3(-1, 0, 0));
	if (key_num == K_NUM3)
		*orig = vplus(*orig, point3(0, 1, 0));
	if (key_num == K_NUM4)
		*orig = vplus(*orig, point3(0, -1, 0));
	if (key_num == K_NUM5)
		*orig = vplus(*orig, point3(0, 0, 1));
	if (key_num == K_NUM6)
		*orig = vplus(*orig, point3(0, 0, -1));
}

void	light_trans(t_minirt *info, int key_num)
{
	t_pt	*orig;

	orig = &info->scene.light.orig;
	if (key_num == K_NUM7)
		*orig = vplus(*orig, point3(1, 0, 0));
	if (key_num == K_NUM8)
		*orig = vplus(*orig, point3(-1, 0, 0));
	if (key_num == K_NUM9)
		*orig = vplus(*orig, point3(0, 1, 0));
	if (key_num == K_NUM0)
		*orig = vplus(*orig, point3(0, -1, 0));
	if (key_num == K_MINUS)
		*orig = vplus(*orig, point3(0, 0, 1));
	if (key_num == K_PLUS)
		*orig = vplus(*orig, point3(0, 0, -1));
}
