/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:30:56 by silee             #+#    #+#             */
/*   Updated: 2022/09/24 10:44:32 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	info_init(t_minirt *info)
{
	info->mlx.mlx = mlx_init();
	if (!info->mlx.mlx)
		exit(1);
	info->mlx.win = mlx_new_window(info->mlx.mlx, WID, HEI, "miniRT");
	if (!info->mlx.win)
		exit(1);
	info->mlx.img = mlx_new_image(info->mlx.mlx, WID, HEI);
	if (!info->mlx.img)
		exit(1);
	info->mlx.addr = mlx_get_data_addr(info->mlx.img, &info->mlx.bpp,
			&info->mlx.size_line, &info->mlx.endian);
	if (!info->mlx.addr)
		exit(1);
}

static t_vt	cam_set_vup(t_vt dir)
{
	if (dir.x == 0 && dir.y != 0 && dir.z == 0)
		return (vec3(0, dir.y, 1e-6));
	else
		return (vec3(0, 1, 0));
}

void	camera_init(t_cam *camera)
{
	t_vt	w;
	t_vt	u;
	t_vt	v;

	camera->focal_len = tan((camera->fov * M_PI / 180.0) / 2.0);
	camera->vp_h = camera->focal_len * 2;
	camera->vp_w = camera->vp_h * ((double)WID / (double)HEI);
	camera->dir = vunit(camera->dir);
	w = vunit(vmult(camera->dir, -1));
	u = vunit(vcross(cam_set_vup(camera->dir), w));
	v = vcross(w, u);
	camera->hor = vmult(u, camera->vp_w);
	camera->ver = vmult(v, camera->vp_h);
	camera->l_bot = vminus(vminus \
		(vminus(camera->orig, vdivide(camera->hor, 2)), \
			vdivide(camera->ver, 2)), w);
}
