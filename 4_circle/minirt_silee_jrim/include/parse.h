/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:32:08 by silee             #+#    #+#             */
/*   Updated: 2022/09/24 10:32:08 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "structs.h"

# define ATOI_MAX 9223372036854775807
# define ATOI_MIN 9223372036854775808ULL

//--------------------------- parse ---------------------------
void	parse_main(t_minirt *info, char *filename);
void	parse_line(char *line, t_scene *scene, t_obj **objs);

//------------------------ parse_scene ------------------------
void	parse_ambient(char **strs, t_amb *amb);
void	parse_camera(char **strs, t_cam *cam);
void	parse_light(char **strs, t_light *light);

//------------------------- parse_obj -------------------------
void	parse_sphere(char **strs, t_obj **objs);
void	parse_plane(char **strs, t_obj **objs);
void	parse_cylinder(char **strs, t_obj **objs);

//------------------------- parse_get -------------------------
void	get_norm(char *str, t_vt *vec);
void	get_point(char *str, t_pt *point);
void	get_color(char *str, t_cl *color);

//------------------------- parse_check -------------------------
bool	check_split(char **strs, int cnt);
void	check_color(int r, int g, int b);
void	check_len(double len);
bool	check_range(double val, double min, double max);
void	check_scene_init(t_scene *scene);

//------------------------ parse_utils ------------------------
double	rt_atod(const char *str);
int		rt_atoi(const char *str);

#endif
