/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:51:28 by silee             #+#    #+#             */
/*   Updated: 2022/05/10 16:45:51 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int *make_sorted_array(int argc, char **argv)
// {
//     int i;
//     int j;
//     int *num_array;
    
//     i = 1;
//     j = 0;
//     num_array = (int *)malloc(sizeof(int) * (argc - 1));
//     if (num_array == 0)
//         return (0);
//     while (argv[i])
//     {
//         num_array[j] = ft_atoi(argv[i]);
//         i++;
//         j++;
//     }
//     num_array[i] = 0;
//     return (num_array);
// }
// void	check_duplicated(int argc, int *nums)
// {
// 	int	check_idx;
// 	int	rotate_idx;

// 	check_idx = 0;
// 	while (check_idx < argc)
// 	{
// 		rotate_idx = 0;
// 		while (rotate_idx < argc)
// 		{
// 			if (check_idx == rotate_idx++)
// 				continue ;
// 			if (nums[check_idx] == nums[rotate_idx])
// 			{
// 				write (1, "ERROR", 6);
// 				exit (1);
// 			}
// 			rotate_idx +=1 ;
// 		}
// 		check_idx += 1;
// 	}
// }

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    //들어온 인자들을 정렬된 채로 배열에 저장. pivot값을 지정하기 위함.
    make_stack_n_push(&stack_a, argc, argv);
    //see_value_f(stack_a);
    int i = 0;
    see_value_s(stack_a);

}


// typedef struct s_node
// {
// 	int				data;
// 	struct s_node	*next;
// 	struct s_node	*prev;
// }	t_node;

// typedef struct s_stack
// {
//     int             noe;
// 	struct s_node	*head;
// }	t_stack;