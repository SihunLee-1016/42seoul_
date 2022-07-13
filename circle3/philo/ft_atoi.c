/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:31:02 by silee             #+#    #+#             */
/*   Updated: 2022/07/13 14:58:49 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int	ft_isspace(char sstr)
{
	if (sstr == '\t')
		return (1);
	else if (sstr == '\n')
		return (1);
	else if (sstr == '\v')
		return (1);
	else if (sstr == '\f')
		return (1);
	else if (sstr == '\r')
		return (1);
	else if (sstr == ' ')
		return (1);
	else if (sstr == '\0')
		return (1);
	else
		return (0);
}

static int	ft_check_flow(long long num, int c, int minus)
{
	num = num * minus;
	c = c - '0';
	if (minus == 1)
		if (num * 10 + c < num)
			return (1);
	if (minus == -1)
		if (num * 10 - c > num)
			return (2);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long	num;
	int			p_m;
	int			i;

	num = 0;
	p_m = 1;
	i = 0;
	while ((ft_isspace(str[i]) == 1) && str[i])
		i++;
	if (str[i] == '-')
		p_m = -1;
	if (str[i] == '-' || str[i] == '+')
		i += 1;
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		if (ft_check_flow(num, str[i], p_m) != 0)
			return (ft_check_flow (num, str[i], p_m) - 3);
		num = (10 * num) + str[i] - 48;
		i++;
	}
	return ((int)(p_m * num));
}
