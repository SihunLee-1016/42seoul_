#include "get_next_line.h"
char	*get_next_line(int fd)
{
    char		buffer[BUFFER_SIZE + 1];
	char		*ret;
	static char	*str;
	int			signal;
    int			byte;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	signal = 0;
	while (signal == 0 || signal == RREAD)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1 || (byte == 0 && (signal == 0 ||signal == ALLFIN)))
			return (0);
		buffer[byte] = '\0';
		str = ft_strjoin(str, buffer);
		if (str == 0)
			return (0);
		ret = find_out_line(&str, &signal, byte);
		if (signal == ERROR && ret == 0)
			return (0);
	}
	return (ret);
}

int	loc_of_next(char *s, char c, int *signal)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		//널까지 가기 전 개행이 있다면 위치를 반환.
		if (s[i] == c)
			break ;
		i++;
	}
	//마지막 줄의 경우 개행이 없고 널이 있기 때문에 시그널을 조작.
	if (s[i] == '\0')
		*signal = ALLFIN;
	if (ft_strlen(s) == i)
		return (0);
	else
		return (i);
}

int loc_of_null(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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
