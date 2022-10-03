/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   make_hourglass.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: silee <silee@student.42seoul.kr>		   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/05/18 16:33:05 by silee			 #+#	#+#			 */
/*   Updated: 2022/05/19 17:56:30 by silee			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_init(t_stack *stack_a)
{
	if (stack_a->noe == 100)
		return (15);
	else if (stack_a->noe == 500)
		return (30);
	else
		return (0.000000053 * stack_a->noe * stack_a->noe + \
			0.03 * stack_a->noe + 14.5);
}

void	init_data(t_stack *stack_a, int *num, int *chunk, t_node **cur)
{
	*num = 0;
	*chunk = chunk_init(stack_a);
	*cur = stack_a->head;
}

void	make_hourglass(t_stack *stack_a, t_stack *stack_b)
{
	int		chunk;
	int		num;
	int		value;
	t_node	*cur;

	init_data(stack_a, &num, &chunk, &cur);
	while (stack_a->noe != 0)
	{
		value = cur->index;
		cur = cur->next;
		if (value <= num)
		{
			pb_command(stack_a, stack_b);
			num++;
		}
		else if (value > num && value <= num + chunk)
		{
			pb_command(stack_a, stack_b);
			rb_command(stack_b);
			num++;
		}
		else
			ra_command(stack_a);
	}
}

int	find_max_pos(t_stack *stack_b)
{
	t_node	*cur;
	int		pos;

	cur = stack_b->head;
	pos = 0;
	if (stack_b->noe <= 1)
		return (1);
	while (cur)
	{
		if (stack_b->noe - 1 == cur->index)
			return (pos);
		pos += 1;
		cur = cur->next;
	}
	write (1, "not found", 10);
	exit (1);
}

void	push_a_in_seq(t_stack *stack_a, t_stack *stack_b)
{
	int	pos;

	while (stack_b->noe > 0)
	{
		pos = find_max_pos (stack_b);
		if (stack_b->noe / 2 > pos)
		{
			while (pos--)
				rb_command (stack_b);
		}
		else
		{
			pos = stack_b->noe - pos;
			while (pos--)
				rrb_command (stack_b);
		}
		pa_command (stack_a, stack_b);
	}
}
