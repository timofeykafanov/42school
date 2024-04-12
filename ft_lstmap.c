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
	t_list	*tmp;

	if (!lst || !f || !del)
		return (0);
	void *temp = f(lst->content);
	res = ft_lstnew(temp);
	if (!res)
		return (free(temp), NULL);
	ptr_res = res;
	res->next = NULL;
	lst = lst->next;
	while (lst)
	{
		temp = f(lst->content);
		tmp = ft_lstnew(temp);
		if (!tmp)
		{
			free(temp);
			ft_lstclear(&res, del);
			return (0);
		}
		tmp->next = NULL;
		ptr_res->next = tmp;
		ptr_res = ptr_res->next;
		lst = lst->next;
	}
	return (res);
}

// void *f(void *content)
// {
//     char *str = (char *)content;
//     char *uppercase_str = malloc(ft_strlen(str) + 1);
//     if (!uppercase_str)
//         return (NULL);
//     for (int i = 0; str[i]; i++)
//         uppercase_str[i] = ft_toupper(str[i]);
//     uppercase_str[ft_strlen(str)] = '\0';
//     return (uppercase_str);
// }

// // Function to free the memory allocated for a string
// void del(void *content)
// {
//     free(content);
// }

// int main()
// {
//     t_list *lst = ft_lstnew("hello");
//     ft_lstadd_back(&lst, ft_lstnew("world"));
//     ft_lstadd_back(&lst, ft_lstnew("this is a test"));

//     t_list *mapped_lst = ft_lstmap(lst, f, del);

//     t_list *ptr = mapped_lst;
//     while (ptr)
//     {
//         printf("%s\n", (char *)ptr->content);
//         ptr = ptr->next;
//     }

//     // Free the memory allocated for the mapped list content before freeing the list nodes
//     ptr = mapped_lst;
//     while (ptr)
//     {
//         t_list *next = ptr->next;
//         del(ptr->content);
//         free(ptr);
//         ptr = next;
//     }

//     ft_lstclear(&lst, del);

//     return 0;
// }