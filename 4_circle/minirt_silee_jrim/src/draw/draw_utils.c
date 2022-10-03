/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:31:02 by silee             #+#    #+#             */
/*   Updated: 2022/09/24 10:31:03 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	make_ray(t_cam *cam, double u, double v)
{
	t_ray		ray;

	ray.orig = cam->orig;
	ray.dir = vunit(vminus(vplus(vplus(cam->l_bot, \
		vmult(cam->hor, u)), vmult(cam->ver, v)), cam->orig));
	return (ray);
}

t_pt	ray_at(t_ray *ray, double t)
{
	t_pt	at;

	at = vplus(ray->orig, vmult(ray->dir, t));
	return (at);
}

void	set_face_normal(t_ray *ray, t_hit *rec)
{
	if (vdot(ray->dir, rec->norm) > 0)
		rec->norm = vmult(rec->norm, -1);
}

t_ray	ray(t_pt orig, t_vt dir)
{
	t_ray	ray;

	ray.orig = orig;
	ray.dir = vunit(dir);
	return (ray);
}

t_vt	cyl_norm(t_cy *cyl, t_vt at)
{
	t_vt	norm;
	t_vt	tmp;

	tmp = vminus(at, cyl->point);
	norm = vminus(tmp, vmult(cyl->norm, vdot(cyl->norm, tmp)));
	return (vunit(norm));
}
