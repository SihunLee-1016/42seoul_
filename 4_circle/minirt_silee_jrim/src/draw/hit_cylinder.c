/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:31:09 by silee             #+#    #+#             */
/*   Updated: 2022/09/24 10:31:10 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	hit_cylinder_side(t_cy *cyl, t_ray *ray, t_hit *rec)
{
	double		root;

	if (!cyl_side_root(cyl, ray, rec, &root))
		return (false);
	if (!cyl_boundary(cyl, ray_at(ray, root)))
		return (false);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->norm = cyl_norm(cyl, rec->p);
	set_face_normal(ray, rec);
	rec->albedo = cyl->color;
	return (true);
}

bool	cyl_side_root(t_cy *cyl, t_ray *ray, t_hit *rec, double *root)
{
	t_vt	to_center;
	double	a;
	double	half_b;
	double	c;
	double	discrim;

	to_center = vminus(ray->orig, cyl->point);
	a = vlength2(vcross(ray->dir, cyl->norm));
	half_b = vdot(\
		vcross(ray->dir, cyl->norm), vcross(to_center, cyl->norm));
	c = vlength2(vcross(to_center, cyl->norm)) - pow(cyl->diameter / 2, 2);
	discrim = half_b * half_b - a * c;
	if (discrim < EPSILON)
		return (false);
	*root = (-half_b - sqrt(discrim)) / a;
	if (*root < rec->t_min || *root > rec->t_max)
	{
		*root = (-half_b + sqrt(discrim)) / a;
		if (*root < rec->t_min || *root > rec->t_max)
			return (false);
	}
	return (true);
}

bool	cyl_boundary(t_cy *cyl, t_vt at)
{
	double	hit_height;
	double	max_height;

	hit_height = vdot(vminus(at, cyl->point), cyl->norm);
	max_height = cyl->height / 2;
	if (fabs(hit_height) > max_height)
		return (false);
	return (true);
}

bool	hit_cylinder_cap(t_cy *cyl, t_ray *ray, t_hit *rec, int mode)
{
	t_vt	cap_center;
	double	root;
	double	diameter;

	if (mode == CYL_CAP_TOP)
		cap_center = cyl->cap_top;
	else
		cap_center = cyl->cap_bot;
	root = mode;
	if (!cyl_cap_root(cyl, ray, rec, &root))
		return (false);
	diameter = vlength(vminus(cap_center, ray_at(ray, root)));
	if (fabs(cyl->radius) < fabs(diameter))
		return (false);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->t_max = rec->t;
	if (mode == CYL_CAP_TOP)
		rec->norm = cyl->norm;
	else
		rec->norm = vmult(cyl->norm, -1);
	set_face_normal(ray, rec);
	rec->albedo = cyl->color;
	return (true);
}

bool	cyl_cap_root(t_cy *cyl, t_ray *ray, t_hit *rec, double *root)
{
	t_vt	cap_center;
	double	denom;
	double	numer;

	if (*root == CYL_CAP_TOP)
		cap_center = cyl->cap_top;
	else
		cap_center = cyl->cap_bot;
	numer = vdot(vminus(cap_center, ray->orig), cyl->norm);
	denom = vdot(ray->dir, cyl->norm);
	*root = numer / denom;
	if (*root < rec->t_min || *root > rec->t_max)
		return (false);
	return (true);
}
