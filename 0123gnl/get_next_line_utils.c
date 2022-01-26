#include "get_next_line.h"
char	*ft_strjoin(char *str, char *buffer)
{
	int		sum;
	char	*result;

	sum = 0;
    //붙일것이 없게 됐다면 eof.
	if (buffer == 0 || *buffer == '\0')
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
	if (s2 == 0)
		return (s1);
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


// 개행이 연달아 있는 경우 2개가 복사되는 에러가 발생
char	*ft_strndup(char *str, int loc_of_next)
{
	char	*p;
	int		i;

	// 개행이 첫번째 위치한 경우 '\n \0' 2바이트가 필요한데
	// 1을 더해주지 않으면 바이트 수가 부족하게 됨.
	if (loc_of_next == 0)
		loc_of_next += 1;
	if (loc_of_next == -2)
		loc_of_next = ft_strlen(str);
	p = (char *)malloc(sizeof(char) * (loc_of_next + 1));
	if (p == 0)
		return (0);
	
	i = 0;
	// i <= strchr(Str.'\n')
	while (*(str + i ) != '\0' && i <= loc_of_next)
	{
		*(p + i) = *(str + i);
		i++;
	}
	*(p + i) = '\0';
	return (p);
}
//*str = ft_substr(*str, loc_of_next + 1, ft_strlen(*str));	
// 1 \n \0 일때, start = 2, str_len = 2
char	*ft_substr(char *str, int start, int str_len)
{
	int		i;
	char	*substr;

	if (ft_strchr(str, '\n') ==  -2 || str_len == 0)
	{
		free (str);
		return (0);
	}

	i = 0;
	substr = (char *)malloc(sizeof(char) * (str_len - start + 1));
	if (substr == 0)
		return (0);
	
	while (i < str_len - start)
	{
		*(substr + i) = *(str + start + i);
		i++;
	}
	*(substr + i) = '\0';
	free (str);
	return ((char *)substr);
}


// Loc of next 가 -2 인경우는 매우 특수한 경우. 통일성을 위해  
// dup과 substr에서 lon이 -2인 경우를 조작해야함
// Dup에서는 널 전까지만 복사를 해넣고, substr에서는 널을 반환하면 될 것 같음.
char	*ret_line(char **str)
{
	int		loc_of_next;
	char	*oneline;
	
	loc_of_next = ft_strchr(*str, '\n');
	//개행이 발견되지 않음 (Return -2) -> EOF
	// if (loc_of_next == -2)
	// {
	// 	printf("loc of next is -2\n");
	// 	return (*str);
	// }
	oneline = ft_strndup(*str, loc_of_next);
	if (oneline == 0)
		return (0);
	*str = ft_substr(*str, loc_of_next + 1, ft_strlen(*str));	
	if (*str == 0 && oneline != 0 && loc_of_next != -2)
	{
		free (oneline);
		return (0);
	}
	return (oneline);
}