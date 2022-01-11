/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:25:03 by silee             #+#    #+#             */
/*   Updated: 2021/12/02 17:26:04 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//원본 문자열에서 set에 들어있는 문자들을 탐색하고, 해당 문자들을 제거하고 반환.
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	fnt;
	size_t	back;
	char	*p;

// 원본 문자열이 비어있다면 0 반환
	if (s1 == 0)
		return (0);
// set이 비어있으면 지울것이 없으므로 원본 문자열 그대로 반환.
	if (set == 0)
		return ((char *)s1);
	fnt = 0;
	back = (size_t)ft_strlen(s1);
	// strchr을 통해 원본문자열 처음부터 set의 문자들이 있으면 fnt를 증가
	while (s1[fnt] != '\0' && ft_strchr(set, s1[fnt]))
		fnt++;
	// 동일하게 뒤에서부터 진행
	while (s1[back - 1] != '\0' && ft_strchr(set, s1[back - 1]))
	{
		// 문자열의 처음까지 도달했다면 break
		if (back - 1 < 1)
			break ;
		back--;
	}
	//fnt >= back인 경우는 모든 문자가 set에 포함되는 경우
	// fnt가 문자열의 길이와 동일한 경우
	// back이 0이면 모든 문자열이  set인 경우
	if (fnt >= back || fnt == (size_t)ft_strlen(s1) || back == 0)
		return (ft_strdup(""));
	p = (char *)malloc(sizeof(char) * ((back - fnt) + 1));
	if (p == 0)
		return (0);
	// 해당 문자들을 할당받은 p에 넣고 범위를 지정.
	ft_strlcpy(p, (s1 + fnt), back - fnt + 1);
	return (p);
}
