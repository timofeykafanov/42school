/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:22:33 by tkafanov          #+#    #+#             */
/*   Updated: 2024/04/11 10:06:47 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*match;

	match = 0;
	while (*s)
	{
		if (*s == (char)c)
			match = (char *)s;
		s++;
	}
	if (*s == (char)c)
		match = (char *)s;
	return (match);
}
