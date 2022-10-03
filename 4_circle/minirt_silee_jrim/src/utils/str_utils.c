/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:31:45 by silee             #+#    #+#             */
/*   Updated: 2022/09/24 10:31:46 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	rt_strcmp(const char *s1, const char *s2)
{
	int	idx;

	idx = 0;
	while (s1[idx] != '\0' || s2[idx] != '\0')
	{
		if (s1[idx] != s2[idx])
			return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
		idx++;
	}
	return (0);
}

int	rt_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

static void	make_strs(char **strs, int idx, char **ptr, char c)
{
	int	len;

	len = 0;
	while ((*ptr)[len] != c && (*ptr)[len] != '\0')
		len++;
	strs[idx] = (char *)malloc((len + 1) * sizeof(char));
	if (!(strs[idx]))
		err_exit("cannot allocate memory (split)\n");
	len = 0;
	while (**ptr != c && **ptr != '\0')
	{
		strs[idx][len] = **(ptr);
		len++;
		(*ptr)++;
	}
	strs[idx][len] = '\0';
}

static int	count_str(char const *s, char c)
{
	int	idx;
	int	cnt;
	int	flag;

	idx = 0;
	cnt = 0;
	flag = 1;
	while (s[idx] != '\0')
	{
		if (s[idx] != c && flag == 1)
		{
			cnt++;
			flag = 0;
		}
		else if (s[idx] == c && flag == 0)
			flag = 1;
		idx++;
	}
	return (cnt);
}

char	**rt_split(char const *s, char c)
{
	char	**strs;
	char	*ptr;
	int		idx;
	int		str_cnt;

	if (!s)
		return (NULL);
	ptr = (char *)s;
	str_cnt = count_str(s, c) + 1;
	strs = (char **)malloc(str_cnt * sizeof(char *));
	if (!(strs))
		err_exit("cannot allocate memory (split)\n");
	idx = 0;
	while (idx < str_cnt - 1 && *ptr != '\0')
	{
		while (*ptr == c && *ptr != '\0')
			ptr++;
		make_strs(strs, idx, &ptr, c);
		idx++;
	}
	strs[idx] = 0;
	return (strs);
}
