/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:31:37 by silee             #+#    #+#             */
/*   Updated: 2022/09/24 10:31:38 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_main(t_minirt *info, char *filename)
{
	int		rt_fd;
	char	*line;

	if (filename == NULL)
		err_exit("invalid filename");
	if (rt_strcmp(filename + rt_strlen(filename) - 3, ".rt") != 0)
		err_exit("invalid file extension");
	rt_fd = open(filename, O_RDONLY);
	if (rt_fd == -1)
		err_exit("file not found");
	info->scene.amb.init = false;
	info->scene.cam.init = false;
	info->scene.light.init = false;
	line = get_next_line(rt_fd);
	while (line != NULL)
	{
		parse_line(line, &info->scene, &info->objs);
		free(line);
		line = get_next_line(rt_fd);
	}
	free(line);
	close(rt_fd);
	check_scene_init(&info->scene);
}

void	parse_line(char *line, t_scene *scene, t_obj **objs)
{
	char	**strs;

	strs = rt_split(line, ' ');
	if (strs[0][0] == '\0' || strs[0][0] == '\n' || strs[0][0] == '#')
		;
	else if (rt_strcmp(strs[0], "A") == 0)
		parse_ambient(strs, &scene->amb);
	else if (rt_strcmp(strs[0], "C") == 0)
		parse_camera(strs, &scene->cam);
	else if (rt_strcmp(strs[0], "L") == 0)
		parse_light(strs, &scene->light);
	else if (rt_strcmp(strs[0], "sp") == 0)
		parse_sphere(strs, objs);
	else if (rt_strcmp(strs[0], "pl") == 0)
		parse_plane(strs, objs);
	else if (rt_strcmp(strs[0], "cy") == 0)
		parse_cylinder(strs, objs);
	else
		err_exit("invalid file format");
	free_all(strs);
}
