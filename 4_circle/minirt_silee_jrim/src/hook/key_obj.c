/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:31:16 by silee             #+#    #+#             */
/*   Updated: 2022/09/24 10:31:17 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	sp_key(t_minirt *info, int key_num)
{
	if (key_num == K_Q)
		sp_trans(info->objs, COORD_X, 1);
	if (key_num == K_W)
		sp_trans(info->objs, COORD_X, -1);
	if (key_num == K_A)
		sp_trans(info->objs, COORD_Y, 1);
	if (key_num == K_S)
		sp_trans(info->objs, COORD_Y, -1);
	if (key_num == K_Z)
		sp_trans(info->objs, COORD_Z, 1);
	if (key_num == K_X)
		sp_trans(info->objs, COORD_Z, -1);
}

void	pl_key(t_minirt *info, int key_num)
{
	if (key_num == K_E)
		pl_rotate(info->objs, COORD_X, 0.1);
	if (key_num == K_R)
		pl_rotate(info->objs, COORD_X, -0.1);
	if (key_num == K_D)
		pl_rotate(info->objs, COORD_Y, 0.1);
	if (key_num == K_F)
		pl_rotate(info->objs, COORD_Y, -0.1);
	if (key_num == K_C)
		pl_rotate(info->objs, COORD_Z, 0.1);
	if (key_num == K_V)
		pl_rotate(info->objs, COORD_Z, -0.1);
	if (key_num == K_T)
		pl_trans(info->objs, COORD_X, 1);
	if (key_num == K_Y)
		pl_trans(info->objs, COORD_X, -1);
	if (key_num == K_G)
		pl_trans(info->objs, COORD_Y, 1);
	if (key_num == K_H)
		pl_trans(info->objs, COORD_Y, -1);
	if (key_num == K_B)
		pl_trans(info->objs, COORD_Z, 1);
	if (key_num == K_N)
		pl_trans(info->objs, COORD_Z, -1);
}

void	cy_key(t_minirt *info, int key_num)
{
	if (key_num == K_U)
		cy_rotate(info->objs, COORD_X, 0.1);
	if (key_num == K_I)
		cy_rotate(info->objs, COORD_X, -0.1);
	if (key_num == K_J)
		cy_rotate(info->objs, COORD_Y, 0.1);
	if (key_num == K_K)
		cy_rotate(info->objs, COORD_Y, -0.1);
	if (key_num == K_M)
		cy_rotate(info->objs, COORD_Z, 0.1);
	if (key_num == K_COMMA)
		cy_rotate(info->objs, COORD_Z, -0.1);
	if (key_num == K_O)
		cy_trans(info->objs, COORD_X, 1);
	if (key_num == K_P)
		cy_trans(info->objs, COORD_X, -1);
	if (key_num == K_L)
		cy_trans(info->objs, COORD_Y, 1);
	if (key_num == K_SEMI)
		cy_trans(info->objs, COORD_Y, -1);
	if (key_num == K_DOT)
		cy_trans(info->objs, COORD_Z, 1);
	if (key_num == K_SLASH)
		cy_trans(info->objs, COORD_Z, -1);
}

void	obj_size_key(t_minirt *info, int key_num)
{
	if (key_num == K_NP7)
		sp_trans(info->objs, SP_DIAM, 1);
	if (key_num == K_NP8)
		sp_trans(info->objs, SP_DIAM, -1);
	if (key_num == K_NP4)
		cy_trans(info->objs, CY_DIAM, 1);
	if (key_num == K_NP5)
		cy_trans(info->objs, CY_DIAM, -1);
	if (key_num == K_NP1)
		cy_trans(info->objs, CY_HEIGHT, 1);
	if (key_num == K_NP2)
		cy_trans(info->objs, CY_HEIGHT, -1);
}
