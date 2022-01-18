/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:39:01 by silee             #+#    #+#             */
/*   Updated: 2022/01/18 15:23:15 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
char *gnl_next(char *next, char **tmp, int *signal)
{
	int	idx;
	int	tmp_len;
	char	*ret;
	
	idx = 0;
	tmp_len = ft_strlen(tmp);
	// line_len 을 지지우우고 그그냥  반환을 널로, 아래 조건문에서 tmp==0인 경우를 체크.
	tmp = ft_strjoin(tmp, next, signal);
	if (tmp == 0)
		return (0);
	while(*(next + idx) != '\0')
	{	
		if (*(next + idx++) == '\n')
		{
			// ret는 성공, tmp는 실패 시, ret를 프리시켜줘야함.
			
			//이 파트를 해결하는 함수를 만들면 될 거 같음,. substr조작.
			// ret = ft_substr(tmp, 0, tmp_len + idx, signal);
			// if (ret == 0)
			// 	return (0);
			// tmp = ft_substr(tmp, tmp_len + idx, ft_strlen(tmp), signal);
			// if (tmp == 0)
			// 	return (0);
			return (ret);
		}
	}
	return (NULL);
}

//여기서도 말록 실패시 signal 값 변경 필요.
char	*ft_substr(char *s, int start, int len, int *signal)
{
	int	i;
	char	*substr;

	i = 0;
	if (s == 0)
		return (0);

	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == 0)
	{
		*signal = -1;
		return (0);
	}
		
	while (i < len && start + i < s_len)
	{
		*(substr + i) = *(s + start + i);
		i++;
	}
	*(substr + i) = '\0';
	return ((char *)substr);
}
// njoin을 생각하면 될 거 같음. 그럼 함수 하나가 비니까 get_next_line 함수에서 free 해줄 여유가 나올듯
 char	*ft_strjoin(char *s1, char *s2, int *signal)
{
	int		i;
	int		sum;
	char	*result;

	sum = 0;
	sum = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (sum + 1));
	if (result == 0)
	{
		*signal = -1;
		return (0);
	}
	i = 0;
	*result = '\0';
	if (s1 != 0)
		ft_strcat(result, s1);
	ft_strcat(result, s2);
	free(s1);
	s1 = result;
	return (result);
}

char	*ft_strcat(char *res, char const *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*(res + i) != '\n')
		i++;
	while (*(buffer + j) != '\n')
	{
		*(res + i + j) = *(buffer+j);
		j++;
	}
	*(res + i + j) = '\0';
	return (res);
}

int	ft_strlen(char *str)
{
	int	len;
	
	if (str == 0)
		return (0);
	len = 0;
	while (str[len] != '\n')
		len++;
	return (len);
}