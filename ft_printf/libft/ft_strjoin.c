/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:31:43 by silee             #+#    #+#             */
/*   Updated: 2021/12/02 16:01:08 by silee            ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		sum;
	char	*result;

	sum = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	sum = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * sum + 1);
	if (result == 0)
		return (0);
	i = 0;
	*result = '\0';
	ft_strcat(result, s1);
	ft_strcat(result, s2);
	return (result);
}
