/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:47:50 by silee             #+#    #+#             */
/*   Updated: 2022/03/11 17:08:39 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
void	ft_ui_2_low_hexa(unsigned int num, unsigned int size)
{
	unsigned int	i;
	unsigned int	*str;

	str = ft_calloc(size, sizeof(unsigned int));
	if (str == 0)
		return ;
	i = size;
	while (size-- >= 0 && num != 0)
	{
		if (num >= 16)
			str[size] = num % 16;
		else
			str[size] = num;
		num = num / 16;
	}
	while (size + 1 < i)
	{
		if (str[size + 1] >= 10 && str[size + 1] <= 15)
			ft_putchar_fd((str[size + 1] - 10 + 'a'), 1);
		else
			ft_putchar_fd((str[size + 1] + '0'), 1);
		size++;
	}
	free(str);
}

void	ft_ui_2_up_hexa(unsigned int num, unsigned int size)
{
	unsigned int	i;
	unsigned int	*str;

	str = ft_calloc(size, sizeof(unsigned int));
	if (str == 0)
		return ;
	i = size;
	while (size-- >= 0 && num != 0)
	{
		if (num >= 16)
			str[size] = num % 16;
		else
			str[size] = num;
		num = num / 16;
	}
	while (size + 1 < i)
	{
		if (str[size + 1] >= 10 && str[size + 1] <= 15)
			ft_putchar_fd((str[size + 1] - 10 + 'A'), 1);
		else
			ft_putchar_fd((str[size + 1] + '0'), 1);
		size++;
	}
	free (str);
}

int	print_low_hexa(va_list data)
{
	int	num;

	num = va_arg(data, unsigned int);
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		ft_ui_2_low_hexa(num, hexa_num_len(num));
	return (hexa_num_len(num));
}

int	print_up_hexa(va_list data)
{
	int	num;

	num = va_arg(data, unsigned int);
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		ft_ui_2_up_hexa(num, hexa_num_len(num));
	return (hexa_num_len(num));
}
