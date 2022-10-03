/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:31:26 by silee             #+#    #+#             */
/*   Updated: 2022/09/24 10:42:27 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	check_split(char **strs, int cnt)
{
	int	idx;

	idx = 0;
	while (strs[idx])
		idx++;
	if (idx != cnt)
		return (false);
	return (true);
}

void	check_color(int r, int g, int b)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		err_exit("color value is out of range");
}

void	check_len(double len)
{
	if (len <= 0.0)
		err_exit("length must be positive");
}

bool	check_range(double val, double min, double max)
{
	if (val < min || val > max)
		return (false);
	return (true);
}

void	check_scene_init(t_scene *scene)
{
	if (scene->amb.init == false)
		err_exit("ambient doesn't exist");
	if (scene->cam.init == false)
		err_exit("camera doesn't exist");
	if (scene->light.init == false)
		err_exit("light doesn't exist");
}
