/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   d_list.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: silee <silee@student.42seoul.kr>		   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/05/09 19:45:02 by silee			 #+#	#+#			 */
/*   Updated: 2022/05/10 17:04:28 by silee			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

t_node	*make_node(int value)
{
	t_node	*n_node;

	n_node = (t_node *)malloc(sizeof(t_node));
	n_node->prev = NULL;
	n_node->next = NULL;
	n_node->data = value;
	return (n_node);
}

t_stack	*stack_init(void)
{
	t_stack	*tmp_stack;
	t_node	*tmp_node;

	tmp_stack = malloc(sizeof(t_stack));
	tmp_node = malloc(sizeof(t_node));
	tmp_node->data = 0;
	tmp_node->next = NULL;
	tmp_node->prev = NULL;
	tmp_stack->head = tmp_node;
	tmp_stack->noe = 0;
	return (tmp_stack);
}

void	d_push (t_stack *list, int value)
{
	t_node	*n_node;

	n_node = malloc(sizeof(t_node));
	n_node->data = value;
	if (list->noe == 0)
	{
		n_node->next = NULL;
		n_node->prev = NULL;
		list->head = n_node;
	}
	else
	{
		n_node->next = list->head;
		list->head->prev = n_node;
		n_node->prev = NULL;
		list->head = n_node;
	}
	list->noe += 1;
}

int	d_pop (t_stack *stack)
{
	t_node	*tmp;
	t_node	*now;
	int		data;

	if (stack->noe == 0)
	{
		printf("no more elements in stack\n");
		exit(1);
	}
	now = stack->head;
	data = now->data;
	tmp = now->next;
	if (stack->noe != 1)
		tmp->prev = NULL;
	stack->head = tmp;
	free (now);
	stack->noe -= 1;
	return (data);
}

//함수 내에서 stack_init을 했을 때, 함수가 종료되면 메모리상 종료가되며 삭제됨.
//2중포인터로 사용해서 생성.
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
				d_push	(*stack_a, ft_atoi(&argv[i][j], &len));
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

void	see_value_f(t_stack *stack)
{
	t_node *cur = stack->head;
	printf("a : %d\n",cur->data);
}

void	see_value_s(t_stack *stack)
{
	t_node *cur = stack->head;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
}

int	*make_num_list(t_stack *stack_a)
{
	t_node *cur;
	int		*list;
	int		i;

	i = 0;
	cur = stack_a->head;
	list = (int *)malloc(sizeof(int) * stack_a->noe);
	if (list == 0)
		exit (1);
	while (i < stack_a->noe)
	{
		list[i] = cur->data;
		cur = cur->next;
		i++;
	}
	quick_sort(list, 0, stack_a->noe - 1);
	check_duplicated(stack_a->noe, list);
	return (list);
}
