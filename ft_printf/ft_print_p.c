/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihunlee <sihunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:47:38 by silee             #+#    #+#             */
/*   Updated: 2022/03/10 16:08:57 by sihunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
void	ft_ul_2_hexa(unsigned long num, int size)
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
		ft_ul_2_hexa(num, num_len(num) + 1);
		ret = ret + hexa_num_len(num);
	}
	return (ret);
}
