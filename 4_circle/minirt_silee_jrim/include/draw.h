/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:31:59 by silee             #+#    #+#             */
/*   Updated: 2022/09/24 10:31:59 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "structs.h"

//----------------------------- draw -----------------------------
void	pixel_put(t_minirt *minirt, int x, int y, t_cl cl);
t_cl	obj_color(t_minirt *minirt, t_hit *rec);
void	draw_img(t_minirt *minirt);

//-------------------------- draw_utils --------------------------
t_ray	make_ray(t_cam *cam, double u, double v);
t_pt	ray_at(t_ray *ray, double t);
void	set_face_normal(t_ray *ray, t_hit *rec);
t_ray	ray(t_pt orig, t_vt dir);
t_vt	cyl_norm(t_cy *cyl, t_vt at);

//------------------------------ hit ------------------------------
bool	hit_sp(t_sp *sp, t_ray *ray, t_hit *rec);
bool	hit_pl(t_pl *pl, t_ray *ray, t_hit *rec);
bool	hit_cy(t_cy *cy, t_ray *ray, t_hit *rec);
bool	obj_type_check(t_obj *obj, t_ray *ray, t_hit *rec);
bool	hit_check(t_minirt *minirt, t_ray *ray, t_hit *rec);

//--------------------------- hit_cylinder ---------------------------
bool	hit_cylinder_side(t_cy *cyl, t_ray *ray, t_hit *rec);
bool	cyl_side_root(t_cy *cyl, t_ray *ray, t_hit *rec, double *root);
bool	cyl_boundary(t_cy *cyl, t_vt at);
bool	hit_cylinder_cap(t_cy *cyl, t_ray *ray, t_hit *rec, int mode);
bool	cyl_cap_root(t_cy *cyl, t_ray *ray, t_hit *rec, double *root);

//---------------------------- phong -----------------------------
int		in_shadow(t_minirt *minirt, t_ray *ray, t_hit *rec, double light_len);
t_vt	reflect(t_vt v, t_vt n);
t_cl	lighting(t_minirt *minirt, t_hit *rec);

#endif
