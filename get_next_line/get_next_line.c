/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:41:10 by tkafanov          #+#    #+#             */
/*   Updated: 2024/04/29 12:52:07 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

#include "get_next_line.h"

char	*extract_line(char *buffer)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	len++;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		str[i] = buffer[i];
	str[i] = '\0';
	return (str);
}

char	*return_line(char **buffer)
{
	char	*line;
	char	*tmp;

	line = extract_line(*buffer);
	if (!line)
		return (free_and_null(buffer), NULL);
	tmp = ft_strdup(*buffer + ft_strlen(line));
	free_and_null(buffer);
	*buffer = tmp;
	if (*buffer && !(*buffer)[0])
		free_and_null(buffer);
	return (line);
}

int	read_text(int fd, char **buffer)
{
	char	*temp;
	char	*tmp;
	int		bytes_read;

	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (free_and_null(buffer), 0);
	bytes_read = read(fd, temp, BUFFER_SIZE);
	if (bytes_read == 0)
		return (free(temp), 2);
	if (bytes_read < 0)
		return (free_and_null(&temp), free_and_null(buffer), 0);
	temp[bytes_read] = '\0';
	tmp = ft_strdup(*buffer);
	if (!tmp)
		return (free_and_null(&temp), free_and_null(buffer), 0);
	free_and_null(buffer);
	*buffer = ft_strjoin(&tmp, &temp);
	return (1);
}

char	*last_line(char **buffer)
{
	char	*line;

	if (!(*buffer))
		return (NULL);
	line = ft_strdup(*buffer);
	if (!line)
	{
		return (free_and_null(buffer), NULL);
	}
	free_and_null(buffer);
	if (*line)
		return (line);
	else
		return (free_and_null(&line), NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	int			read_to_end;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer && include_n(buffer))
			return (return_line(&buffer));
		read_to_end = read_text(fd, &buffer);
		if (!read_to_end)
			return (free_and_null(&buffer), NULL);
		if (read_to_end == 2)
			return (last_line(&buffer));
	}
}
