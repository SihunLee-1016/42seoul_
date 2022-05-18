/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_hourglass.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:33:05 by silee             #+#    #+#             */
/*   Updated: 2022/05/18 21:49:45 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int chunk_init(t_stack *stack_a)
{
    if (stack_a->noe == 100)
        return (15);
    else if (stack_a->noe == 500)
        return (30);
    else
        return (4);
}

void    init_data(t_stack *stack_a,int *num, int *rotate, int *chunk, t_node **cur)
{
	*num = 0;
	*rotate = stack_a->noe;
	*chunk = chunk_init(stack_a);
	*cur = stack_a->head;
}

void    make_hourglass(t_stack *stack_a, t_stack *stack_b)
{
    int chunk;
    int num;
    int value;
    int rotate;
    t_node *cur;

	init_data(stack_a, &num, &rotate, &chunk, &cur);
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
        // else if (num + chunk < value)
        else
            ra_command(stack_a);
    }
}
