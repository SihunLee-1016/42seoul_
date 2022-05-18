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

void	check_dup(t_stack *stack_a)
{
	t_node	*o_cur;
	t_node	*i_cur;

	o_cur = stack_a->head;
	while (o_cur)
	{
		i_cur = stack_a->head;
		while (i_cur)
		{
			if (o_cur != i_cur)
			{
				if (o_cur->data == i_cur->data)
				{
					write (1, "ERROR in checkdup", 18);
					exit (1);
				}
			}
			i_cur = i_cur->next;
		}
		o_cur = o_cur->next;
	}
}

int	find_max_pos(t_stack *stack_b, t_node *max)
{
	t_node	*cur;
	int		position;

	if (stack_b->noe == 1)
		return (1);
	position = 0;
	cur = stack_b->head;
	while (cur)
	{
		if (max->data == cur->data)
			return (position);
		cur = cur->next;
		position += 1;
	}
	if (cur->data == max->data)
		return (position);
	else
		return (-1);
}

t_node	*find_max_node(t_stack *stack_b)
{
	t_node	*cur;
	t_node	*max_position;
	int		max_data;

	if (stack_b->noe == 1)
		return (stack_b->head);
	cur = stack_b->head;
	max_data = cur->data;
	while (cur)
	{
		if (cur->data > max_data)
		{
			max_data = cur->data;
			max_position = cur;
		}
		cur = cur->next;
	}
	return (max_position);
}

void	push_a_in_seq(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*max;
	int		max_pos;
	int		i;

	//1.현존하는 가장 큰 값이 "b에서" 어디에 위치해 있는지 찾는다.
	//2. 해당 위치가 noe/2보다 큰지, 작은지에 대해서 판별을 한 뒤
	// 		크다면 rra로, 작다면 ra로 top이 될 때 까지 반복.
	//1과 2 반복
	while (stack_b->noe > 0)
	{
		i = -1;
		max = find_max_node(stack_b);
		max_pos = find_max_pos(stack_b, max);
		if (max_pos == -1)
			exit (1);
		// 절반 보다 큰 위치에 일 떄
		if (stack_b->noe / 2 < max_pos)
			while (++i < stack_b->noe - max_pos)
				rrb_command(stack_b);
		// 절반보다 작은 위치일 때
		else 
			while (++i < max_pos)
				rb_command(stack_b);
		pa_command(stack_a, stack_b);
		printf("b noe %d\n", stack_b->noe);
	}
}

//전체 개수 확인 필요. rra를 2
// 100이고, 80인 경우.
// 50 -80 -> -30. 

//100이고 20인 경우

// 절반 인덱스 - 데이터의 인덱스 
// 음수인 경우 : 데이터의 인덱스가 더 큰 경우. rr 커맨드로
// 양수인 경우 : r 커맨드로 


int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	make_stack_n_push(&stack_a, argc, argv);
	stack_b = stack_init();
	check_dup(stack_a);
    indexing_data(stack_a);
	
	//b로 전부 넘어갔음. 이제 a로 다시 넘겨줄 차례.
	// make_hourglass(stack_a, stack_b);
	//b에서 가장 큰 idx를 가진 node를 찾기.
	// push_a_in_seq(stack_a, stack_b);
    // see_value_s(stack_a);
	see_value_s(stack_a);
	printf("\nhead = : %d\n",stack_a->head->data);
}
    // printf("stack a\n");
    // see_value_s(stack_a);
    // printf("stack b\n");
	// system("leaks a.out");