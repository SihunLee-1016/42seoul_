/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:55:51 by silee             #+#    #+#             */
/*   Updated: 2022/05/11 17:31:06 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//B 2 A
void    pa_command(t_stack *stack_a, t_stack *stack_b)
{
	int	b_data;
	
	b_data = d_pop(stack_b);
	d_push(stack_a, b_data);
}
// A 2 B
void    pb_command(t_stack *stack_a, t_stack *stack_b)
{
    int a_data;

	a_data = d_pop(stack_a);
	d_push(stack_b, a_data);
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

void	ra_command(t_stack *stack_a)
{
	int		f_data;
	t_node *n_node;
	t_node	*now;

	f_data = d_pop(stack_a);
	now = stack_a->head;
	while (now->next != NULL)
		now = now->next;
	n_node = malloc(sizeof(t_node));
	
	now->next = n_node;
	n_node->data = f_data;
	n_node->prev = now;
	n_node->next = NULL;
}

void	rb_command(t_stack *stack_a)
{	
	int		f_data;
	t_node *n_node;
	t_node	*now;

	f_data = d_pop(stack_b);
	now = stack_b->head;
	while (now->next != NULL)
		now = now->next;
	n_node = malloc(sizeof(t_node));
	
	now->next = n_node;
	n_node->data = f_data;
	n_node->prev = now;
	n_node->next = NULL;
}

void	rra_command(t_stack *stack_a)
{
	int		l_data;
	t_node *now;
	t_node	*new_head;

	now = stack_a->head;
	while (now->next != NULL)
		now = now->next;
	l_data = now->data;
	now->prev->next = NULL;
	now->prev = NULL;
	free(now);
	new_head = malloc(sizeof(t_node));
	new_head->data = l_data;
	new_head->prev = NULL;
	new_head->next = stack_a->head;
	
}

void	rrb_command(t_stack *stack_a)
{

}
