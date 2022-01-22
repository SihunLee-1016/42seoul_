#include "get_next_line.h"
char	*ft_strjoin(char *s1, char *s2,int byte)
{
	int		len;
	char	*result;

	s2[byte] = '\0';
	if (s1 == 0 && byte == 0)
		return(0);
	len = ft_strlen(s2);
    if (s1 != 0)
        len += ft_strlen(s1);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
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

char    *find_out_line(char **str, int *signal, int *byte)
{
    int     loc;
    char    *ret;

    loc = loc_of_next(*str, '\n',signal, *byte);
    if (loc == 0 && byte != 0)
	{
		*signal = RREAD;
		return (0);
	}

    ret = ft_substr(*str, 0, loc, signal);
    if (ret == 0)
        return (0);
    *str = ft_substr(*str, loc + 1, ft_strlen(*str), signal);
    if (*str == 0 && *signal == ERROR)
    {
        if (ret != 0)
            free (ret);
        return (0);
    }
	if (*signal != END)
		*signal = FINISH;
	return (ret);
}

char	*ft_substr(char *s, int start, int len, int *signal)
{
	int		i;
	char	*substr;
	
	if (start == len || *(s + start) == '\0')
    	return (0);
		
	i = 0;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == 0)
	{
		*signal = ERROR;
		return (0);
	}
	while (i < len)
	{
		*(substr + i) = *(s + start + i);
		i++;
	}
	*(substr + i) = '\0';
	return ((char *)substr);
}
