/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:41:59 by silee             #+#    #+#             */
/*   Updated: 2022/03/07 19:15:27 by silee            ###   ########.fr       */
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

void ft_ul_2_hexa(unsigned long num, int len)
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

int    print_address(va_list data)
{
    unsigned long num;
	int	ret;

	ret = 0;
    num = (unsigned long)va_arg(data, void *);
    
	ret += write(1, "0x", 2);
	if (num == 0)
		ret += write(1, "0", 1);
	else
	{
		ft_ul_2_hexa(num, num_len(num));
		ret += ft_ptr_len(num);
	}
	return (ret);
}