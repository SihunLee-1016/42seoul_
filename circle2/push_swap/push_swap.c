/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:51:17 by silee             #+#    #+#             */
/*   Updated: 2022/05/19 21:04:00 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 2)
		exit (1);
	make_stack_n_push (&stack_a, argc, argv);
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
