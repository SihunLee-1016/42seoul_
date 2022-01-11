/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:38:54 by silee             #+#    #+#             */
/*   Updated: 2022/01/11 17:18:50 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 100
char	*ft_strncpy(char *res, char *buffer, int len);
char	gnl_read_write(char **next, char *buffer, char *res, int fd);
char	*ft_strdup(char *ret, char *buffer, int *line_len);

char    *get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static char	*next;
    char		*res;
	char		*ret;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	ret = gnl_read_write(&next, buffer, res, fd);

}
// 함수를 void 포인터형으로 바꾸고 반환형을 다르게 하면 될거같은디..?
// 아님말구,,

char	gnl_read_write(char **next, char *buffer, char *res, int fd)
{
	int	byte;
	int line_len;
	int	end;
	char	*ret;
	
	end = 0;
	line_len = 0;
	while(end != 1)
	{
		//처음이면 read로 str에 문자열 저장.
		if(!(*next))
		{
			// if문을 gnl함수로 넣어주고 조작하면 될거같기도..?
			if ((byte = read(fd, buffer, BUFFER_SIZE)) == -1)
				return (0);
			buffer[byte] = '\0';
			*next = buffer;
		}
		//처음이 아닌 경우. *next가 존재하는 경우 
		// 개행 전까지 res에 저장.
		res = ft_strdup(ret, next, &line_len);
		//실패했을 시  strdup에서 line_len이 -1 됐음
		if (line_len == -1)
			return (-1);
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

int	check_eof(char **next, char *res)
{
	if (**next )
}

char	*ft_strdup(char *ret, char *buffer, int *line_len)
{
	int	i;
	
	i = 0;
	while (*(buffer + i) != '\n')
		i++;
	ret = (char *)malloc(sizeof(char) * (i + 1));
	if (ret == 0)
	{
		//할당 실패했을 시 line_len을 -1로 초기화. 
		*line_len = -1;
		return (0);
	}
		
	ft_strncpy(ret, buffer, i);
	*line_len = i;
	return (ret);
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

int main(){
    char a[] = "abc\ndef\nghi";
 

}
