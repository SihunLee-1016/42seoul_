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

void	pa_command(t_stack *stack_a, t_stack *stack_b, int *cmd_pa)
{
	int	b_data;

	b_data = d_pop(stack_b);
	d_push(stack_a, b_data);
	*cmd_pa += 1;
}

void	pb_command(t_stack *stack_a, t_stack *stack_b, int *cmd_pb)
{
	int	a_data;

	a_data = d_pop(stack_a);
	d_push(stack_b, a_data);
	*cmd_pb +=1 ;
}

void	sa_command(t_stack *stack_a)
{
	int	f_data;
	int	s_data;

	f_data = stack_a->head->data;
	s_data = stack_a->head->next->data;
	stack_a->head->data = s_data;
	stack_a->head->next->data = f_data;
}

void	sb_command(t_stack *stack_b)
{
	int	f_data;
	int	s_data;

	f_data = stack_b->head->data;
	s_data = stack_b->head->next->data;
	stack_b->head->data = s_data;
	stack_b->head->next->data = f_data;
}
