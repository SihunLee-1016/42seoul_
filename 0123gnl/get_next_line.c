#include "get_next_line.h"
char	*get_next_line(int fd)
{
	static char	*str;
	char		*ret;

    if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = txt_read(fd, str);
	if (str == 0)
	{
		free (str);
		return (0);
	}
	// 반환 ㅇ -> 개행이 존재한다는 것. 혹은 eof => 확인이 필요한 자리. \0 인지 \n인지.

	// 개행이 발견된 경우 -> 개행의 위치까지 str을 자르고 전체 str에서 앞선 반환값을 제외한 문자열을 다시 저장.
	ret = ret_line(&str);
	if (ret == 0)
	{
		free (str);
		return (0);
	}
	return (ret);
}

char    *txt_read(int fd,char *str)
{
    int		byte;
    char	buffer[BUFFER_SIZE + 1];
	char	*str;

	byte = 1;
	// byte가 0이 아니고 문자열 내에 개행이 있을 때 까지 반복
	// 반복을 돌다가 중간에 개행이 존재한다면 반복문을 탈출하여 return str;
	// byte == 0일때까지 반복문을 돌았다면 중간에 개행이 없고 마지막에 널문자만 존재한다는 것.
	while (byte > 0 && ft_strchr(str, '\n') == 0)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
			return (0);
		buffer[byte] = '\0';
		str = ft_strjoin(str, buffer);
		if (str == 0)
			return (0);
	}
	return (str);
}

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	len;
	
	if (str == 0)
		return (0);
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
