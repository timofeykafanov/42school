/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:37:16 by tkafanov          #+#    #+#             */
/*   Updated: 2024/04/02 14:37:18 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

// char	*ft_strdup(const char *s)
// {
// 	char	*dup_str;
// 	int		len;
// 	int		i;

// 	len = 0;
// 	i = 0;
// 	while (s[len])
// 		len++;
// 	dup_str = (char *)malloc((len + 1) * sizeof(char));
// 	if (dup_str == NULL)
// 		return (NULL);
// 	while (s[i])
// 	{
// 		dup_str[i] = s[i];
// 		i++;
// 	}
// 	dup_str[i] = '\0';
// 	return (dup_str);
// }

// size_t	ft_strlen(const char *str)
// {
// 	size_t	len;

// 	len = 0;
// 	while (*str)
// 	{
// 		len++;
// 		str++;
// 	}
// 	return (len);
// }

// #include <string.h>

// char    *ft_substr(char const *s, unsigned int start, size_t len)
// {
//     unsigned int     i;
//     char            *res;
//     size_t          s_len;
    
//     if (s == NULL)
//         return (NULL);
//     s_len = ft_strlen(s);
//     if (start >= s_len)
//         return (ft_strdup(""));
//     res = malloc(len + 1);
//     if (res == NULL)
//         return (NULL);
//     i = 0;
//     while (s[start + i] && i < len)
//     {
//         res[i] = s[start + i];
//         i++;
//     }
//     res[i] = '\0';
//     return (res);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*dup;
// 	size_t	c;

// 	dup = malloc(len + 1);
// 	if (!dup)
// 		return (0);
// 	if (start > ft_strlen(s) || len < 1)
// 	{
// 		ft_bzero(dup, len);
// 		return (dup);
// 	}
// 	c = 0;
// 	while (s[start + c] && c < len)
// 	{
// 		dup[c] = s[start + c];
// 		c++;
// 	}
// 	dup[c] = 0;
// 	return (dup);
// }

#include <string.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *res;
    size_t i;

    // Check if the starting index is out of bounds
    if (start >= strlen(s))
    {
        return strdup("");
    }

    // Allocate memory for the res
    res = (char *)malloc(sizeof(char) * (len + 1));
    if (!res)
    {
        return NULL;
    }

    // Copy the res from the original string
    i = 0;
    while (i < len && s[start + i] != '\0')
    {
        res[i] = s[start + i];
        i++;
    }
    res[i] = '\0';

    return res;
}

// #include <stdio.h>

// int main()
// {
//     printf("%s", ft_substr("", 0, 0));
//     //printf("%s", ft_substr("hola", 0, 18446744073709551615));
//     return (0);
// }