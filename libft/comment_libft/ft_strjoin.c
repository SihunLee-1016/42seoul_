/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:31:43 by silee             #+#    #+#             */
/*   Updated: 2021/12/21 13:28:35 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strcat(char *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}

//할당을 받아서 두 값을 이어붙힘.
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		sum;
	char	*result;

	sum = 0;
	// 참조연산자가 없을때는 가르키는 주소가 없기때문에. 아래 *result ='\0'를 넣어줘야함.
	if (s1 == 0 || s2 == 0)
		return (0);
	sum = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * sum + 1);
	if (result == 0)
		return (0);
	i = 0;
	//왜 넣어줬지?
	// s1,s2가 아무것도 없는 경우.
	*result = '\0';
	ft_strcat(result, s1);
	ft_strcat(result, s2);
	return (result);
}
