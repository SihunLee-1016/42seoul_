/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xX.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:57:15 by silee             #+#    #+#             */
/*   Updated: 2022/03/07 19:15:24 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
int	hexa_num_len(unsigned long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void ft_ui_2_low_hexa(unsigned long num, int len)
{
    int i;
	int	str[len];
    
	str[len] = 0;
	i = 0;
	while (len-- >= 0 && num != 0)
	{
		if (num >= 16)
			str[len] = num % 16;
		else
			str[len] = num;
		num = num / 16;
	}
	while (str[i])
	{
		if (str[i] >= 10 && str[i] <= 15)
			ft_putchar_fd((str[i] - 10 + 'a'), 1)
		else 
			ft_putchar_fd((str[i] + '0'), 1)
		i++;
	}
}

int ft_ui_2_up_hexa(unsigned long num, int len)
{
    int i;
	int	str[len];
    
	str[len] = 0;
	i = 0;
	while (len-- >= 0 && num != 0)
	{
		if (num >= 16)
			str[len] = num % 16;
		else
			str[len] = num;
		num = num / 16;
	}
	while (str[i])
	{
		if (str[i] >= 10 && str[i] <= 15)
			ft_putchar_fd((str[i] - 10 + 'A'), 1)
		else 
			ft_putchar_fd((str[i] + '0'), 1)
		i++;
	}
}
int print_low_hexa(va_list data)
{
    int num;

    num = va_arg(data, unsigned int);
    ft_ui_2_low_hexa(unsigned long num, int len);
    return (hexa_num_len(num));
}

int print_up_hexa(va_list data)
{
    int num;

    num = va_arg(data, unsigned int);
    ft_ui_2_up_hexa(unsigned long num, int len)
    return (hexa_num_len(num));
}