/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:20:28 by tkafanov          #+#    #+#             */
/*   Updated: 2024/04/03 11:33:02 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	*p;

	p = ptr;
	i = 0;
	while (i < num)
	{
		p[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}
