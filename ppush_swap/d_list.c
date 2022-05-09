/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:45:02 by silee             #+#    #+#             */
/*   Updated: 2022/05/09 20:26:13 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// typedef struct s_node
// {
// 	int				data;
// 	struct s_node	*left;
// 	struct s_node	*right;
// }	t_node;

// typedef struct s_stack
// {
// 	struct s_node	*top;
// 	struct s_node	*bottom;
// }	t_stack;

// typedef struct s_var
// {
// 	int				max_size;
// 	int				*sorted_array;
// 	struct s_stack	*stack_a;
// 	struct s_stack	*stack_b;
// 	struct s_list	*list;
// 	int				a_size;
// 	int				b_size;
// }	t_data_list;

t_stack stack_init (void)
{
    t_stack *tmp_stack;
    t_node  *tmp_node;

    tmp_stack = malloc(sizeof(t_stack));
    tmp_node = malloc(sizeof(t_node));

    tmp_node->data = 0;
    tmp_node->left = NULL;
    tmp_node->right = NULL;
    tmp_stack->top = tmp_node;
    tmp_stack->noe = 0;
    return (tmp_stack);
}

t_node  make_node(int value)
{
    t_node  n_node;

    n_node = (t_node *)malloc(sizeof(t_node));
    n_node->left = NULL:
    n_node->right = NULL;
    n_node->data = value;
    return (n_node);
}