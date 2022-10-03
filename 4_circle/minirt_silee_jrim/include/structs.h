/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:32:11 by silee             #+#    #+#             */
/*   Updated: 2022/09/24 10:32:11 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>
# include <stdlib.h>

//----------------------------------------------
typedef struct s_coord3	t_vt;
typedef struct s_coord3	t_pt;
typedef struct s_coord3	t_cl;

struct s_coord3
{
	double		x;
	double		y;
	double		z;
};

//----------------------------------------------
typedef struct s_cnvs
{
	int			w;
	int			h;
	double		aspect_ratio;
}				t_cnvs;

typedef struct s_cam
{
	t_pt		orig;
	t_vt		dir;
	int			fov;
	t_vt		ver;
	t_vt		hor;
	double		focal_len;
	double		vp_w;
	double		vp_h;
	t_pt		l_bot;
	bool		init;
}				t_cam;

typedef struct s_light
{
	t_pt		orig;
	t_cl		color;
	double		bright_ratio;
	bool		init;
}				t_light;

typedef struct s_amb
{
	t_cl		color;
	double		ratio;
	bool		init;
}				t_amb;

typedef struct s_ray
{
	t_pt		orig;
	t_vt		dir;
}				t_ray;

typedef struct s_scene
{
	t_cnvs		cnvs;
	t_cam		cam;
	t_light		light;
	t_amb		amb;
	t_ray		ray;
}				t_scene;

//----------------------------------------------
typedef struct s_hit
{
	t_pt		p;
	t_vt		norm;
	double		t;
	double		t_min;
	double		t_max;
	bool		front_face;
	t_cl		albedo;
}				t_hit;

//----------------------------------------------
typedef struct s_cy
{
	t_cl		color;
	t_pt		point;
	t_vt		norm;
	double		height;
	double		diameter;
	double		radius;
	t_pt		cap_top;
	t_pt		cap_bot;
}				t_cy;

typedef struct s_pl
{
	t_cl		color;
	t_pt		point;
	t_vt		norm;
}				t_pl;

typedef struct s_sp
{
	t_cl		color;
	t_pt		center;
	double		diam;
}				t_sp;

typedef struct s_obj
{
	void		*data;
	int			type;
	void		*next;
}				t_obj;

//----------------------------------------------
typedef struct s_hook
{
	size_t		mode;
	int			sp_index;
	int			pl_index;
	int			cy_index;
}				t_hook;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
}				t_mlx;

typedef struct s_minirt
{
	t_mlx		mlx;
	t_hook		hook;
	t_scene		scene;
	t_obj		*objs;
}				t_minirt;

//----------------------------------------------
typedef struct s_hit_sp
{
	double		a;
	double		half_b;
	double		c;
	double		disc;
	double		sqrtd;
	double		root;
}				t_hit_sp;

typedef struct s_hit_cy
{
	double		a;
	double		b;
	double		c;
	double		disc;
}				t_hit_cy;

//----------------------------------------------
typedef struct s_phong_light
{
	t_cl		diffuse;
	t_cl		specular;
	t_cl		d_plus_s;
	t_vt		light_dir;
	t_vt		view_dir;
	t_vt		reflect_dir;
	t_ray		light_ray;
	double		light_len;
	double		kd;
	double		spec;
	double		ksn;
	double		ks;
}				t_phong_light;

#endif
