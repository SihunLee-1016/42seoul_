/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 19:32:43 by silee             #+#    #+#             */
/*   Updated: 2022/07/14 20:41:52 by silee            ###   ########.fr       */
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
