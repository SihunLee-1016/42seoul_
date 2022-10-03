/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:31:23 by silee             #+#    #+#             */
/*   Updated: 2022/09/24 10:31:23 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	sp_trans(t_obj *objs, int mode, double value)
{
	t_sp	*sp;

	while (objs)
	{
		if (objs->type == OBJ_SP)
		{
			sp = (t_sp *)objs->data;
			if (mode == COORD_X)
				sp->center = vplus(sp->center, point3(value, 0, 0));
			if (mode == COORD_Y)
				sp->center = vplus(sp->center, point3(0, value, 0));
			if (mode == COORD_Z)
				sp->center = vplus(sp->center, point3(0, 0, value));
			if (mode == SP_DIAM && sp->diam + value > 0)
				sp->diam += value;
		}
		objs = objs->next;
	}
}

void	pl_rotate(t_obj *objs, int mode, double value)
{
	t_pl	*pl;

	while (objs)
	{
		if (objs->type == OBJ_PL)
		{
			pl = (t_pl *)objs->data;
			if (mode == COORD_X)
				pl->norm = vunit(vplus(pl->norm, vec3(value, 0, 0)));
			if (mode == COORD_Y)
				pl->norm = vunit(vplus(pl->norm, vec3(0, value, 0)));
			if (mode == COORD_Z)
				pl->norm = vunit(vplus(pl->norm, vec3(0, 0, value)));
		}
		objs = objs->next;
	}
}

void	pl_trans(t_obj *objs, int mode, double value)
{
	t_pl	*pl;

	while (objs)
	{
		if (objs->type == OBJ_PL)
		{	
			pl = (t_pl *)objs->data;
			if (mode == COORD_X)
				pl->point = vplus(pl->point, point3(value, 0, 0));
			if (mode == COORD_Y)
				pl->point = vplus(pl->point, point3(0, value, 0));
			if (mode == COORD_Z)
				pl->point = vplus(pl->point, point3(0, 0, value));
		}
		objs = objs->next;
	}
}

void	cy_rotate(t_obj *objs, int mode, double value)
{
	t_cy	*cy;

	while (objs)
	{
		if (objs->type == OBJ_CY)
		{
			cy = (t_cy *)objs->data;
			if (mode == COORD_X)
				cy->norm = vunit(vplus(cy->norm, vec3(value, 0, 0)));
			if (mode == COORD_Y)
				cy->norm = vunit(vplus(cy->norm, vec3(0, value, 0)));
			if (mode == COORD_Z)
				cy->norm = vunit(vplus(cy->norm, vec3(0, 0, value)));
		}
		objs = objs->next;
	}
}

void	cy_trans(t_obj *objs, int mode, double value)
{
	t_cy	*cy;

	while (objs)
	{
		if (objs->type == OBJ_CY)
		{
			cy = (t_cy *)objs->data;
			if (mode == COORD_X)
				cy->point = vplus(cy->point, point3(value, 0, 0));
			if (mode == COORD_Y)
				cy->point = vplus(cy->point, point3(0, value, 0));
			if (mode == COORD_Z)
				cy->point = vplus(cy->point, point3(0, 0, value));
			if (mode == CY_DIAM && cy->diameter + value > 0)
					cy->diameter += value;
			if (mode == CY_HEIGHT && cy->height + value > 0)
					cy->height += value;
		}
		objs = objs->next;
	}
}
