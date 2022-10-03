/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   d_list.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: silee <silee@student.42seoul.kr>		   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/05/09 19:45:02 by silee			 #+#	#+#			 */
/*   Updated: 2022/05/10 17:04:28 by silee			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(void)
{
	t_stack	*tmp_stack;

	tmp_stack = malloc(sizeof(t_stack));
	tmp_stack->noe = 0;
	return (tmp_stack);
}

void	d_push(t_stack *list, int value)
{
	t_node	*n_node;

	n_node = malloc(sizeof(t_node));
	n_node->data = value;
	if (list->noe == 0)
	{
		n_node->next = NULL;
		n_node->prev = NULL;
		list->head = n_node;
	}
	else
	{
		n_node->next = list->head;
		list->head->prev = n_node;
		n_node->prev = NULL;
		list->head = n_node;
	}
	list->noe += 1;
}

void	push_in_seq(t_stack *stack, int value)
{
	t_node	*n_node;
	t_node	*cur;

	n_node = malloc(sizeof(t_node));
	n_node->data = value;
	cur = stack->head;
	if (stack->noe == 0)
	{
		n_node->next = NULL;
		n_node->prev = NULL;
		stack->head = n_node;
	}
	else
	{
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = n_node;
		n_node->prev = cur;
		n_node->next = NULL;
	}
	stack->noe += 1;
}

int	d_pop(t_stack *stack)
{
	t_node	*tmp;
	t_node	*now;
	int		data;

	if (stack->noe == 0)
		exit(1);
	now = stack->head;
	data = now->data;
	tmp = now->next;
	if (stack->noe != 1)
		tmp->prev = NULL;
	stack->head = tmp;
	free (now);
	stack->noe -= 1;
	return (data);
}
