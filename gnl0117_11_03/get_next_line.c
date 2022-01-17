/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:38:54 by silee             #+#    #+#             */
/*   Updated: 2022/01/17 11:00:21 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static char	*next;
	static char fin;
	char		*ret;
	int			byte;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!(next) && fin == 0)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
			return (0);
		buffer[byte] = '\0';
		next = buffer;
		fin = 1;
	}
	ret = gnl_next(&next, fin);
	if (ret != 0 && next == 0)
		fin = 2;
	if (ret == 0)
		return (0);
	return (ret);
}
