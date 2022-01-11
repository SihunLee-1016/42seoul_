/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihunlee <sihunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:55:49 by silee             #+#    #+#             */
/*   Updated: 2021/11/24 17:18:04 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	ft_print(int n, int fd)
{
	 int	i;
	char	num[11];

	i = 0;
	while (n > 0)
	{
		num[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		write (fd, &num[i], 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		write (fd, "0", 1);
		return ;
	}
	else if (n >= -2147483647 && n <= 2147483647)
	{
		if (n < 0)
		{
			write (fd, "-", 1);
			n = -n;
		}
	}
	else if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	else
		return ;
	ft_print(n, fd);
}
