/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:24:56 by silee             #+#    #+#             */
/*   Updated: 2021/11/25 16:24:23 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	len;
	unsigned int	i;

	if (s == 0 || f == 0)
		return ;
	len = (unsigned int)ft_strlen(s);
	i = 0;
	if (s != 0 && f != 0)
	{
		while (i < len)
		{
			(*f)(i, s);
			i++;
			s++;
		}
	}
}
