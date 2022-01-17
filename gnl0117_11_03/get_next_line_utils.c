/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:39:01 by silee             #+#    #+#             */
/*   Updated: 2022/01/17 11:03:22 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"
char	*gnl_next(char **next, int fin)
{
	int	line_len;
	int	end;
	char	*res;
	
	end = 0;
	line_len = 0;
	while (end != 1 && fin != 2)
	{
		res = ft_strdup(*next, &line_len);
		// printf("line len : %d \n", line_len);
		// printf("next in gnl_next : %c\n", **next);
		
		//할당이 실패한 경우에 
		if (line_len == -1)
			return (0);
		// res에 한 줄이 저장이 됐으므로 그 줄의 길이만큼 주소값을 증가시켜줌.
		*next += line_len;
		// 증가시킨 주소값에 들어있는 값이 개행 혹은 결과값이 0
		if (**next == '\n' || res == 0)
			end = 1;
		if (**next == '\n')
			*next += 1;
		
		//여기서 주소값을 0으로 만들어줘서
		// gnl함수의 if문이 계속 돌아 무한루프를 도는건가..?
		if (**next == '\0')
			*next = 0;
		printf("\n loop in gnl next \n");
	}
	if (fin == 2)
		return (0);
	return (res);
}

char	*ft_strdup(char *buffer, int *line_len)
{
	int		i;
	char	*p;

	i = 0;
	while (*(buffer + i) != '\n')
		i++;
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (p == 0)
	{
		*line_len = -1;
		return (0);
	}
	ft_strncpy(p, buffer, i);
	printf("in strdup : %s\n",p);
	*line_len = i;
	return (p);
}

void	ft_strncpy(char *ret, char *buffer, int len)
{
	int	i;
	
	i = 0;
	while (*(buffer + i) != '\n' && i < len)
	{
		*(ret + i) = *(buffer + i);
		i++;
		len++;
	}
	*(ret + i) = '\0';
	//return (ret);
}
