/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:21:42 by tkafanov          #+#    #+#             */
/*   Updated: 2024/04/11 10:18:17 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	s;
	size_t	d;

	dlen = 0;
	slen = 0;
	s = 0;
	d = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	d = dlen;
	if (size <= dlen)
		return (slen + size);
	if (size > 0)
	{
		while (src[s] && d < size - 1)
		{
			dst[d] = src[s];
			s++;
			d++;
		}
	}
	dst[d] = 0;
	return (dlen + slen);
}
