#include "get_next_line.h"
char	*ft_strjoin(char *str, char *buffer)
{
	int		sum;
	char	*result;

	sum = 0;
    //붙일것이 없게 됐다면 eof.
	if (buffer == 0)
		return (str);
	sum = ft_strlen(str) + ft_strlen(buffer);
	result = (char *)malloc(sizeof(char) * (sum + 1));
	if (result == 0)
		return (0);
	*result = '\0';
	ft_strcat(result, str);
	ft_strcat(result, buffer);
	if (str != 0)
		free (str);
	str = result;
	return (result);
}

char	*ft_strcat(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}

char	*ft_strndup(char *str, int loc_of_next)
{
	char	*p;
	int		i;

	p = (char *)malloc(sizeof(char) * (loc_of_next + 1));
	if (p == 0)
		return (0);
	i = 0;

	while (*(str + i ) != '\0' && i < loc_of_next)
	{
		*(p + i) = *(str + i);
		i++;
	}
	*(p + i) = '\0';
	return (p);
}

char	*ft_substr(char *s, int start, int str_len)
{
	int		i;
	char	*substr;
	
	if (start == str_len)
	{
		free (s);
	 	return (0);
	}

	i = 0;
	substr = (char *)malloc(sizeof(char) * (str_len - start + 1));
	if (substr == 0)
		return (0);
	
	while (i < str_len - start)
	{
		*(substr + i) = *(s + start + i);
		i++;
	}
	*(substr + i) = '\0';
	return ((char *)substr);
}


char	*ret_line(char **str)
{
	int		loc_of_next;
	char	*oneline;
	
	loc_of_next = ft_strchr(str, '\n');
	//개행이 발견되지 않음 -> 중간에 개행없이 끝에 널문자만 존재
	if (loc_of_next == 0)
		return (str);
	oneline = ft_strndup(str, loc_of_next);
	if (oneline == 0)
	{
		free (str);
		return (0);
	}
	str = ft_substr(*str, loc_of_next + 1, ft_strlen(str));	
	if (str == 0 && loc_of_next != ft_strlen(str))
	{
		free (oneline);
		return (0);
	}
	return (oneline);
}