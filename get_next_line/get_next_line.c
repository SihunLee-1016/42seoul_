/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:38:54 by silee             #+#    #+#             */
/*   Updated: 2022/01/13 15:57:36 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static char	*next;
	char		*ret;
	int			byte;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!(next))
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
			return (0);
		buffer[byte] = '\0';
		next = buffer;
	}
	ret = gnl_next(&next);
	if (next == 0 || ret == 0)
		return (0);
	return (ret);
}
