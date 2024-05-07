/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:41:19 by tkafanov          #+#    #+#             */
/*   Updated: 2024/04/30 08:50:00 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_and_null(char **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
	}
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	include_n(char *s)
{
	while (s && *s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strjoin(char **s1, char **s2)
{
	char	*res;
	int		i;
	int		j;

	res = (char *)malloc(sizeof(char) * (ft_strlen(*s1) + ft_strlen(*s2) + 1));
	if (!res)
		return (free_and_null(s1), free_and_null(s2), NULL);
	i = 0;
	while ((*s1)[i])
	{
		res[i] = (*s1)[i];
		i++;
	}
	j = 0;
	while ((*s2)[j])
	{
		res[i + j] = (*s2)[j];
		j++;
	}
	res[i + j] = '\0';
	free_and_null(&(*s1));
	free_and_null(&(*s2));
	return (res);
}

char	*ft_strdup(char *s)
{
	char	*dup_str;
	int		len;
	int		i;

	i = 0;
	if (!s)
		s = "";
	len = ft_strlen(s);
	dup_str = (char *)malloc((len + 1) * sizeof(char));
	if (!dup_str)
		return (NULL);
	while (s[i])
	{
		dup_str[i] = s[i];
		i++;
	}
	dup_str[i] = '\0';
	return (dup_str);
}
