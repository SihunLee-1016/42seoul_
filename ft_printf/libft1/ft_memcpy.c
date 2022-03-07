/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:27:52 by silee             #+#    #+#             */
/*   Updated: 2021/11/25 15:36:45 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	unsigned char		*source;

	if (!dst && !src)
		return (0);
	dest = dst;
	source = (unsigned char *)src;
	i = 0;
	while (i++ < n)
		*dest++ = *source++;
	return (dst);
}
