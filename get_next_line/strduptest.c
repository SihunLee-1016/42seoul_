#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void ft_strcpy_n(char *res, char *buffer, int len);
 
int	ft_strdup(char *res,char *buffer)
{
	int	len;
	
	len = 0;
	while (*(buffer + len) != '\n')
		len++;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == 0)
		return (0);
	ft_strcpy_n(res, buffer, len);
    printf("in dup = %s\n", res);
	return (len);
}

void ft_strcpy_n(char *res, char *buffer, int len)
{
	int	i;

	i = 0;
	while (*(buffer + i) != '\0' && i < len)
	{
		*(res + i) = *(buffer + i);
		i++;
		len++;
	}
	*(res + i) = '\0';
}

int main (){
    char a[]="hello 123";
    char *p;
    int b;
    b = ft_strdup(p,a);
    printf("%d \n%s",b,p);
}