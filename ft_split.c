/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:37:54 by tkafanov          #+#    #+#             */
/*   Updated: 2024/04/02 14:54:49 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_is_separator(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	count;
	int	is_word;

	count = 0;
	is_word = 0;
	while (*str)
	{
		if (!ft_is_separator(*str, charset))
		{
			if (!is_word)
			{
				count++;
				is_word = 1;
			}
		}
		else
			is_word = 0;
		str++;
	}
	return (count);
}

void	ft_extract_words(char **res, int *i, char *start, char *end)
{
	int	len;
	int	j;

	len = end - start;
	j = 0;
	res[*i] = (char *)malloc((len + 1) * sizeof(char));
	if (res[*i] == NULL)
		return ;
	while (start < end)
		res[*i][j++] = *start++;
	res[*i][len] = '\0';
	(*i)++;
}

void	ft_fill_res(char **res, char *str, char *charset)
{
	int		i;
	char	*start;

	i = 0;
	start = NULL;
	while (*str)
	{
		if (!ft_is_separator(*str, charset))
		{
			if (!start)
				start = str;
		}
		else
		{
			if (start != NULL)
			{
				ft_extract_words(res, &i, start, str);
				start = NULL;
			}
		}
		str++;
	}
	if (start && *start)
		ft_extract_words(res, &i, start, str);
}

char	**ft_split(char *str, char *charset)
{
	int		words;
	char	**res;

	words = ft_count_words(str, charset);
	res = (char **)malloc((words + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	ft_fill_res(res, str, charset);
	return (res);
}
