/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:45:28 by silee             #+#    #+#             */
/*   Updated: 2022/03/14 18:15:17 by silee            ###   ########.fr       */
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
	va_end (data);
	if (res == ERROR)
		return (ERROR);
	return (res);
}

int	circulate_str(char *str, va_list data)
{
	int	ret;

	ret = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			ret = ret + check_vaild_N_print(*str, data);
			if (ret == ERROR)
				return (ERROR);
		}
		else
			ret = ret + write(1, str, 1);
		str++;
	}
	return (ret);
}

int	check_vaild_N_print(char str, va_list data)
{
	int	byte;

	byte = -1;
	if (str == 'c')
		byte = print_char(data);
	else if (str == 's')
		byte = print_string(data);
	else if (str == 'p')
		byte = print_address(data);
	else if (str == 'd')
		byte = print_decimal(data);
	else if (str == 'i')
		byte = print_integer(data);
	else if (str == 'u')
		byte = print_u_demical(data);
	else if (str == 'x')
		byte = print_low_hexa(data);
	else if (str == 'X')
		byte = print_up_hexa(data);
	else if (str == '%')
		byte = write(1, "%", 1);
	return (byte);
}
