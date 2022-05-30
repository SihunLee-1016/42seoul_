/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_without_nl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:13:44 by silee             #+#    #+#             */
/*   Updated: 2022/05/30 20:25:28 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"
char	*ft_strcat_without_nl(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\n')
	{
		if (s2[j] == '\0')
			break ;
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}


//s1은 개행이 없는 문자열. s2는 개행이 존재하는 문자열.
char	*ft_join_without_nl(char *s1, char *s2)
{
	int		i;
	int		sum;
	char	*result;

	sum = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	//s1의 길이는 그냥 strlen. s2의 길이는 개행이 포함되어 있으므로 
	sum = ft_strlen(s1) + ft_strlen(s2) - 1;
	result = (char *)malloc(sizeof(char) * sum + 1);
	if (result == 0)
		return (0);
	i = 0;
	*result = '\0';
	ft_strcat(result, s1);
	ft_strcat_without_nl(result, s2);
	return (result);
}
