/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:31:33 by silee             #+#    #+#             */
/*   Updated: 2022/09/24 10:31:34 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_ambient(char **strs, t_amb *amb)
{
	if (amb->init == true)
		return ;
	if (check_split(strs, 3) == false)
		err_exit("invalid argument number (ambient)");
	amb->ratio = rt_atod(strs[1]);
	if (!check_range(amb->ratio, 0.0, 1.0))
		err_exit("ambient ratio is out of range");
	get_color(strs[2], &amb->color);
	amb->init = true;
}

void	parse_camera(char **strs, t_cam *cam)
{
	if (cam->init == true)
		return ;
	if (check_split(strs, 4) == false)
		err_exit("invalid argument number (camera)");
	get_point(strs[1], &cam->orig);
	get_norm(strs[2], &cam->dir);
	cam->fov = rt_atod(strs[3]);
	if (!check_range(cam->fov, 0.0, 180.0))
		err_exit("fov is out of range");
	cam->init = true;
}

void	parse_light(char **strs, t_light *light)
{
	if (light->init == true)
		return ;
	if (check_split(strs, 4) == false)
		err_exit("invalid argument number (light)");
	get_point(strs[1], &light->orig);
	light->bright_ratio = rt_atod(strs[2]);
	if (!check_range(light->bright_ratio, 0.0, 1.0))
		err_exit("bright ratio is out of range");
	get_color(strs[3], &light->color);
	light->init = true;
}
