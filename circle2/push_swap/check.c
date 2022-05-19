/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:35:51 by silee             #+#    #+#             */
/*   Updated: 2022/05/19 18:44:51 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dup(t_stack *stack_a)
{
	t_node	*o_cur;
	t_node	*i_cur;

	o_cur = stack_a->head;
	while (o_cur)
	{
		i_cur = stack_a->head;
		while (i_cur)
		{
			if (o_cur != i_cur)
			{
				if (o_cur->data == i_cur->data)
				{
					write (1, "ERROR in checkdup", 18);
					exit (1);
				}
			}
			i_cur = i_cur->next;
		}
		o_cur = o_cur->next;
	}
}

void	check_already_sort(t_stack *stack_a)
{
	t_node	*now;
	int		rot;
	int		cnt;

	now = stack_a->head;
	rot = stack_a->noe - 1;
	cnt = 0;
	while (rot-- > 0)
	{
		if (now->index == now->next->index - 1)
			cnt++;
		now = now->next;
	}
	if (cnt == stack_a->noe - 1)
	{
		write (1, "already sorted", 15);
		exit (1);
	}
}