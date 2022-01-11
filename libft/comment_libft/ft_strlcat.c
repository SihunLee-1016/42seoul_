/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:11:05 by silee             #+#    #+#             */
/*   Updated: 2021/12/21 13:28:35 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
unsigned int	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	destlen;
	size_t	srclen;

	i = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	// dst 뒤에 src를 복사하는데, 복사하는 사이즈 size - dstlen - 1 만큼이다. 
	// size < destlen 이면  size의 크기를 벗어나기에 문자를 이어붙일수가 없다.
	// 복사하는 사이즈가 음수가 되므로 연결작업은 건너뛰고 srclen+size를 반환
	if (size <= destlen)
		return (size + srclen);
	//size > destlen 이면 복사를 하며 srclen + destlen 을 반환.
	//destlen + i + 1 < len 은 식이 동일하기때문에 그냥 했다. 음수가 되는게 싫어서 그냥 처리했다.
	while (src[i] && destlen + i + 1 < size)
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = 0;
	return (destlen + srclen);
}
