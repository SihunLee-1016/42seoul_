/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:27:52 by silee             #+#    #+#             */
/*   Updated: 2021/12/20 10:12:35 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//메모리 복사.
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	unsigned char		*source;

	//memcpy는 세번째 인자값 n만큼 메모리 복사를 시도하는데,
	//src와 dst가 널포인터인데 n이 0이 아니면 메모리 복사를 시도하다 터져서 그부분에 대한 메모리 가드를 의미하는 것 같습니다
	
	//memcpy에서는 입력이 null일때에 대해서 별도로 규졍해놓진 않았지만 
	//둘중 하나라도 null이면 주소가 0인 메모리를 참조할 수 없어서 segfault가 발생할겁니당
	if (!dst && !src)
		return (0);

	//void *는 어떤 자료형으로도 캐스팅이 가능.
	dest = dst;
	source = (unsigned char *)src;
	i = 0;
	while (i++ < n)
		*dest++ = *source++;
	return (dst);
	//dst와 src의 주소가 겹치게 된다면 함수가 제대로 작동하지 않아 (overlap), memmove함수를 사용해야한다.
}
