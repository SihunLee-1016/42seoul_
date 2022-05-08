/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:51:28 by silee             #+#    #+#             */
/*   Updated: 2022/05/08 16:50:12 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *make_sorted_array(int argc, char **argv)
{
    int i;
    int j;
    int *num_array;
    
    i = 1;
    j = 0;
    num_array = (int *)malloc(sizeof(int) * (argc - 1));
    if (num_array == 0)
        return (0);
    while (argv[i])
    {
        num_array[j] = ft_atoi(argv[i]);
        i++;
        j++;
    }
    num_array[i] = 0;
    i = 0;
    quick_sort(num_array, 0, argc - 2);
    return (num_array);
}

int main(int argc, char **argv)
{
    int sorted_array;

    //들어온 인자들을 정렬된 채로 배열에 저장. pivot값을 지정하기 위함.
    sorted_array = make_sorted_array(argc, **argv);
    
}