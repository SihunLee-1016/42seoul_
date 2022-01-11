/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:31:02 by silee             #+#    #+#             */
/*   Updated: 2021/12/20 09:49:24 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	ft_isspace(char sstr)
{
	if (sstr == '\t')
		return (1);
	else if (sstr == '\n')
		return (1);
	else if (sstr == '\v')
		return (1);
	else if (sstr == '\f')
		return (1);
	else if (sstr == '\r')
		return (1);
	else if (sstr == ' ')
		return (1);
	else if (sstr == '\0')
		return (1);
	else
		return (0);
}

// overflow, underflow를 체크하는 함수.
// 값이 음수/ 양수인경우를 나누고, c에 해당하는 값을 더했을 때 더하기 전 값과 비교했을 때
// 작아지면 오버플로우, 커지면 언더플로우 해서 값을 리턴.
static int	ft_check_flow(long long num, int c, int minus)
{
	num = num * minus;
	c = c - '0';
	if (minus == 1)
		if (num * 10 + c < num)
			return (1);
	if (minus == -1)
		if (num * 10 - c > num)
			return (2);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long	num;
	int			p_m;
	int			i;

	num = 0;
	p_m = 1;
	i = 0;
	// 공백 문자인 경우 모두 스킵.
	while ((ft_isspace(str[i]) == 1) && str[i])
		i++;
	// - 부호가 있는 경우 p_m을 -1로 초기화.
	if (str[i] == '-')
		p_m = -1;
	// 음/양 부호인 경우 i를 하나 증가.
	if (str[i] == '-' || str[i] == '+')
		i += 1;
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		//under, over flow체크.
		if (ft_check_flow(num, str[i], p_m) != 0)
			return (ft_check_flow (num, str[i], p_m) - 2);
		num = (10 * num) + str[i] - 48;
		i++;
	}
	return ((int)(p_m * num));
}
