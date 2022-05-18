/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: silee <silee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:29:41 by silee             #+#    #+#             */
/*   Updated: 2021/11/25 16:10:42 by silee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*next;

	curr = *lst;
	if (lst == 0 || del == 0)
		return ;
	while (curr != 0)
	{
		next = curr->next;
		del(curr->content);
		free (curr);
		curr = next;
	}
	*lst = 0;
}
