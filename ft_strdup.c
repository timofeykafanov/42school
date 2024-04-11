/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:23:52 by tkafanov          #+#    #+#             */
/*   Updated: 2024/04/04 15:18:20 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup_str;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s);
	dup_str = (char *)malloc((len + 1) * sizeof(char));
	if (dup_str == NULL)
		return (NULL);
	while (s[i])
	{
		dup_str[i] = s[i];
		i++;
	}
	dup_str[i] = '\0';
	return (dup_str);
}
