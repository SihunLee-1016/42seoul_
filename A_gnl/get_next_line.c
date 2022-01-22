#include "get_next_line.h"
char	*get_next_line(int fd)
{
    char		buffer[BUFFER_SIZE + 1];
	char		*ret;
	static char	*str;
	static int	IS_END;
	int			signal;
    int			byte;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	signal = 0;
	while (signal == 0 || signal == RREAD)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1 || (byte == 0 && IS_END == END))
			return (0);
		str = ft_strjoin(str, buffer, byte);
		if (str == 0)
			return (0);
		ret = find_out_line(&str, &signal, &byte);
		if (signal == END)
			IS_END = END;
		if (signal == ERROR && ret == 0)
			return (0);
	}
	return (ret);
}

int	loc_of_next(char *s, char c, int *signal, int byte)
{
	int	loc;

	loc = 0;
	//일단 반복 
	while (s[loc] != '\0')
	{
		if (s[loc] == c)
			return (loc);
		loc++;
	}
	if (byte != 0)
		return (0);
	else
	{
		loc = loc_of_null(s);
		*signal = END;
		return (loc);
	}
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
