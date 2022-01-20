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
		if ((byte == -1 || byte == 0) || str == 0)
			return (0);
		buffer[byte] = '\0';
		str = ft_strjoin(str, buffer);
		if (str == 0)
			return (0);
		printf("str : \n%s @@\n",str);
		ret = find_out_line(&str, &signal);
		if (signal == ERROR && ret == 0)
			return (0);
	}
	return (ret);
}

int	loc_of_next(char *s, char c)
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
