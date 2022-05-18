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

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	make_stack_n_push(&stack_a, argc, argv);
	stack_b = stack_init();
	check_dup(stack_a);
    indexing_data(stack_a);

    make_hourglass(stack_a, stack_b);
    
    printf("stack a\n");
    see_value_s(stack_a);
    printf("stack b\n");
    see_value_s(stack_b);
}