/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:51:28 by silee             #+#    #+#             */
/*   Updated: 2022/05/07 20:00:43 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *make_sorted_array(int argc, char **argv)
{
    int i;
    int *num_array;
    
    i = 0
    num_array = (int *)malloc(sizeof(int) * (argc - 1));
    if (num_array == 0)
        return (0);
    while (argv[i])
    {
        //atoi에서 O_F or U_F가 발생 시, exit으로 종료
        num_array[i] = ft_atoi(argv[i]);
        i++;
    }
    //quicksort로 정렬
    //qsort(num_array, argc, sizeof(int),)
    return (num_array);
}

int main(int argc, char **argv)
{
    int sorted_array;

    sorted_array = make_sorted_array(argc, **argv);
}