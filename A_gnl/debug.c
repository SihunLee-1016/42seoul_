# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define FINISH 2
# define RREAD 1
# define ERROR -1
# define BUFFER_SIZE 10
char	*get_next_line(int fd);
int	    loc_of_next(char *s, char c);
int	    ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcat(char *res, char *buffer);
char    *find_out_line(char **str, int *signal);
char	*ft_substr(char *s, int start, int len, int *signal);

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
		if (byte == -1 || byte == 0)
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
	while (str[len] != '\n')
		len++;
	return (len);
}
char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*result;

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

char    *find_out_line(char **str, int *signal)
{
    int     loc;
    char    *ret;

    loc = loc_of_next(*str, '\n');
    //개행의 위치가 없으므로 다시 읽어야 함.
    if (loc == 0)
    {
        *signal = RREAD;
        return (0);        
    }
    //만약 아니라면. str의 처음 위치부터 개행의 위치까지 ret에 저장.
    ret = ft_substr(*str, 0, loc, signal);
    if (ret == 0)
        return (0);
    // ret에 이미 저장을 한번 했으므로 개행 다음 문자부터 다시 str에 넣어줌. 

    //세그폴트가 발생할거같음. str은 이미 할당 되어 있는건데 다시 할당을 하게되니.
    *str = ft_substr(*str, loc + 1, ft_strlen(*str), signal);
    
	// 개행이 저장한 문자열의 마지막에 위치하는 경우 ret에 그동안 담겨있던
    // 모든 것이 저장되어 있으므로 str ==0이 아닌 ERROR조건까지 넣어줘야지
    //할당이 제대로 안된 경우 ret을 free 하고 return 0 할 수 있다. 
    if (*str == 0 && *signal == ERROR)
    {
        if (ret != 0)
            free (ret);
        return (0);
    }

    //제대로 할당이 됐다면 ret의 주소를 반환.
    *signal = FINISH;
	return (ret);
}

char	*ft_substr(char *s, int start, int len, int *signal)
{
	int		i;
	char	*substr;
	
    // 개행이 연달아 있는 경우?
	//if (*signal == ERROR || start == len)
    if (start == len)
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
int	main(void)
{
    int     fd;
    char    *tmp;
    int     idx;

    fd = open("test", O_RDONLY);
    idx = 1;
    printf ("fd : %d\n", fd);
    while ((tmp = get_next_line(fd)) != 0)
    {
        printf("\n----- %d -----\n", idx);
        printf("%s", tmp);
        printf("-------------\n\n");
        idx++;
		free(tmp);
    }
    close(fd);
    return (0);
}