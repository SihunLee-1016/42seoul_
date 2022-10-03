/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:32:14 by silee             #+#    #+#             */
/*   Updated: 2022/09/24 10:32:14 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structs.h"

//--------------------------- init ----------------------------
void	camera_init(t_cam *camera);
void	info_init(t_minirt *info);

//--------------------------- utils ---------------------------
void	err_exit(char *msg);
void	free_all(char **strs);

//------------------------- str_utils -------------------------
int		rt_strcmp(const char *s1, const char *s2);
int		rt_strlen(const char *s);
char	**rt_split(char const *s, char c);

//------------------------- list_utils ------------------------
t_obj	*obj_init(int type, void *element);
void	obj_add(t_obj **list, t_obj *new);
void	obj_clean(t_obj *list);

//------------------------ vec_utils_1 ------------------------
t_vt	vec3(double x, double y, double z);
t_pt	point3(double x, double y, double z);
t_cl	color3(double r, double g, double b);

//------------------------ vec_utils_2 ------------------------
t_vt	vplus(t_vt vec, t_vt vec2);
t_vt	vplus_(t_vt vec, double x, double y, double z);
t_vt	vminus(t_vt vec, t_vt vec2);
t_vt	vminus_(t_vt vec, double x, double y, double z);

//------------------------ vec_utils_3 ------------------------
t_vt	vmult(t_vt vec, double t);
t_vt	vmult_(t_vt vec, t_vt vec2);
t_vt	vdivide(t_vt vec, double t);
t_vt	vmin(t_vt vec1, t_vt vec2);

//------------------------ vec_utils_4 ------------------------
double	vdot(t_vt vec, t_vt vec2);
t_vt	vcross(t_vt vec, t_vt vec2);
t_vt	vunit(t_vt vec);
double	vlength2(t_vt vec);
double	vlength(t_vt vec);

//----------------------- unnecessary ---------------------------
// 중간중간에 뭐 확인해볼 때 사용하려고 만들었어요. 나중에 지울거임.
void	print_vt(t_vt vec);
void	print_pt(t_pt point);
void	print_cl(t_cl color);
void	print_amb(t_amb amb);
void	print_cam(t_cam cam);
void	print_light(t_light light);
void	print_sp(t_sp *sp);
void	print_pl(t_pl *pl);
void	print_cy(t_cy *cy);
void	print_obj(t_obj *objs);

#endif