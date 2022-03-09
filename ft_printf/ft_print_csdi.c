/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_csdi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:02:50 by silee             #+#    #+#             */
/*   Updated: 2022/03/09 16:11:42 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
int	print_char(va_list data);
{
	write(1, va_arg(data, char), 1);
	return (1);
}

int	print_string(va_list data)
{
	int		data_len;
	char	*s;

	s = va_arg(data, char *);
	while (*s != '\0')
	{
		write(1, s, 1);
		*s++;
	}
	write(1, "", 1);
	return ((ft_strlen(s) + 1));
}

int	print_demical(va_list data)
{
	int		num;
	char	*str_num;

	num = va_arg(data, int);
	str_num = ft_itoa(num);
	if (str_num == 0)
		return (0);
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	write(1, str_num, len);
	free(str_num);
	return (len);
}

int	print_integer(va_list data)
{
	int		num;
	char	*str_num;

	num = va_arg(data, int);
	str_num = ft_itoa(num);
	if (str_num == 0)
		return (0);
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	write (1, str_num, len);
	free (str_num);
	return (len);
}
