/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:51:17 by silee             #+#    #+#             */
/*   Updated: 2022/05/26 12:17:18 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_or_five(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->noe == 2)
	{
		if (stack_a->head->data > stack_a->head->next->data)
			sa_command(stack_a);
		exit (1);
	}
	else if (stack_a->noe == 3)
		in_case_of_three(stack_a);
	else if (stack_a-> noe == 4)
		in_case_of_four(stack_a, stack_b);
	else if (stack_a->noe == 5)
		in_case_of_five(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = stack_init();
	make_stack_n_push (stack_a, argc, argv);
	if (stack_a->noe == 1)
		exit (1);
	check_dup (stack_a);
	stack_b = stack_init();
	indexing_data (stack_a);
	check_already_sort(stack_a);
	if (stack_a->noe <= 5)
		three_or_five(stack_a, stack_b);
	else
	{
		make_hourglass (stack_a, stack_b);
		push_a_in_seq (stack_a, stack_b);
	}
}
