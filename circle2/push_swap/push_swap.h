/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   push_swap.h										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: silee <silee@student.42seoul.kr>		   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/05/09 20:08:06 by silee			 #+#	#+#			 */
/*   Updated: 2022/05/19 20:57:36 by silee			###   ########.fr	   */
/*																			*/
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
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int				noe;
	struct s_node	*head;
}	t_stack;

//=================d_list.c===================
t_stack	*stack_init(void);
void	d_push(t_stack *list, int value);
void	push_in_seq(t_stack *stack, int value);
int		d_pop(t_stack *stack);

//=================ft_atoi.c==================
void	is_valid(char *str);
int		ft_isspace(char sstr);
int		ft_check_flow(long long num, int c, int minus);
int		ft_atoi(char *str, int *len);
void	check_valid(char str);

//=================utils.c===================
void	make_stack_n_push(t_stack **stack_a, int argc, char **argv);
int		*sort_input(t_stack *stack_a);
void	indexing_data(t_stack *stack_a);

//=================quick_sort.c===================
void	quick_sort(int dataset[], int left, int right);
int		partition(int dataset[], int left, int right);
void	swap(int *a, int *b);

////=================commands.c===================
void	pb_command(t_stack *stack_a, t_stack *stack_b);
void	pa_command(t_stack *stack_a, t_stack *stack_b);
void	sa_command(t_stack *stack_a);
void	sb_command(t_stack *stack_b);

//=================r_commands.c===================
void	ra_command(t_stack *stack_a);
void	rb_command(t_stack *stack_b);
void	rra_command(t_stack *stack_a);
void	rrb_command(t_stack *stack_b);

//=================check.c===================
void	check_dup(t_stack *stack_a);
void	check_already_sort(t_stack *stack_a);

//=================make_hourglass_n_return.c===================
int		chunk_init(t_stack *stack_a);
void	init_data(t_stack *stack_a, int *num, int *chunk, t_node **cur);
void	make_hourglass(t_stack *stack_a, t_stack *stack_b);
int		find_max_pos(t_stack *stack_b);
void	push_a_in_seq(t_stack *stack_a, t_stack *stack_b);

//=================three_or_five.c===================
void	in_case_of_three(t_stack *stack_a);
void	in_case_of_five(t_stack *stack_a, t_stack *stack_b);
void	three_or_five(t_stack *stack_a, t_stack *stack_b);
void	sort_anb(t_stack *stack_a, t_stack *stack_b);
#endif
