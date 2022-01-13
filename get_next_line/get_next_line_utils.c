/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:39:01 by silee             #+#    #+#             */
/*   Updated: 2022/01/13 15:35:15 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char	*gnl_next(char **next)
{
	int		line_len;
	int		end;
 	char	*res;

	end = 0;
	line_len = 0;
	while (end != 1)
	{
		res = ft_strdup(*next, &line_len);
		if (line_len == -1)
			return (0);
		*next += line_len;
		if (**next == '\n' || res == 0)
			end = 1;
		if (**next == '\n')
			*next += 1;
		if (**next == '\0')
			*next = 0;
	}
	return (res);
}

char	*ft_strdup(char *buffer, int *line_len)
{
	int		i;
	char	*p;

	i = 0;
	while (*(buffer + i) != '\n')
		i++;
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (p == 0)
	{
		*line_len = -1;
		return (0);
	}
	ft_strncpy(p, buffer, i);
	*line_len = i;
	return (p);
}

char	*ft_strncpy(char *ret, char *buffer, int len)
{
	int	i;

	i = 0;
	while (*(buffer + i) != '\0' && i < len)
	{
		*(ret + i) = *(buffer + i);
		i++;
		len++;
	}
	*(ret + i) = '\0';
	return (ret);
}
