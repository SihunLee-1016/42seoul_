/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:31:31 by silee             #+#    #+#             */
/*   Updated: 2022/09/24 10:31:31 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_sphere(char **strs, t_obj **objs)
{
	t_sp	*sp;

	if (check_split(strs, 4) == false)
		err_exit("invalid argument number (sphere)");
	sp = (t_sp *)malloc(sizeof(t_sp));
	if (!sp)
		err_exit("cannot allocate memory (sphere)");
	get_point(strs[1], &sp->center);
	sp->diam = rt_atod(strs[2]);
	check_len(sp->diam);
	get_color(strs[3], &sp->color);
	obj_add(objs, obj_init(OBJ_SP, sp));
}

void	parse_plane(char **strs, t_obj **objs)
{
	t_pl	*pl;

	if (check_split(strs, 4) == false)
		err_exit("invalid argument number (plane)");
	pl = (t_pl *)malloc(sizeof(t_pl));
	if (!pl)
		err_exit("cannot allocate memory (plane)");
	get_point(strs[1], &pl->point);
	get_norm(strs[2], &pl->norm);
	get_color(strs[3], &pl->color);
	obj_add(objs, obj_init(OBJ_PL, pl));
}

void	parse_cylinder(char **strs, t_obj **objs)
{
	t_cy	*cy;

	if (check_split(strs, 6) == false)
		err_exit("invalid argument number (cylinder)");
	cy = (t_cy *)malloc(sizeof(t_cy));
	if (!cy)
		err_exit("cannot allocate memory (cylinder)");
	get_point(strs[1], &cy->point);
	get_norm(strs[2], &cy->norm);
	cy->diameter = rt_atod(strs[3]);
	check_len(cy->diameter);
	cy->height = rt_atod(strs[4]);
	check_len(cy->height);
	get_color(strs[5], &cy->color);
	obj_add(objs, obj_init(OBJ_CY, cy));
}
