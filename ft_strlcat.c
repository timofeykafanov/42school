/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:21:42 by tkafanov          #+#    #+#             */
/*   Updated: 2024/04/04 15:19:50 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;
	size_t	space_left;

	i = 0;
	dest_len = 0;
	src_len = 0;
	while (dst[dest_len])
		dest_len++;
	while (src[src_len])
		src_len++;
	if (size > dest_len)
		space_left = size - dest_len - 1;
	else
		space_left = 0;
	while (i < space_left && src[i])
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	if (size > 0)
		dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}
