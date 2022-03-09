/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:47:45 by silee             #+#    #+#             */
/*   Updated: 2022/03/09 16:11:41 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
int	num_len(unsigned int num)
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

char	*ft_uitoa(unsigned int n)
{
	unsigned int	len;
	char			*p;

	len = num_len(n);
	p = ft_calloc(len + 1, sizeof(char));
	if (!p)
		return (0);
	while (len-- > 0)
	{
		p[len] = n % 10 + '0';
		n = n / 10;
	}
	return (p);
}

int	print_u_demical(va_list data)
{
	unsigned int	num;
	int				ret;
	char			*num;

	ret = 0;
	num = va_arg(data, unsigned int);
	if (num == 0)
		ret = ret + write(1, "0", 1);
	num = ft_uitoa(num);
	else
	{
		ret = ret + ft_print_str_fd(num, 1);
		free (num);
	}
	return (ret);
}
