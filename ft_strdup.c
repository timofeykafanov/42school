/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:23:52 by tkafanov          #+#    #+#             */
/*   Updated: 2024/04/04 13:33:05 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	const char	*dup_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	dup_str = (char *)malloc((len + 1) * sizeof(char));
	if (dup_str == NULL)
		return (NULL);
	while (src[i])
	{
		dup_str[i] = src[i];
		i++;
	}
	dup_str[i] = '\0';
	return (dup_str);
}
