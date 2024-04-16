/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:21:31 by tkafanov          #+#    #+#             */
/*   Updated: 2024/04/11 10:10:18 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	while (*src && size > 1)
	{
		*dst++ = *src++;
		size--;
		len++;
	}
	if (size > 0)
		*dst = 0;
	while (*src)
	{
		src++;
		len++;
	}
	return (len);
}
