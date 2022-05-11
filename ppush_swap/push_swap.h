/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihunlee <sihunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:08:06 by silee             #+#    #+#             */
/*   Updated: 2022/05/11 22:27:13 by sihunlee         ###   ########.fr       */
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
void	d_push	(t_stack *list, int value);
t_stack *stack_init (void);
t_node  *make_node(int value);
void	see_value_f(t_stack *stack);
void	see_value_s(t_stack *stack);
int	d_pop (t_stack *stack);


void	is_valid(char *str);
int	ft_isspace(char sstr);
static int	ft_check_flow(long long num, int c, int minus);
int	ft_atoi(char *str, int *len);
void	check_valid(char str);

int	*make_num_list(t_stack *stack_a);

void	quick_sort(int dataset[], int left, int right);
int	partition(int dataset[], int left, int right);
void	swap(int *a, int *b);
void	check_duplicated(int argc, int *nums);

void    pb_command(t_stack *stack_a, t_stack *stack_b);
void    pa_command(t_stack *stack_a, t_stack *stack_b);
void	sa_command(t_stack *stack_a);
void	sb_command(t_stack *stack_b);
void	ra_command(t_stack *stack_a);
void	rb_command(t_stack *stack_b);
void	rra_command(t_stack *stack_a);
void	rrb_command(t_stack *stack_b);


#endif
