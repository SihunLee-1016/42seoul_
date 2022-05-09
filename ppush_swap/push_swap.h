/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:08:06 by silee             #+#    #+#             */
/*   Updated: 2022/05/09 20:08:09 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>

typedef struct s_node
{
	int				data;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

typedef struct s_stack
{
    int             noe;
	struct s_node	*top;
	struct s_node	*bottom;
}	t_stack;

typedef struct s_var
{
	int				max_size;
	int				*sorted_array;
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	struct s_list	*list;
	int				a_size;
	int				b_size;
}	t_data_list;






#endif
