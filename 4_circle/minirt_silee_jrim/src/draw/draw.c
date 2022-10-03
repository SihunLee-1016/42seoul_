/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:31:07 by silee             #+#    #+#             */
/*   Updated: 2022/09/24 10:31:07 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	pixel_put(t_minirt *minirt, int x, int y, t_cl cl)
{
	char			*img_addr;
	unsigned int	color_hex;
	int				red;
	int				green;
	int				blue;

	red = (int)(cl.x * 255);
	green = (int)(cl.y * 255);
	blue = (int)(cl.z * 255);
	color_hex = ((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff);
	y = HEI - y;
	img_addr = &minirt->mlx.addr[(y * minirt->mlx.size_line + x * \
		(minirt->mlx.bpp / 8))];
	*(unsigned int *)img_addr = color_hex;
}

t_cl	obj_color(t_minirt *minirt, t_hit *rec)
{
	if (hit_check(minirt, &minirt->scene.ray, rec))
		return (lighting(minirt, rec));
	return (color3(0, 0, 0));
}

void	draw_img(t_minirt *minirt)
{
	int		i;
	int		j;
	double	u;
	double	v;
	t_hit	rec;

	camera_init(&minirt->scene.cam);
	i = -1;
	while (++i < WID)
	{
		j = -1;
		while (++j < HEI)
		{
			u = (double)i / (WID - 1);
			v = (double)j / (HEI - 1);
			rec.t_max = 10000;
			rec.t_min = EPSILON;
			minirt->scene.ray = make_ray(&minirt->scene.cam, u, v);
			pixel_put(minirt, i, HEI - j - 1, obj_color(minirt, &rec));
		}
	}
}
