/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:38:54 by silee             #+#    #+#             */
/*   Updated: 2022/01/19 16:35:39 by silee            ###   ########.fr       */
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
	int			signal;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	tmp = 0;
	signal = 0;
	while (signal == 0 || byte != 0)
	{
		if (!(next)) 
		{
			byte = read(fd, buffer, BUFFER_SIZE);
			if (byte == -1)
				return (0);
			buffer[byte] = '\0';
			next = buffer;
		}
		ret = gnl_next(next, &tmp, &signal);
		// 오류가 발생한 경우 signal은 -1이 되므로 에러 발생시 null 반환.
		if (signal == -1 || ret == 0) 
			return (0);
	}
	return (ret);
}

// signal = 0 : 초기 상태. gnl_next함수를 거쳤음에도 signal이 0이라면 반복.
// signal = -1: tmp이어 붙히는건 성공했지만 ret
//				 or tmp 할당이 실패한 경우 혹은 tmp에 이어 붙히는것이 실패한 경우.
// signal = 2 : gnl_next함수에서 while문 안을 제대로 돌고, 반환 할 값이 제대로 할당 된 경우
//				2로 초기화 해주며 탈출.