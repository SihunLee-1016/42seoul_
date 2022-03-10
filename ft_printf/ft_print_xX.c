/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihunlee <sihunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:47:50 by silee             #+#    #+#             */
/*   Updated: 2022/03/10 16:08:50 by sihunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
void	ft_ui_2_low_hexa(unsigned long num, int size)
{
	int	i;
	int	*str;

	str = ft_calloc(size, sizeof(int));
	if (str == 0)
		return ;
	i = 0;
	while (size-- >= 0 && num != 0)
	{
		if (num >= 16)
			str[size] = num % 16;
		else
			str[size] = num;
		num = num / 16;
	}
	while (str[i])
	{
		if (str[i] >= 10 && str[i] <= 15)
			ft_putchar_fd((str[i] - 10 + 'a'), 1);
		else
			ft_putchar_fd((str[i] + '0'), 1);
		i++;
	}
}

void	ft_ui_2_up_hexa(unsigned long num, int size)
{
	int	i;
	int	*str;

	str = ft_calloc(size, sizeof(int));
	if (str == 0)
		return ;
	i = 0;
	while (size-- >= 0 && num != 0)
	{
		if (num >= 16)
			str[size] = num % 16;
		else
			str[size] = num;
		num = num / 16;
	}
	while (str[i])
	{
		if (str[i] >= 10 && str[i] <= 15)

			ft_putchar_fd((str[i] - 10 + 'A'), 1);
		else
			ft_putchar_fd((str[i] + '0'), 1);
		i++;
	}
	free (str);
}

int	print_low_hexa(va_list data)
{
	int	num;

	num = va_arg(data, unsigned int);
	ft_ui_2_low_hexa(num, hexa_num_len(num) + 1);
	return (hexa_num_len(num));
}

int	print_up_hexa(va_list data)
{
	int	num;

	num = va_arg(data, unsigned int);
	ft_ui_2_up_hexa(num, hexa_num_len(num) + 1);
	return (hexa_num_len(num));
}
