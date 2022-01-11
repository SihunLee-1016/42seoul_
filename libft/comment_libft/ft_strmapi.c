/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:46:51 by silee             #+#    #+#             */
/*   Updated: 2021/12/20 11:32:20 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//주어진 문자열에 주어진 함수를 적용시킴.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tmp;
	unsigned int	i;

	i = 0;
//함수가 가르키는 주소값이 없다면 함수의 존재 으미가 없다.
	if (s == 0 || f == 0)
		return (0);
	tmp = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (tmp == 0)
		return (0);
	while (s[i] != '\0')
	{
		tmp[i] = f(i, s[i]);
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
