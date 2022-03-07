/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:25:03 by silee             #+#    #+#             */
/*   Updated: 2021/11/25 16:27:08 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	fnt;
	size_t	back;
	char	*p;

	if (s1 == 0)
		return (0);
	if (set == 0)
		return ((char *)s1);
	fnt = 0;
	back = (size_t)ft_strlen(s1);
	while (s1[fnt] != '\0' && ft_strchr(set, s1[fnt]))
		fnt++;
	while (s1[back - 1] != '\0' && ft_strchr(set, s1[back - 1]))
	{
		if (back - 1 < 1)
			break ;
		back--;
	}
	if (fnt >= back || fnt == (size_t)ft_strlen(s1) || back == 0)
		return (ft_strdup(""));
	p = (char *)malloc(sizeof(char) * ((back - fnt) + 1));
	if (p == 0)
		return (0);
	ft_strlcpy(p, (s1 + fnt), back - fnt + 1);
	return (p);
}
