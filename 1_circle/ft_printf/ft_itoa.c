/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:36:28 by silee             #+#    #+#             */
/*   Updated: 2022/07/18 17:04:46 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	len_of_int(int n)
{
	int			len;
	long long	tmp;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len += 1;
		tmp = -(long long)n;
	}
	else
		tmp = (long long)n;
	while (tmp > 0)
	{
		tmp = tmp / 10;
		len++;
	}
	return (len);
}

int	plus_minus(int n)
{
	if (n < 0)
		return (-1);
	else
		return (0);
}

char	*ft_itoa(int n)
{
	int			len;
	int			sign;
	char		*p;
	long long	tmp;

	sign = plus_minus(n);
	len = len_of_int(n);
	p = ft_calloc(len + 1, sizeof(char));
	if (!p)
		return (0);
	p[len] = '\0';
	if (n < 0)
		tmp = -(long long)n;
	else
		tmp = (long long)n;
	while (len-- > 0)
	{
		p[len] = tmp % 10 + '0';
		tmp = tmp / 10;
	}
	if (sign == -1)
		p[0] = '-';
	return (p);
}
