/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:53:05 by silee             #+#    #+#             */
/*   Updated: 2022/05/04 20:47:18 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	idx_of_c(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (i);
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

char	*make_path(char *tmp, char *cmd)
{
	char	*path;
	int		i;
	int		j;

	if (tmp == 0)
		return (0);
	i = 0;
	j = 0;
	path = (char *)malloc(sizeof(char) * (idx_of_c(tmp, 0) \
	+ idx_of_c(cmd, 0) + 2));
	if (path == 0)
		return (0);
	while (tmp[j] != '\0')
		path[i++] = tmp[j++];
	path[i++] = '/';
	j = 0;
	while (cmd[j])
		path[i++] = cmd[j++];
	path[i] = '\0';
	return (path);
}

char	*find_path(char *cmd, char **envp)
{
	char	*path;
	char	*tmp;
	char	*ret_path;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	path = envp[i] + 5;
	while (path && idx_of_c(path, ':') > -1)
	{
		tmp = ft_strndup(path, idx_of_c(path, ':'));
		ret_path = make_path(tmp, cmd);
		if (tmp == 0 || ret_path == 0)
			return (0);
		else
			free (tmp);
		if (access(ret_path, F_OK) == 0)
			return (ret_path);
		free (ret_path);
		path += idx_of_c(path, ':') + 1;
	}
	return (NULL);
}
