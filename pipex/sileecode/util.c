/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:58:40 by silee             #+#    #+#             */
/*   Updated: 2022/05/01 18:00:30 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	i = 0;
	while (n-- > 0)
	{
		if (tmp1[i] != tmp2[i])
			return (tmp1[i] - tmp2[i]);
		else if (tmp1[i] == 0)
			return (tmp1[i] - tmp2[i]);
		else if (tmp2[i] == 0)
			return (tmp1[i] - tmp2[i]);
		i++;
	}
	return (0);
}

int	idx_of_c(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *)malloc(sizeof(char) * (n + 1));
	if (p == 0)
		return (0);
	while (*(src + i) != '\0' && i < n)
	{
		*(p + i) = *(src + i);
		i++;
	}
	*(p + i) = '\0';
	return (p);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		write (fd, &s[i++], 1);
	write (fd, "\n", 1);
}

void	ft_make_exit(int status, char *message)
{
	if (message)
		ft_putstr(message, status);
	exit(status);
}
