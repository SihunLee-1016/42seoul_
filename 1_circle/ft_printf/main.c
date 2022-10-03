#include "./includes/ft_printf.h"
#include <stdio.h>
int main()
{
	int res = 0;
	res = ft_printf("Magic %s is %d", "number", 42);

	printf("%d", res);
}
