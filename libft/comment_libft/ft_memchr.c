/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:37:26 by silee             #+#    #+#             */
/*   Updated: 2021/12/02 13:41:47 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// 검색을 수행할 시작 주소, 찾을 값 (함수 내부적으로 한 값씩 비교할거라 unsigned char로 변환)
// 검색을 수행할 만큼의 수
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (tmp[i] == (unsigned char)c)
		// void *에는 어떤 자료형으로 된 포인터든 모두 저장할 수 있음. 
		// 함수 반환형이 void *s니 void*형으로 변환해서 전달.
			return ((void *)s + i);
		i++;
	}
	return ((void *)0);
}
