/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:38:19 by tkafanov          #+#    #+#             */
/*   Updated: 2024/04/02 14:38:20 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char    *str;
    int     i;
    int     len;

    if (!s || !f)
        return (NULL);
    len = 0;
    while (s[len])
        len++;
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    i = 0;
    while (i < len)
    {
        str[i] = f(i, s[i]);
        i++;
    }
    str[i] = '\0';
    return (str);
}