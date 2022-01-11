/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:24:56 by silee             #+#    #+#             */
/*   Updated: 2021/12/02 15:55:53 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//문자열의 각 문자에 인자로 들어온 함수를 적용시킴.
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	len;
	unsigned int	i;
//만약 인자가 안들어온다면 함수 존재 이유가 없기에 f == 0인경우도 넣어줌.
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
