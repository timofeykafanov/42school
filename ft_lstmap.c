/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:28:31 by tkafanov          #+#    #+#             */
/*   Updated: 2024/04/11 11:29:53 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (!lst || !f)
		return (0);
	new_lst = ft_lstnew(f(lst->content));
	if (!new_lst)
		return (0);
	new_node = new_lst;
	lst = lst->next;
	while (lst)
	{
		new_node->next = ft_lstnew(f(lst->content));
		if (!(new_node->next))
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		new_node = new_node->next;
		lst = lst->next;
	}
	return (new_lst);
}
