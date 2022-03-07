/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:05:42 by silee             #+#    #+#             */
/*   Updated: 2021/11/29 16:00:54 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;

	if (*find == 0)
		return ((char *)str);
	if (ft_strlen(str) < ft_strlen(find)
		|| len < (size_t)ft_strlen(find))
		return (0);
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
