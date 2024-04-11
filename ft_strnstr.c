/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:23:16 by tkafanov          #+#    #+#             */
/*   Updated: 2024/04/04 15:20:17 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

const char	*ft_strnstr(const char *big, const char *little, size_t len)
{

	size_t i;
    size_t j;

    if (!*little)
        return (big);
    i = 0;
    while (big[i] && i < len)
    {
        j = 0;
        while (big[i + j] == little[j] && little[j] && i + j < len)
            j++;
        if (!little[j])
            return (&big[i]);
        i++;
    }
    return (0);
}