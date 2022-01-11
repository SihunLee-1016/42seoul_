/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:45:47 by silee             #+#    #+#             */
/*   Updated: 2021/12/21 13:28:35 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// restrict 공부해놓기
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp;
	const char	*s;

	if ((len == 0) || (dst == 0 && src == 0))
		return (dst);
	// dst의 주소보다 src의 주소가 큰 경우, 앞에서부터 복사를 한다.
	if (dst <= src)
	{
		tmp = dst;
		s = src;
		while (len--)
			*tmp++ = *s++;
	}
	//src의 주소가 dst보다 작은경우 src의 마지막 바이트부터 복사. 
	else
	{
		tmp = dst;
		tmp += len;
		s = src;
		s += len;
		while (len--)
			*--tmp = *--s;
	}
	return (dst);
}
