/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:05:42 by silee             #+#    #+#             */
/*   Updated: 2021/12/21 13:28:35 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;

	if (*find == 0)
		return ((char *)str);
	//원본 문자열보다 찾는 문자열의 길이가 더 길 때 || 탑색범위가 찾는 길이보다 길 때
	if (ft_strlen(str) < ft_strlen(find)
		|| len < (size_t)ft_strlen(find))
		return (0);
	// len-- > (size_t)ft_strlen(find) <- str의 index를 j라고 했을 때, 탐색 범위가 len이지만
	// j + strlen(find) 가  len 범위를 초과하게 된다면 주어진 길이보다 많이 탐색하게 되므로 같은 수식인 len--~~ 
	//로 처리했습니당
	while (*str != '\0' && len-- >= (size_t)ft_strlen(find))
	{
		i = 0;
		while (*(str + i) == *(find + i) && i <= (size_t)ft_strlen(find))
		{
			i++;
			if (*(find + i) == '\0')
				return ((char *)str);
		}
		str++;
	}
	return (0);
}
