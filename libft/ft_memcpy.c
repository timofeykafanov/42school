/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:21:01 by tkafanov          #+#    #+#             */
/*   Updated: 2024/04/11 11:15:58 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*pdest;
	const unsigned char	*psrc;

	if (!dest && !src && n != 0)
		return (dest);
	i = 0;
	pdest = dest;
	psrc = src;
	while (i < n)
	{
		pdest[i] = psrc[i];
		i++;
	}
	return (dest);
}
