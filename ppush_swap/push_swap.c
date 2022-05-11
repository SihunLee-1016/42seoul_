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

void	check_duplicated(int noe, int *nums)
{
	int	check_idx;
	int	rotate_idx;

	check_idx = 0;
	while (check_idx < noe)
	{
		rotate_idx = 0;
		while (rotate_idx < noe)
		{
			if (nums[check_idx] == nums[rotate_idx])
			{
				if (check_idx != rotate_idx)
				{
					write (1, "ERROR", 6);
					exit (1);
				}
			}
			rotate_idx +=1 ;
		}
		check_idx += 1;
	}
}
	
int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int		*nums;

	make_stack_n_push(&stack_a, argc, argv);
	stack_b = stack_init();
	nums = make_num_list(stack_a);
	
	int i = 0;
	while (i < stack_a->noe)
	{
		printf("%d ",nums[i]);
		i++;
	}
	i = 0;
	int j;
	int poped_value;
	int out = stack_a->noe;
	printf("\nbf sa\n");
	see_value_s(stack_a);
	ra_command(stack_a);
	printf("\naf sa\n");
	see_value_s(stack_a);
	// while (i < out)
	// {
	// 	poped_value = d_pop(stack_a);
	// 	printf("\npoped value = %d\n", poped_value);
	// 	printf("left stack\n");
	// 	see_value_s(stack_a);
	// 	i++;
	// }

}


// typedef struct s_node
// {
// 	int				data;
// 	struct s_node	*next;
// 	struct s_node	*prev;
// }	t_node;

// typedef struct s_stack
// {
//	 int			 noe;
// 	struct s_node	*head;
// }	t_stack;