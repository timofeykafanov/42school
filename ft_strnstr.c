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
	size_t	little_len;
	size_t	i;
	size_t	j;

	if (!(*little))
		return (big);
	little_len = 0;
	while (little[little_len])
		little_len++;
	i = 0;
	while (i <= len - little_len && big[i])
	{
		j = 0;
		while (j < little_len)
		{
			if (big[i + j] != little[j])
				break ;
			j++;
		}
		if (j == little_len)
			return (&big[i]);
		i++;
	}
	return (0);
}
