/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihunlee <sihunlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:47:27 by silee             #+#    #+#             */
/*   Updated: 2022/03/10 16:11:04 by sihunlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
int	ft_print_str_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		write (fd, &s[i++], 1);
	return (i);
}

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
