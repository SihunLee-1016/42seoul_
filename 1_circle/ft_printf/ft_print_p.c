/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:47:38 by silee             #+#    #+#             */
/*   Updated: 2022/03/11 16:49:19 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
unsigned long	p_num_len(unsigned long num)
{
	unsigned long	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_ul_2_hexa(unsigned long num, unsigned long size)
{
	unsigned long	i;
	unsigned long	*str;

	str = ft_calloc(size, sizeof(unsigned long));
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

int	print_address(va_list data)
{
	unsigned long	num;
	int				ret;

	ret = 0;
	num = (unsigned long)va_arg(data, void *);
	ret = ret + write(1, "0x", 2);
	if (num == 0)
		ret = ret + write(1, "0", 1);
	else
	{
		ft_ul_2_hexa(num, (p_num_len(num)));
		ret = ret + p_num_len(num);
	}
	return (ret);
}
