/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:31:29 by silee             #+#    #+#             */
/*   Updated: 2022/09/24 10:31:29 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_norm(char *str, t_vt *vec)
{
	char	**coord;

	coord = rt_split(str, ',');
	if (check_split(coord, 3) == false)
		err_exit("invalid argument (norm)");
	*vec = vec3(rt_atod(coord[0]), rt_atod(coord[1]), rt_atod(coord[2]));
	if (!check_range(vec->x, -1.0, 1.0)
		|| !check_range(vec->y, -1.0, 1.0)
		|| !check_range(vec->z, -1.0, 1.0))
		err_exit("normal vector is out of range");
	*vec = vunit(*vec);
	free_all(coord);
}

void	get_point(char *str, t_pt *point)
{
	char	**coord;

	coord = rt_split(str, ',');
	if (check_split(coord, 3) == false)
		err_exit("invalid argument (point)");
	*point = point3(rt_atod(coord[0]), rt_atod(coord[1]), rt_atod(coord[2]));
	free_all(coord);
}

void	get_color(char *str, t_cl *color)
{
	char	**coord;
	int		r;
	int		g;
	int		b;

	coord = rt_split(str, ',');
	if (check_split(coord, 3) == false)
		err_exit("invalid argument (color)");
	r = rt_atoi(coord[0]);
	g = rt_atoi(coord[1]);
	b = rt_atoi(coord[2]);
	check_color(r, g, b);
	*color = color3((double)r / 255.0, \
					(double)g / 255.0, \
					(double)b / 255.0);
	free_all(coord);
}
