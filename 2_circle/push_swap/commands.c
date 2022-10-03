/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   commands.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: sihunlee <sihunlee@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/05/11 15:55:51 by silee			 #+#	#+#			 */
/*   Updated: 2022/05/11 22:53:26 by sihunlee		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

void	pa_command(t_stack *stack_a, t_stack *stack_b)
{
	int	b_data;
	int	idx;

	idx = stack_b->head->index;
	b_data = d_pop(stack_b);
	d_push(stack_a, b_data);
	stack_a->head->index = idx;
	write (1, "pa\n", 3);
}

void	pb_command(t_stack *stack_a, t_stack *stack_b)
{
	int	a_data;
	int	idx;

	idx = stack_a->head->index;
	a_data = d_pop(stack_a);
	d_push(stack_b, a_data);
	stack_b->head->index = idx;
	write (1, "pb\n", 3);
}

void	sa_command(t_stack *stack_a)
{
	int	f_data;
	int	s_data;

	f_data = stack_a->head->data;
	s_data = stack_a->head->next->data;
	stack_a->head->data = s_data;
	stack_a->head->next->data = f_data;
	write (1, "sa\n", 3);
}

void	sb_command(t_stack *stack_b)
{
	int	f_data;
	int	s_data;

	f_data = stack_b->head->data;
	s_data = stack_b->head->next->data;
	stack_b->head->data = s_data;
	stack_b->head->next->data = f_data;
	write (1, "sb\n", 3);
}
