/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:46:51 by heom              #+#    #+#             */
/*   Updated: 2022/04/25 15:31:24 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void
	malloc_fd(void)
{
	int	i;

	i = 0;
	// 이중포인터 생성.
	if (!(all()->fd = (int **)malloc(sizeof(int *) * (all()->proc_num))))
		safe_exit(1, "malloc_err");
	//2개의 파일 디스크럽터 생성.
	while (i < all()->proc_num)
	{
		if (!(all()->fd[i] = (int *)malloc(sizeof(int) * 2)))
			safe_exit(1, "malloc_err");
		i++;
	}
}
