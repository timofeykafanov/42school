/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:37:30 by tkafanov          #+#    #+#             */
/*   Updated: 2024/04/02 14:52:31 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(int size, char **strs, char *sep)
{
	int	i;
	int	res_len;
	int	str_len;
	int	sep_len;

	i = 0;
	res_len = 0;
	while (i < size)
	{
		str_len = 0;
		while (strs[i][str_len++])
			res_len++;
		if (i < size - 1)
		{
			sep_len = 0;
			while (sep[sep_len++])
				res_len++;
		}
		i++;
	}
	return (res_len);
}

void	ft_fill_str(int size, char **strs, char *sep, char *res)
{
	int	i;
	int	res_len;
	int	str_len;
	int	sep_len;

	i = 0;
	res_len = 0;
	while (i < size)
	{
		str_len = 0;
		while (strs[i][str_len])
			res[res_len++] = strs[i][str_len++];
		if (i < size - 1)
		{
			sep_len = 0;
			while (sep[sep_len])
				res[res_len++] = sep[sep_len++];
		}
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		res_len;
	char	*res;

	res_len = ft_strlen(size, strs, sep);
	if (res_len == 0)
		return (0);
	res = (char *)malloc((res_len + 1) * sizeof(char));
	if (res == 0)
		return (0);
	ft_fill_str(size, strs, sep, res);
	res[res_len] = '\0';
	return (res);
}
