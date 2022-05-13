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

t_node	*make_node(int value)
{
	t_node	*n_node;

	n_node = (t_node *)malloc(sizeof(t_node));
	n_node->prev = NULL;
	n_node->next = NULL;
	n_node->data = value;
	return (n_node);
}

t_stack	*stack_init(void)
{
	t_stack	*tmp_stack;
	t_node	*tmp_node;

	tmp_stack = malloc(sizeof(t_stack));
	tmp_node = malloc(sizeof(t_node));
	tmp_node->data = 0;
	tmp_node->next = NULL;
	tmp_node->prev = NULL;
	tmp_stack->head = tmp_node;
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

int	d_pop(t_stack *stack)
{
	t_node	*tmp;
	t_node	*now;
	int		data;

	if (stack->noe == 0)
	{
		printf("no more elements in stack\n");
		exit(1);
	}
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
