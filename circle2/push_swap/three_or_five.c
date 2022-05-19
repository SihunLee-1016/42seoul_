/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   three_or_five.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: silee <silee@student.42seoul.kr>		   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/05/19 18:54:56 by silee			 #+#	#+#			 */
/*   Updated: 2022/05/19 20:24:00 by silee			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

void	in_case_of_three(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->head->index;
	second = stack_a->head->next->index;
	third = stack_a->head->next->next->index;
	if (first - second == -2 && second - third == 1)
	{
		sa_command(stack_a);
		ra_command(stack_a);
	}
	else if (first - second == 1 && second - third == -2)
		sa_command(stack_a);
	else if (first - second == -1 && second - third == 2)
		rra_command(stack_a);
	else if (first - second == 2 && second - third == -1)
		ra_command(stack_a);
	else if (first - second == 1 && second - third == 1)
	{
		ra_command(stack_a);
		sa_command(stack_a);
	}
}

int	find_min_pos(t_stack *stack_a)
{
	t_node	*cur;
	int		pos;

	cur = stack_a->head;
	pos = 0;
	while (cur)
	{
		if (cur->index <= 1)
			return (pos);
		pos += 1;
		cur = cur->next;
	}
	return (-1);
}

void	sort_anb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*now_b;

	now_b = stack_b->head;
	in_case_of_three(stack_a);
	if (now_b->data < now_b->next->data)
		sb_command(stack_b);
	while (stack_b->noe > 0)
		pa_command(stack_a, stack_b);
}

void	in_case_of_five(t_stack *stack_a, t_stack *stack_b)
{
	int		pos;
	t_node	*cur;

	cur = stack_a->head;
	while (stack_a->noe > 3)
	{
		pos = find_min_pos(stack_a);
		if (stack_a->noe / 2 > pos)
		{
			while (pos--)
				ra_command(stack_a);
		}
		else
		{
			pos = stack_a->noe - pos;
			while (pos--)
				rra_command(stack_a);
		}
		pb_command(stack_a, stack_b);
	}
	sort_anb(stack_a, stack_b);
}

void	three_or_five(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->noe == 3)
		in_case_of_three(stack_a);
	else if (stack_a->noe == 5)
		in_case_of_five(stack_a, stack_b);
}		

// void	ft_lstclear(t_list **lst, void (*del)(void *))
// {
// 	t_list	*curr;
// 	t_list	*next;
// 	curr = *lst;
// 	if (lst == 0 || del == 0)
// 		return ;
// 	while (curr != 0)
// 	{
// 		next = curr->next;
// 		del(curr->content);
// 		free (curr);
// 		curr = next;
// 	}
// 	*lst = 0;
// }
