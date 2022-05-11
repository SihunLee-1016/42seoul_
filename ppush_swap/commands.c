/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihunlee <sihunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:55:51 by silee             #+#    #+#             */
/*   Updated: 2022/05/11 22:53:26 by sihunlee         ###   ########.fr       */
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

void	rb_command(t_stack *stack_b)
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
	//마지막 노드로 접근.
	while (now->next != NULL)
		now = now->next;
	//마지막 노드의 data만 추출.
	l_data = now->data;
	//마지막 노드의 이전노드의 next를 null로 초기화.
	now->prev->next = NULL;
	// free.
	free(now);
	//bottom의 data를 새로운 노드에 할당해 맨 앞에 추가.
	new_head = malloc(sizeof(t_node));
	//값을 넣어주고
	new_head->data = l_data;
	//첫 노드가 될 것이니 이전을 가르키는건 없도록
	new_head->prev = NULL;
	//첫노드이므로 가르키는건 기존 첫번 째 노드.
	new_head->next = stack_a->head;
	stack_a->head->prev = new_head;
	stack_a->head = new_head;
}

void	rrb_command(t_stack *stack_b)
{
	int		l_data;
	t_node *now;
	t_node	*new_head;

	now = stack_b->head;
	//마지막 노드로 접근.
	while (now->next != NULL)
		now = now->next;
	//마지막 노드의 data만 추출.
	l_data = now->data;
	//마지막 노드의 이전노드의 next를 null로 초기화.
	now->prev->next = NULL;
	// free.
	free(now);
	//bottom의 data를 새로운 노드에 할당해 맨 앞에 추가.
	new_head = malloc(sizeof(t_node));
	//값을 넣어주고
	new_head->data = l_data;
	//첫 노드가 될 것이니 이전을 가르키는건 없도록
	new_head->prev = NULL;
	//첫노드이므로 가르키는건 기존 첫번 째 노드.
	new_head->next = stack_b->head;
	stack_b->head->prev = new_head;
	stack_b->head = new_head;
}
