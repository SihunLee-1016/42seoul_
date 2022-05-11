/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:08:06 by silee             #+#    #+#             */
/*   Updated: 2022/05/11 13:54:00 by silee            ###   ########.fr       */
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
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
    int             noe;
	struct s_node	*head;
}	t_stack;

void	check_duplicated(int argc, int *nums);
int *make_sorted_array(int argc, char **argv);

void	make_stack_n_push(t_stack **stack_a, int argc, char **argv);
void	insert(t_stack *list, int value);
t_stack *stack_init (void);
t_node  *make_node(int value);
void	see_value_f(t_stack *stack);
void	see_value_s(t_stack *stack);

void	is_valid(char *str);
int	ft_isspace(char sstr);
static int	ft_check_flow(long long num, int c, int minus);
int	ft_atoi(char *str, int *len);
void	check_valid(char str);

int	*make_num_list(t_stack *stack_a);

void	quick_sort(int dataset[], int left, int right);
int	partition(int dataset[], int left, int right);
void	swap(int *a, int *b);



#endif
