/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qqq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:38:54 by silee             #+#    #+#             */
/*   Updated: 2022/01/11 15:17:09 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER 100
int	len_bf_next(char *str)
{
	int	len;

	len = 0;
	while (str[len] = '\n')
		len++;
	return (len);
}

char    *get_next_line(int fd)
{
    ssize_t 	num;
	static char	str[BUFFER + 1];
	static char	*next;
    char		*res;
	int			len;

	if(!(num = read(fd, &str, BUFFER) >= 0))
		return (0);
	str[num] = '\0';
	len = len_bf_next(str);
	printf("%d",len);
}


int main(){
    char a[] = "abc\ndef\nghi";
 

}
