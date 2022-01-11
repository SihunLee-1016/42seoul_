
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:45:31 by silee             #+#    #+#             */
/*   Updated: 2022/01/11 15:19:19 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

// char	*ft_strdup(char *src,int *len)
// {
// 	 int	i;
// 	 char	*p;

// 	i = 0;
// 	while (*(src + i) != '\0')
// 		i++;
// 	p = (char *)malloc(sizeof(char) * (i + 1));
// 	if (p == 0)
// 		return (0);
// 	ft_strcpy(p, src);
// 	*len = i;
// 	return (p);
// }

char	*ft_strdup(char *ret, char *buffer, int *line_len)
{
	int	i;
	
	i = 0;
	while (*(buffer + i) != '\n')
		i++;
	ret = (char *)malloc(sizeof(char) * (i + 1));
	if (ret == 0)
	{
		//할당 실패했을 시 line_len을 -1로 초기화. 
		*line_len = -1;
		return (0);
	}
		
	ft_strcpy(ret, buffer);
	*line_len = i;
	return (ret);
}

int main(){

	char a[]="123";
	char *p;
	int len;
	printf("before fun p's adress = %p\n",p);
	p = ft_strdup(p,a,&len);
	//포인터 반환 함수를 사용하게 된다면
	//포인터가 함수 전 후로 주소값이 변경되게 된다.
	// p = function(~~) 구조라면
	// p = &a 처럼 주소값을 연결시켜줌.
	printf("after fun p's adress = %p\n",p);
	printf("p = %s\n",p);
	printf("len = %d",len);
}
// res = ft_strdup(ret, buffer, &line_len);
