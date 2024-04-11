/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:28:31 by tkafanov          #+#    #+#             */
/*   Updated: 2024/04/11 14:42:32 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*ptr_res;

	if (!lst || !f)
		return (0);
	res = ft_lstnew(f(lst->content));
	if (!res)
		return (0);
	ptr_res = res;
	lst = lst->next;
	while (lst)
	{
		ptr_res->next = ft_lstnew(f(lst->content));
		if (!(ptr_res->next))
		{
			ft_lstclear(&res, del);
			return (0);
		}
		ptr_res = ptr_res->next;
		lst = lst->next;
	}
	return (res);
}
