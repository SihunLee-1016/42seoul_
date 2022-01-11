/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:00:00 by silee             #+#    #+#             */
/*   Updated: 2021/12/02 17:31:03 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//원본 문자열, 원본 문자열의 시작 지점, 얼마만큼 자를 것인지.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*substr;

	i = 0;
	if (s == 0)
		return (0);
	s_len = ft_strlen(s);
	// tester기에서 오류. 크기만큼 알맞게 할당해줌.
	// 문자열의 길이가 주어진 크키보다 작으면 s_len만큼 할당.
	if (s_len < len)
		substr = (char *)malloc(sizeof(char) * (s_len + 1));
	else
		substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == 0)
		return (0);
	while (i < len && start + i < s_len)
	{
		*(substr + i) = *(s + start + i);
		i++;
	}
	*(substr + i) = '\0';
	return ((char *)substr);
}
