/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   push_swap.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: silee <silee@student.42seoul.kr>		   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/05/07 16:51:28 by silee			 #+#	#+#			 */
/*   Updated: 2022/05/11 13:21:05 by silee			###   ########.fr	   */
/*																			*/
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

void	set_cmd_a(t_cmd_a *cmd_a, t_stack *stack_a, int *rot)
{
	cmd_a->pb = 0;
	cmd_a->ra = 0;
	cmd_a->rra = 0;
	cmd_a->pivot_a = find_middle_pivot(stack_a);
	*rot = stack_a->noe;
}

void	set_cmd_b(t_cmd_b *cmd_b, t_stack *stack_b, int *rot)
{
	cmd_b->rb = 0;
	cmd_b->pa = 0;
	cmd_b->rrb = 0;
	cmd_b->pivot_b = find_middle_pivot(stack_b);
	*rot = stack_b->noe;
}

void	atob(t_stack *stack_a, t_stack *stack_b)
{
	//무조건 원소의 개수는 5개 이상인 경우에만.
	int		i;
	int		rotate;
	int		value;
	t_node	*now;
	t_cmd_a	cmd_a;

	if (stack_a->noe == 1)
		return ;
	set_cmd_a(&cmd_a, stack_a, &rotate);
	now = stack_a->head;
	i = -1;
	while (++i < rotate)
	{
		value = now->data;
		now = now->next;
		if (value > cmd_a.pivot_a && stack_a->noe != 1)
			ra_command(stack_a, &cmd_a.ra);
		else if (value <= cmd_a.pivot_a)
			pb_command(stack_a, stack_b, &cmd_a.pb);
	} 
}

	// i = -1;
	// while (++i < cmd_a.ra)
	// 	rra_command(stack_a);
	// i = -1;
	//  while (++i < cmd_a.ra)
	// 	atob(stack_a, stack_b);	
	// i = -1;
	// while (++i < cmd_a.pb)
	// 	btoa(stack_a,stack_b);
void	btoa(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		rotate;
	t_node	*now;
	t_cmd_b	cmd_b;

	if (stack_b->noe <= 2)
		return ;
	set_cmd_b(&cmd_b, stack_b, &rotate);
	now = stack_b->head;
	printf("pivot b = %d\n",cmd_b.pivot_b);
	i = -1;
	while (++i < rotate && stack_b->noe >= 5)
	{
		if (now->data > cmd_b.pivot_b && stack_b->noe != 1)
		{
			now = now->next;
			rb_command(stack_b, &cmd_b.rb);
		}
		else if (now->data <= cmd_b.pivot_b)
		{
			now = now->next;
			pa_command(stack_a, stack_b, &cmd_b.pa);
		}
	}
	i = -1;
	while (++i < cmd_b.rb && stack_b->noe >= 2)
		rrb_command(stack_a);

	i = -1;
	while (++i < cmd_b.rb)
		atob(stack_a, stack_b);	
	
	i = -1;
	while (++i < cmd_b.pa)
		btoa(stack_a, stack_b);

}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	make_stack_n_push(&stack_a, argc, argv);
	stack_b = stack_init();
	//중복검사
	check_dup(stack_a);
	atob(stack_a, stack_b);
	printf ("stack a :");
	see_value_s(stack_a);
	printf ("stack b :");
	see_value_s(stack_b);
}