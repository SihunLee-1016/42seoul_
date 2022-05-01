/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:53:05 by silee             #+#    #+#             */
/*   Updated: 2022/05/01 18:37:58 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"		

int	is_slash(char *commands)
{
	while (commands)
	{
		if (*commands == '/')
			return (-1);
		commands++;
	}
	return (1);
}

char	*make_path(char *tmp, char *cmd)
{
	char	*path;
	int		i;
	int		j;

	i = 0;
	j = 0;
	path = (char *)malloc(sizeof(char) * (idx_of_c(tmp, 0) \
		+ idx_of_c(cmd, 0) + 2));
	while (tmp[j] != '\0')
	{
		path[i] = tmp[j];
		j++;
		i++;
	}
	path[i] = '/';
	i += 1;
	j = 0;
	while (cmd[j])
	{
		path[i] = cmd[j];
		i++;
		j++;
	}
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
	while (envp[i] && ft_strncmp(envp[i], "PATH", 5))
		i++;
	if (!envp[i])
		return (NULL);
	path = envp[i] + 5;
	while (path && idx_of_c(path, ':') > -1)
	{
		tmp = ft_strndup(path, idx_of_c(path, ':'));
		ret_path = make_path(tmp, cmd);
		free (tmp);
		if (access(ret_path, F_OK) == 0)
			return (ret_path);
		free (ret_path);
		path += idx_of_c(path, ':') + 1;
	}
	return (cmd);
}
