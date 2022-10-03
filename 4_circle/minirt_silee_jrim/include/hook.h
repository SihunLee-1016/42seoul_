/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:32:02 by silee             #+#    #+#             */
/*   Updated: 2022/09/24 10:32:02 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "structs.h"

# define COORD_X 0
# define COORD_Y 1
# define COORD_Z 2
# define SP_DIAM 3
# define CY_DIAM 4
# define CY_HEIGHT 5

//---------------------------- key ----------------------------
int		press_key(int key_num, t_minirt *info);
int		minirt_end(t_minirt *info);

//-------------------------- key_scene ------------------------
void	cam_rotate(t_minirt *info, int key_num);
void	cam_trans(t_minirt *info, int key_num);
void	light_trans(t_minirt *info, int key_num);

//--------------------------- key_obj -------------------------
void	sp_key(t_minirt *info, int key_num);
void	pl_key(t_minirt *info, int key_num);
void	cy_key(t_minirt *info, int key_num);
void	obj_size_key(t_minirt *info, int key_num);

//------------------------- transform -------------------------
void	sp_trans(t_obj *objs, int mode, double value);
void	pl_rotate(t_obj *objs, int mode, double value);
void	pl_trans(t_obj *objs, int mode, double value);
void	cy_rotate(t_obj *objs, int mode, double value);
void	cy_trans(t_obj *objs, int mode, double value);

#endif