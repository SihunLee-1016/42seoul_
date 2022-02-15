#include "ft_printf.h"
void	*ft_calloc(size_t count, size_t size)
{
	int		i;
	char	*p;

	p = malloc(count * size);
	if (p == 0)
		return (0);
	i = count * size;
	ft_bzero(p, i);
	return (p);
}