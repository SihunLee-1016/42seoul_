/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_hourglass.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:33:05 by silee             #+#    #+#             */
/*   Updated: 2022/05/18 17:14:24 by silee            ###   ########.fr       */
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
        return (-1);
}

void    make_hourglass(t_stack *stack_a, t_stack *stack_b)
{
    int chunk;
    int num;
    int i;
    int value;
    t_node *cur;

    i = -1;
    num = 0;
    chunk = chunk_init(stack_a);
    cur = stack_a->head;
    //3개, 혹은 5개일땐 직접 처리
    if (chunk == -1)
        chunk = 2;
    // 100개이상인 경우
    while (++i < stack_a->noe && cur)
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
        else if (num + chunk < value)
            ra_command(stack_a);
    }
}