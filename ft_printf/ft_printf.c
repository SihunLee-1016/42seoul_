/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:45:28 by silee             #+#    #+#             */
/*   Updated: 2022/03/09 17:50:11 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
int	ft_printf(const char *str, ...)
{
	int		res;
	va_list	data;

	if (*str == '\0')
	{
		write (1, "", 1);
		return (ERROR);
	}
	va_start (data, str);
	res = circulate_str((char *)str, data);
	if (res == ERROR)
		return (0);
	return (res);
}

int	circulate_str(char *str, va_list data)
{
	int	ret;

	ret = 1;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			*str++;
			ret = ret + check_vaild_N_print(*str, data);
			if (ret == ERROR)
				return (ERROR);
		}
		else
			ret = ret + write(1, str, 1);
		*str++;
	}
	return (ret);
}

int	check_vaild_N_print(char str, va_list data)
{
	int	bite;

	bite = -1;
	if (str == 'c')
		bite = print_char(data);
	else if (str == 's')
		bite = print_string(data);
	else if (str == 'p')
		bite = print_address(data);
	else if (str == 'd')
		bite = print_demical(data);
	else if (str == 'i')
		bite = print_integer(data);
	else if (str == 'u')
		bite = print_u_demical(data);
	else if (str == 'x')
		bite = print_low_hexa(data);
	else if (str == 'X')
		bite = print_up_hexa(data);
	else if (str == '%')
		bite = write(1, "%", 1);
	return (bite);
}
