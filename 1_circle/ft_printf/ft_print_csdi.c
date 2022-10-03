/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_csdi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:02:50 by silee             #+#    #+#             */
/*   Updated: 2022/03/11 17:10:01 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
int	print_char(va_list data)
{
	char	c;

	c = va_arg(data, int);
	write(1, &c, 1);
	return (1);
}

int	print_string(va_list data)
{
	char	*s;
	int		ret;

	ret = 0;
	s = va_arg(data, char *);
	if (s == NULL)
		ret += write(1, "(null)", 6);
	else
		ret += ft_print_str_fd(s, 1);
	return (ret);
}

int	print_decimal(va_list data)
{
	int		num;
	char	*str_num;
	int		ret;

	num = va_arg(data, int);
	str_num = ft_itoa(num);
	if (str_num == 0)
		return (0);
	ret = ft_print_str_fd(str_num, 1);
	free (str_num);
	return (ret);
}

int	print_integer(va_list data)
{
	int		num;
	char	*str_num;
	int		ret;

	num = va_arg(data, int);
	str_num = ft_itoa(num);
	if (str_num == 0)
		return (0);
	ret = ft_print_str_fd(str_num, 1);
	free (str_num);
	return (ret);
}
