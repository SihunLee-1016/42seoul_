/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:30:11 by silee             #+#    #+#             */
/*   Updated: 2022/05/01 19:37:26 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	num_of_split(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			cnt += 1;
			while (s[i] && s[i] == c)
				i++;
		}
		else
			i++;
	}
	if (i != 0 && s[i - 1] != c)
		cnt += 1;
	return (cnt);
}

size_t	len_of_str(char const *s, char c)
{
	int	len;

	len = 0;
	while (s != 0 && *s == c)
		s++;
	while (*s != '\0')
	{
		if (*s == c)
			break ;
		len += 1;
		s++;
	}
	return (len);
}

char	**free_all(char **s)
{
	int	i;

	i = 0;
	while (s[i++] != 0)
		free(s[i]);
	free (s);
	return (0);
}

unsigned int	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (src[len] != '\0')
		len += 1;
	if (size <= 0)
		return (len);
	while (i < len && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		nos;
	size_t	len;
	size_t	i;

	i = 0;
	if (s == 0)
		return (0);
	nos = num_of_split(s, c);
	res = (char **)ft_calloc((nos + 1), sizeof(char *));
	if (res == 0)
		return (0);
	while (nos-- > 0)
	{
		while (*s != '\0' && *s == c)
			s++;
		len = len_of_str (s, c) + 1;
		res[i] = ft_calloc(sizeof(char), len);
		if (res[i] == 0)
			return (free_all(res));
		ft_strlcpy(res[i++], s, len);
		s = s + len - 1;
	}
	return (res);
}
