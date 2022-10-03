/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:31:35 by silee             #+#    #+#             */
/*   Updated: 2022/09/24 10:31:36 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	if_end_exit(char c, char end)
{
	if (end == 'y')
	{
		if (c == '\0' || c == '\n')
			err_exit("non-numeric value");
	}
	if (end == 'n')
	{
		if (c != '\0' && c != '\n')
			err_exit("non-numeric value");
	}
}

int	rt_atoi(const char *str)
{
	unsigned long long	result;
	int					sign;
	int					idx;

	idx = 0;
	while (str[idx] == ' ' || (str[idx] >= 9 && str[idx] <= 13))
		idx++;
	sign = 1;
	if (str[idx] == '-')
		sign = -1;
	if (str[idx] == '-' || str[idx] == '+')
		idx++;
	result = 0;
	if_end_exit(str[idx], 'y');
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		result = result * 10 + str[idx] - '0';
		idx++;
	}
	if_end_exit(str[idx], 'n');
	if (result > ATOI_MAX && sign == 1)
		err_exit("number too big\n");
	else if (result > ATOI_MIN && sign == -1)
		err_exit("number too small\n");
	return ((int)result * sign);
}

static void	get_decimal(const char *str, double *result, int *idx)
{
	int	dot;

	if (str[(*idx)] == '.')
	{
		if_end_exit(str[(*idx)], 'y');
		dot = 1;
		(*idx)++;
		while (str[(*idx)] >= '0' && str[(*idx)] <= '9')
		{
			dot *= 10;
			(*result) = (*result) + (double)(str[(*idx)] - '0') / dot;
			(*idx)++;
		}
	}
}

double	rt_atod(const char *str)
{
	double	result;
	double	sign;
	int		idx;

	idx = 0;
	while (str[idx] == ' ' || (str[idx] >= 9 && str[idx] <= 13))
		idx++;
	sign = 1;
	if (str[idx] == '-')
		sign = -1;
	if (str[idx] == '-' || str[idx] == '+')
		idx++;
	if_end_exit(str[idx], 'y');
	result = 0;
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		result = result * 10 + str[idx] - '0';
		idx++;
	}
	get_decimal(str, &result, &idx);
	if_end_exit(str[idx], 'n');
	return (result * sign);
}
