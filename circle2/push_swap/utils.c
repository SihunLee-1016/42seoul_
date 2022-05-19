/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   utils.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: silee <silee@student.42seoul.kr>		   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/05/13 17:17:18 by silee			 #+#	#+#			 */
/*   Updated: 2022/05/13 17:18:03 by silee			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

void	make_stack_n_push(t_stack **stack_a, int argc, char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	*stack_a = stack_init();
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if ((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == '-')
			{
				push_in_seq (*stack_a, ft_atoi (&argv[i][j], &len));
				j = j + len - 1;
			}
			else if (ft_isspace(argv[i][j]) == 0)
			{
				write (1, "ERROR", 6);
				exit (1);
			}
			j++;
		}
		i++;
	}
}

int	*sort_input(t_stack *stack_a)
{
	t_node	*cur;
	int		*list;
	int		i;

	i = 0;
	cur = stack_a->head;
	list = malloc(sizeof(int) * stack_a->noe);
	if (list == 0)
		exit (1);
	while (i < stack_a->noe)
	{
		list[i] = cur->data;
		cur = cur->next;
		i++;
	}
	quick_sort (list, 0, stack_a->noe - 1);
	return (list);
}

void	indexing_data(t_stack *stack_a)
{
	int		*list;
	int		i;
	t_node	*cur;

	list = sort_input(stack_a);
	i = 0;
	while (i < stack_a->noe)
	{
		cur = stack_a->head;
		while (cur)
		{
			if (list[i] == cur->data)
			{
				cur->index = i;
				break ;
			}
			cur = cur->next;
		}
		i++;
	}
	free (list);
}
