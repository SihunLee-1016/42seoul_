/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:11:11 by silee             #+#    #+#             */
/*   Updated: 2021/12/20 11:28:20 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
unsigned int	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (src[len] != '\0')
		len += 1;
	if (size <= 0)
		return (len);
	//size - 1	만큼 복사해준다. \0을 넣기 위해.
	while (i < len && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	//size가 1인경우까지 고려. 위 반복문에 걸리지 않아도 마지막에 널값이 들어가도록.
	if (size > 0)
		dest[i] = '\0';
	return (len);
}
