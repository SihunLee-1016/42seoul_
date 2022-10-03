/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:31:11 by silee             #+#    #+#             */
/*   Updated: 2022/09/24 10:31:11 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	hit_sp(t_sp *sp, t_ray *ray, t_hit *rec)
{
	t_vt		oc;
	t_hit_sp	data;

	oc = vminus(ray->orig, sp->center);
	data.a = vlength2(ray->dir);
	data.half_b = vdot(oc, ray->dir);
	data.c = vlength2(oc) - sp->diam * sp->diam / 4;
	data.disc = data.half_b * data.half_b - data.a * data.c;
	if (data.disc < 0)
		return (false);
	data.sqrtd = sqrt(data.disc);
	data.root = (-data.half_b - data.sqrtd) / data.a;
	if (data.root < rec->t_min || rec->t_max < data.root)
	{
		data.root = (-data.half_b + data.sqrtd) / data.a;
		if (data.root < rec->t_min || rec->t_max < data.root)
			return (false);
	}
	rec->t = data.root;
	rec->p = ray_at(ray, data.root);
	rec->norm = vdivide(vminus(rec->p, sp->center), sp->diam / 2);
	set_face_normal (ray, rec);
	rec->albedo = sp->color;
	return (true);
}

bool	hit_pl(t_pl *pl, t_ray *ray, t_hit *rec)
{
	double	numerator;
	double	denominator;
	double	root;

	denominator = vdot(ray->dir, pl->norm);
	if (fabs(denominator) < EPSILON)
		return (false);
	numerator = vdot(vminus(pl->point, ray->orig), pl->norm);
	root = numerator / denominator;
	if (root < rec->t_min || rec->t_max <= root)
		return (false);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->norm = pl->norm;
	set_face_normal(ray, rec);
	rec->albedo = pl->color;
	return (true);
}

bool	hit_cy(t_cy *cy, t_ray *ray, t_hit *rec)
{
	int	result;

	cy->norm = vunit(cy->norm);
	cy->radius = cy->diameter / 2;
	cy->cap_top = vplus(cy->point, vmult(cy->norm, cy->height / 2));
	cy->cap_bot = vplus(cy->point, vmult(cy->norm, -(cy->height / 2)));
	cy->norm = vunit(cy->norm);
	result = 0;
	result += hit_cylinder_cap(cy, ray, rec, CYL_CAP_TOP);
	result += hit_cylinder_cap(cy, ray, rec, CYL_CAP_BOT);
	result += hit_cylinder_side(cy, ray, rec);
	return (result);
}

bool	obj_type_check(t_obj *obj, t_ray *ray, t_hit *rec)
{
	bool	hit;

	hit = false;
	if (obj->type == 0)
		hit = hit_sp((t_sp *)obj->data, ray, rec);
	else if (obj->type == 1)
		hit = hit_pl((t_pl *)obj->data, ray, rec);
	else if (obj->type == 2)
		hit = hit_cy((t_cy *)obj->data, ray, rec);
	return (hit);
}

bool	hit_check(t_minirt *minirt, t_ray *ray, t_hit *rec)
{
	t_hit	tmp;
	t_obj	*objects;
	bool	smt_hit;

	tmp = *rec;
	objects = minirt->objs;
	smt_hit = false;
	while (objects)
	{
		if (obj_type_check(objects, ray, &tmp))
		{
			smt_hit = true;
			tmp.t_max = tmp.t;
			*rec = tmp;
		}
		objects = objects->next;
	}
	return (smt_hit);
}
