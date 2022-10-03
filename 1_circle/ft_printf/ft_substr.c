/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:00:00 by silee             #+#    #+#             */
/*   Updated: 2021/11/25 17:25:20 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*substr;

	i = 0;
	if (s == 0)
		return (0);
	s_len = ft_strlen(s);
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
