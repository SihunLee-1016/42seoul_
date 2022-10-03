/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:31:13 by silee             #+#    #+#             */
/*   Updated: 2022/09/24 10:31:13 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	in_shadow(t_minirt *minirt, t_ray *ray, t_hit *rec, double light_len)
{
	rec->t_min = 0;
	rec->t_max = light_len;
	if (hit_check(minirt, ray, rec))
		return (1);
	return (0);
}

t_vt	reflect(t_vt v, t_vt n)
{
	return (vminus(v, vmult(n, 2 * vdot(v, n))));
}

t_cl	lighting(t_minirt *minirt, t_hit *rec)
{
	t_phong_light	pl;
	t_cl			color;

	color = color3(0, 0, 0);
	if (rec->t_max > INFINITY - 1)
		return (color);
	pl.light_dir = vminus(minirt->scene.light.orig, rec->p);
	pl.light_len = vlength(pl.light_dir);
	pl.light_ray = ray(vplus(rec->p, vmult(rec->norm, EPSILON)), pl.light_dir);
	if (in_shadow(minirt, &pl.light_ray, rec, pl.light_len))
		return (color3(0, 0, 0));
	pl.light_dir = vunit(vminus(minirt->scene.light.orig, rec->p));
	pl.kd = fmax(vdot(rec->norm, pl.light_dir), 0.0);
	pl.diffuse = vmult(minirt->scene.light.color, \
		pl.kd * minirt->scene.light.bright_ratio);
	pl.view_dir = vunit(vmult(minirt->scene.ray.dir, -1));
	pl.reflect_dir = reflect(vmult(pl.light_dir, -1), rec->norm);
	pl.ksn = 34;
	pl.ks = 1;
	pl.spec = pow(fmax(vdot(pl.view_dir, pl.reflect_dir), 0.0), pl.ksn);
	pl.specular = vmult(vmult(minirt->scene.light.color, \
		pl.ks * minirt->scene.light.bright_ratio), pl.spec);
	color = vplus((vplus(color, vplus(pl.diffuse, pl.specular))), \
		vmult(minirt->scene.amb.color, minirt->scene.amb.ratio));
	return (vmin(vmult_(color, rec->albedo), color3(1, 1, 1)));
}
