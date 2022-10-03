/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:31:48 by silee             #+#    #+#             */
/*   Updated: 2022/09/24 10:31:48 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vt	vec3(double x, double y, double z)
{
	t_vt	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_pt	point3(double x, double y, double z)
{
	t_pt	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_pt	color3(double r, double g, double b)
{
	t_cl	color;

	color.x = r;
	color.y = g;
	color.z = b;
	return (color);
}
