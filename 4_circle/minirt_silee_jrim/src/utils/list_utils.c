/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:31:42 by silee             #+#    #+#             */
/*   Updated: 2022/09/24 10:31:42 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj	*obj_init(int type, void *element)
{
	t_obj	*new;

	new = (t_obj *)malloc(sizeof(t_obj));
	if (!new)
		err_exit("cannot allocate memory (obj)\n");
	new->type = type;
	new->data = element;
	new->next = NULL;
	return (new);
}

void	obj_add(t_obj **list, t_obj *new)
{
	t_obj	*cur;

	if (*list == NULL)
	{
		*list = new;
		return ;
	}
	cur = *list;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

void	obj_clean(t_obj *list)
{
	t_obj	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp->data);
		free(tmp);
		tmp = NULL;
	}
}
