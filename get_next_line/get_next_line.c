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
# define BUFFER_SIZE 42
#endif

#include "get_next_line.h"

// char	*get_next_line(int fd)
// {
// 	static char	*previous;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	previous = (char *)malloc(BUFFER_SIZE + 1);
// }

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static int	position = 0;
	static int	bytes_read = 0;
	char		*line;
	int			i;
	int			j;
	int			line_length;

	i = position;
	while (1)
	{
		if (position == bytes_read)
		{
			position = 0;
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read <= 0)
				return (NULL);
			buffer[bytes_read] = '\0';
		}
		while (buffer[position] != '\n' && buffer[position] != '\0')
			position++;
		line_length = position - i;
		line = (char *)malloc(line_length + 1);
		if (!line)
			return (NULL);
		j = 0;
		while (i < position)
			line[j++] = buffer[i++];
		line[line_length] = '\0';
		position++;
		if (buffer[i] == '\n')
			return (line);
		free(line);
	}
	return (NULL);
}
