/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:39:01 by silee             #+#    #+#             */
/*   Updated: 2022/01/19 16:35:40 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
char *gnl_next(char *next, char **tmp, int *signal)
{
	int		idx;
	int		tmp_len;
	char	*ret;
	
	idx = 0;
	
	//join 에서 실패한 경우 signal 값을 2로 둬서 본 함수에서 반복문을 다시 돌도록 실행.
	*tmp = ft_strjoin(*tmp, next, signal);
	if (tmp == 0)
		return (0);
	//일단 들어온 값을 이어 붙힌 다음 아래에서 이어 붙힌 것들 중에서 개행이 있다면 substr로 자르고 개행 전까지를 반환.
	// 개행이 여러개 있을 수 있으니까
	
	while(*(next + idx) != '\0')
	{	
		//중간에 개행이 있는 경우를 처리하는 조건문. next의 주소를 0으로 초기화 할 필요가 없음.
		if (*(next + idx++) == '\n')
		{
			// ret는 성공, tmp는 실패 시, ret를 프리시켜줘야함.
			//이 파트를 해결하는 함수를 만들면 될 거 같음,. substr조작.
			ret = ft_substr(*tmp, 0, tmp_len + idx - 1, signal);
			if (ret == 0)
				return(0);
			*tmp = ft_substr(*tmp, tmp_len + idx - 1, ft_strlen(*tmp), signal);
			if (*signal == -1)
			{
				if (ret != 0)
					free (ret);
				return (0);
			}
			*signal = 2;
			return (ret);
		}
	}
	//반복문이 끝났다면 중간에 개행이 없는 것이므로 next를 0으로 초기화 해준다.
	//반환은 아무것도 없으므로 본 함수에서 signal의 값을 통해 반복문 조건 충족시키기.
	*next = 0;
	return (0);
}

//여기서도 말록 실패시 signal 값 변경 필요.
// ret 성공, substr이 할당 실패 시 ret을 할당 해제.
char	*ft_substr(char *s, int start, int len, int *signal)
{
	int		i;
	char	*substr;

	//2번째 실행부터 걸리게 되는 조건문.
	//앞전 실행 결과에 따라 signal이 -1이라는 것은 ret이 제대로 할당이 되지 않았다는 거니까
	// 실행 할 필요 없이 그냥 바로 return (0) 해주면 됨.
	if (*signal == -1 || start == len)
		return (0);
		
	i = 0;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == 0)
	{
		// 1번째 실행부터 걸리는 조건문.
		// ret이 제대로 할당이 안되었으면 바로 -1을 할당하게 됨. 
		// signal이 0인 상태로 들어왔는데 tmp 할당이 실패했다면 siganl은 -1. 
		// 위 35줄에서 걸리게 됨.
		*signal = -1;
		return (0);
	}
		
	while (i < len)
	{
		*(substr + i) = *(s + start + i);
		i++;
	}
	*(substr + i) = '\0';
	//만약 ret이 할당이 제대로 되었다면 signal은 그대로 0일 것이다. 
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
	if (s1 != 0)
		free(s1);
	s1 = result;
	return (result);
}

char	*ft_strcat(char *res, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*(res + i) != '\0')
		i++;
	while (*(buffer + j) != '\0')
	{
		*(res + i + j) = *(buffer + j);
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