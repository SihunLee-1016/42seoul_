/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:45:31 by silee             #+#    #+#             */
/*   Updated: 2021/11/24 20:15:15 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	 int	i;
	 char	*p;

	i = 0;
	while (*(src + i) != '\0')
		i++;
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (p == 0)
		return (0);
	ft_strcpy(p, src);
	return (p);
}
