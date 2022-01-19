char	*ft_strdup(char *src,int *len)
{
	 int	i;
	 char	*p;

	i = 0;
	while (*(src + i) != '\0')
		i++;
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (p == 0)
		return (0);
    i = 0;
    while (*(src + i) != '\0')
    {
        *(p + i) = *(src + i);
        i++;
    }
    *(p + i) = '\0';
	*len = i;
	return (p);
}
