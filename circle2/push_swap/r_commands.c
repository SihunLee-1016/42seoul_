/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   r_commands.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: silee <silee@student.42seoul.kr>		   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/05/13 17:12:36 by silee			 #+#	#+#			 */
/*   Updated: 2022/05/13 17:14:32 by silee			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

void	ra_command(t_stack *stack_a)
{
	int		f_data;
	int		f_idx;
	t_node	*n_node;
	t_node	*now;

	if (stack_a->noe == 1)
		return ;
	f_idx = stack_a->head->index;
	f_data = d_pop(stack_a);
	stack_a->noe += 1;
	now = stack_a->head;
	while (now->next != NULL)
		now = now->next;
	n_node = malloc(sizeof(t_node));
	now->next = n_node;
	n_node->data = f_data;
	n_node->prev = now;
	n_node->index = f_idx;
	n_node->next = NULL;
	write(1, "ra\n", 3);
}

void	rb_command(t_stack *stack_b)
{
	int		f_data;
	int		f_idx;
	t_node	*n_node;
	t_node	*now;

	if (stack_b->noe == 1)
		return ;
	f_idx = stack_b->head->index;
	f_data = d_pop(stack_b);
	stack_b->noe += 1;
	now = stack_b->head;
	while (now->next != NULL)
		now = now->next;
	n_node = malloc(sizeof(t_node));
	now->next = n_node;
	n_node->data = f_data;
	n_node->prev = now;
	n_node->index = f_idx;
	n_node->next = NULL;
	write(1, "rb\n", 3);
}

void	rra_command(t_stack *stack_a)
{
	int		l_data;
	int		l_idx;
	t_node	*now;
	t_node	*new_head;

	if (stack_a->noe == 2)
	{
		sa_command(stack_a);
		return ;
	}
	now = stack_a->head;
	while (now->next != NULL)
		now = now->next;
	l_data = now->data;
	l_idx = now->index;
	now->prev->next = NULL;
	free(now);
	new_head = malloc(sizeof(t_node));
	new_head->data = l_data;
	new_head->index = l_idx;
	new_head->prev = NULL;
	new_head->next = stack_a->head;
	stack_a->head->prev = new_head;
	stack_a->head = new_head;
	write(1, "rra\n", 4);
}

void	rrb_command(t_stack *stack_b)
{
	int		l_data;
	int		l_idx;
	t_node	*now;
	t_node	*new_head;

	now = stack_b->head;
	while (now->next != NULL)
		now = now->next;
	l_data = now->data;
	l_idx = now->index;
	now->prev->next = NULL;
	free(now);
	new_head = malloc(sizeof(t_node));
	new_head->data = l_data;
	new_head->index = l_idx;
	new_head->prev = NULL;
	new_head->next = stack_b->head;
	stack_b->head->prev = new_head;
	stack_b->head = new_head;
	write(1, "rrb\n", 4);
}
