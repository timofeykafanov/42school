#include <stdlib.h>
#include "libft.h"

// t_list *ft_lstnew(void *content)
// {
//     t_list *new;

//     new = (t_list *)malloc(sizeof(t_list));
//     if (!new)
//         return (NULL);
//     new->content = content;
//     new->next = NULL;
//     return (new);
// }

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new_lst;
    t_list *new_node;

    if (!lst || !f)
        return (NULL);
    new_lst = ft_lstnew(f(lst->content));
    if (!new_lst)
        return (NULL);
    new_node = new_lst;
    lst = lst->next;
    while (lst)
    {
        new_node->next = ft_lstnew(f(lst->content));
        if (!(new_node->next))
        {
            ft_lstclear(&new_lst, del);
            return (NULL);
        }
        new_node = new_node->next;
        lst = lst->next;
    }
    return (new_lst);
}