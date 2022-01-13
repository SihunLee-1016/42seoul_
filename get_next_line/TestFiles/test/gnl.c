/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:38:54 by silee             #+#    #+#             */
/*   Updated: 2022/01/13 13:46:36 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 100
char	*ft_strncpy(char *res, char *buffer, int len);
char	gnl_next(char **next, char *res, int fd);
char	*ft_strdup(char *buffer, int *line_len);

char    *get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static char	*next;
    char		*res;
	char		*ret;
	int			byte;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if(!(*next))
	{
		if ((byte = read(fd, buffer, BUFFER_SIZE)) == -1)
			return (0);
		buffer[byte] = '\0';
		*next = buffer;
	}
	// gnl_next함수를 통해 개행 전까지를 ret에 저장.
	ret = gnl_next(&next, res, fd);
	if (*next == 0 || ret == 0)
		return (0);
	return (ret);
}
// 함수를 void 포인터형으로 바꾸고 반환형을 다르게 하면 될거같은디..?
// 아님말구,,

char	gnl_next(char **next, char *res, int fd)
{
	int 	line_len;
	int		end;
	
	end = 0;
	line_len = 0;
	while(end != 1)
	{
		// 처음이 아닌 경우. *next가 존재하는 경우 
		// 개행 전까지 res에 저장.
		res = ft_strdup(next, &line_len);
		//실패했을 시  strdup에서 line_len이 -1 됐음
		if (line_len == -1)
			return (0);
		*next += line_len;
		if (**next == '\n' || res == 0)
			end = 1;
		if (**next == '\n')
			*next += 1;
		if (**next == '\0')
			*next = 0;
	}
	return (res);
}

char	*ft_strdup(char *buffer, int *line_len)
{
	int	i;
	char	*p;
	
	i = 0;
	while (*(buffer + i) != '\n')
		i++;
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (p == 0)
	{
		//할당 실패했을 시 line_len을 -1로 초기화. 
		*line_len = -1;
		return (0);
	}
		
	ft_strncpy(p, buffer, i);
	*line_len = i;
	return (p);
}

char	*ft_strncpy(char *ret, char *buffer, int len)
{
	int	i;

	i = 0;
	while (*(buffer + i) != '\0' && i < len)
	{
		*(ret + i) = *(buffer + i);
		i++;
		len++;
	}
	*(ret + i) = '\0';
	return (ret);
}