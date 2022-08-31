/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihunlee <sihunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 19:32:43 by silee             #+#    #+#             */
/*   Updated: 2022/08/17 19:57:47 by sihunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		i;
	char	*p;

	p = malloc(count * size);
	if (p == 0)
		return (0);
	i = count * size;
	ft_bzero(p, i);
	return (p);
}
int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	i = 0;
	while (n-- > 0)
	{
		if (tmp1[i] != tmp2[i])
			return (tmp1[i] - tmp2[i]);
		else if (tmp1[i] == 0)
			return (tmp1[i] - tmp2[i]);
		else if (tmp2[i] == 0)
			return (tmp1[i] - tmp2[i]);
		i++;
	}
	return (0);
}
