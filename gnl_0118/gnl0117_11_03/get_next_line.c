/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:38:54 by silee             #+#    #+#             */
/*   Updated: 2022/01/18 15:02:59 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static char	*next;
	char		*tmp;
	char		*ret;
	int			byte;
	int			status;
	int			signal;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	tmp = 0;
	while (1)
	{
		//next를 gnl_next에서 값 변경 필요.
		if (!(next)) 
		{
			byte = read(fd, buffer, BUFFER_SIZE);
			if (byte == -1 || byte == 0)
				return (0);
			buffer[byte] = '\0';
			next = buffer;
		}
		ret = gnl_next(next, &tmp, signal);
		if (ret != 0 || signal == -1) //signal이 -1이고 tmp에 뭔가 있다 -> free
			break ;
	}
	return (ret);
}
