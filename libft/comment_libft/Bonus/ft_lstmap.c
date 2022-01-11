/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:29:27 by silee             #+#    #+#             */
/*   Updated: 2021/12/21 13:12:58 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// 리스트 'lst'의 요소들을 순회하며 각 요소의 content에 함수 'f'를 연속적으로 적용시킵니다. 
// 또한 함수 'f'를 적용시킨 결과물들을 content로 담은 새로운 리스트를 생성합니다. 
// 'del' 함수들은 필요 시 각 요소의 content를 삭제하는 데 사용됩니다.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	if (lst == 0 || f == 0)
		return (0);
	//lstnew에서 할당이 실패한 경우 종료. 아니라면 f함수를 적용시켜 새롭게 추가.
	new = ft_lstnew(f(lst->content));
	if (new == 0)
		return (0);
	lst = lst->next;
	//리스트를 순회하며 각 요소의 content에 함수 f를 적용.
	// 적용시킨 결과물들을 새로 만들어진 리스트에 저장.
	while (lst != 0)
	{
		tmp = ft_lstnew(f(lst->content));
		//만약 제대로 저장이 되지 않았다면
		if (tmp == 0)
		{
			//clear함수에 del 함수를 인자로 전달해 리스트 삭제.
			ft_lstclear(&new, del);
			return (0);
		}
		//함수를 적용시킨 리스트의 content를 이어붙힌다.
		ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}
