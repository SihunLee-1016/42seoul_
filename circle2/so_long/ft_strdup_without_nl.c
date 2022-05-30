/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:45:31 by silee             #+#    #+#             */
/*   Updated: 2022/05/30 19:41:17 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
char	*ft_strcpy_wo_nl(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(src + i) != '\n')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

char	*ft_strdup_without_nl(char *src)
{
	 int	i;
	 char	*p;

	i = 0;
	//개행까지만 위치를 찾아서 malloc후 반환.
	while (*(src + i) != '\n')
		i++;
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (p == 0)
		return (0);
	ft_strcpy_wo_nl(p, src);
	return (p);
}
