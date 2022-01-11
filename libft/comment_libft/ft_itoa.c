/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:36:28 by silee             #+#    #+#             */
/*   Updated: 2021/12/02 13:41:47 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	len_of_int(int n)
{
	int			len;
	// long long을 사용한 이유는 int min값때문에. 
	long long	tmp;

	len = 0;
	if (n == 0)
		return (1);
	
	//음수인 경우 문자열에서 - 부호가 들어가야 하므로 
	//한자리를 더 더해준다.
	if (n < 0)
	{
		len += 1;
		tmp = -(long long)n;
	}
	else
		tmp = (long long)n;
	
	//길이를 연산.
	while (tmp > 0)
	{
		tmp = tmp / 10;
		len++;
	}
	return (len);
}

int	plus_minus(int n)
{
	if (n < 0)
		return (-1);
	else
		return (0);
}

char	*ft_itoa(int n)
{
	int			len;
	int			sign;
	char		*p;
	long long	tmp;

	//음수를 처리하는 함수.
	sign = plus_minus(n);
	len = len_of_int(n);
	// 음수일때는 길이+1 된 값을 받아와 할당해줌.
	//calloc을 사용했기때문에 마지막에 null을 안넣어도됨.
	p = ft_calloc(len + 1, sizeof(char));
	if (!p)
		return (0);
	p[len] = '\0';
	if (n < 0)
		tmp = -(long long)n;
	else
		tmp = (long long)n;
	while (len-- > 0)
	{
		p[len] = tmp % 10 + '0';
		tmp = tmp / 10;
	}
	//음수인 경우 index가 0일때 - 부호를 넣어줌
	if (sign == -1)
		p[0] = '-';
	return (p);
}
