#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>    
int	num_len(unsigned long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void ft_address_print(unsigned long num, int len)
{
    int i;
	int	str[len];
    
	str[len] = 0;
	i = 0;
	while (len-- >= 0 && num != 0)
	{
		if (num >= 16)
			str[len] = num % 16;
		else
			str[len] = num;
		num = num / 16;
	}
	while (str[i])
	{
		if (str[i] >= 10 && str[i] <= 15)
			ft_putchar_fd((str[i] - 10 + 'a'), 1);
		else 
			ft_putchar_fd((str[i] + '0'), 1);
		i++;
	}
}
int main(){
    unsigned long num = 100;
    ft_address_print(num,num_len(num));
}