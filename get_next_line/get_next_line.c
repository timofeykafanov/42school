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

// char	*read_stdin(int fd)
// {
// 	char 	*buffer;
// 	char	*temp;
// 	int		bytes_read;

// 	buffer = (char *)malloc(BUFFER_SIZE + 1);
//     if (!buffer)
// 		return NULL;
//     *buffer = '\0';
// 	while (1)
// 	{
// 		if (ft_strchr(buffer, '\n'))
// 		{
// 			return (buffer);
// 		}
// 		temp = (char *)malloc(BUFFER_SIZE + 1);
// 		if (!temp)
// 			return(NULL);
// 		bytes_read = read(fd, temp, BUFFER_SIZE);
// 		buffer = ft_strjoin(&buffer, &temp);
// 	}
// }

// char	*read_text(int fd)
// {
// 	static char	*buffer;
// 	static int	is_end = 0;
// 	char		*temp;
// 	char		*tmp;
// 	char		*line;
// 	int			bytes_read;

// 	while (1)
// 	{
// 		if (buffer && ft_strchr(buffer, '\n'))
// 		{
// 			line = extract_line(buffer);
// 			if (!line)
// 				return (free_and_null(&buffer), NULL);
// 			tmp = ft_strdup(buffer + ft_strlen(line));
// 			free_and_null(&buffer);
// 			buffer = tmp;
// 			if (buffer && !buffer[0])
// 				free_and_null(&buffer);
// 			return (line);
// 		}
// 		if (is_end)
// 		{
// 			if (is_end == 2)
// 				return (NULL);
// 			else
// 			{
// 				is_end = 2;
// 				return (buffer);
// 			}
// 		}
// 		if (!is_end)
// 		{
// 			temp = (char *)malloc(BUFFER_SIZE + 1);
// 			if (!temp)
// 				return (free_and_null(&buffer), NULL);
// 			bytes_read = read(fd, temp, BUFFER_SIZE);
// 			if (bytes_read < BUFFER_SIZE)
// 				is_end = 1;
// 			if (bytes_read < 0)
// 				return (free_and_null(&temp), free_and_null(&buffer), NULL);
// 			temp[bytes_read] = '\0';
// 			if (buffer)
// 			{
// 				tmp = ft_strdup(buffer);
// 				if (!tmp)
// 					return (free_and_null(&temp), free_and_null(&buffer), NULL);
// 			}
// 			else
// 			{
// 				tmp = ft_strdup("");
// 				if (!tmp)
// 					return (free_and_null(&temp), free_and_null(&buffer), NULL);
// 			}
// 			free_and_null(&buffer);
// 			buffer = ft_strjoin(&tmp, &temp);
// 		}
// 	}
// }

char	*return_line(char **buffer)
{
	char	*line;
	char	*tmp;

	line = extract_line(*buffer);
	if (!line)
		return (free_and_null(buffer), printf("%p\n", *buffer), NULL);
	tmp = ft_strdup(*buffer + ft_strlen(line));
	free_and_null(buffer);
	*buffer = tmp;
	if (*buffer && !(*buffer)[0])
		free_and_null(buffer);
	return (printf("%p\n", *buffer), line);
}

int	read_text(int fd, char **buffer, int *is_end)
{
	char	*temp;
	char	*tmp;
	int		bytes_read;

	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (free_and_null(buffer), 0);
	bytes_read = read(fd, temp, BUFFER_SIZE);
	if (bytes_read < BUFFER_SIZE)
		*is_end = 1;
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

char	*last_line(char **buffer, int *is_end)
{
	char	*line;

	if (*is_end == 2)
	{
		*is_end = 0;
		return (NULL);
	}
	else
	{
		*is_end = 2;
		line = ft_strdup(*buffer);
		if (!line)
		{
			*is_end = 0;
			return (free_and_null(buffer), NULL);
		}
		free_and_null(buffer);
		if (*line)
			return (printf("%p\n", *buffer), line);
		else
			return (free_and_null(&line), printf("%p\n", *buffer), NULL);
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	static int	is_end = 0;
	static int	last_fd = -1;

	if (fd < 0 || fd > 99 || BUFFER_SIZE <= 0)
		return (NULL);
	if (last_fd != fd)
	{
		buffer = NULL;
		is_end = 0;
		last_fd = fd;
	}
	while (1)
	{
		if (buffer && include_n(buffer))
			return (return_line(&buffer));
		if (is_end)
			return (last_line(&buffer, &is_end));
		if (!is_end)
		{
			if (!read_text(fd, &buffer, &is_end))
				return (printf("%p\n", buffer), NULL);
		}
	}
}

// char	*extract_line(char *buffer, int position, char *line)
// {
// 	int	i;
// 	int	j;
// 	int	line_length;

// 	i = position;
// 	while (buffer[position] != '\n' && buffer[position] != '\0')
// 		position++;
// 	line_length = position - i;
// 	line = (char *)malloc(line_length + 1);
// 	if (!line)
// 		return (NULL);
// 	j = 0;
// 	while (i < position)
// 		line[j++] = buffer[i++];
// 	position++;
// 	if (buffer[i] == '\n' && i <= BUFFER_SIZE)
// 	{
// 		line[j] = '\n';
// 		line[line_length + 1] = '\0';
// 		return (line);
// 	}
// 	if (buffer[i] == '\0' && i <= BUFFER_SIZE)
// 		return (line);
// 	return (NULL);
// }

// char	*get_next_line(int fd)
// {
// 	static char	buffer[BUFFER_SIZE + 1];
// 	static int	position = 0;
// 	static int	bytes_read = 0;
// 	char		*line;

// 	line = NULL;
// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	while (1)
// 	{
// 		if (position == bytes_read)
// 		{
// 			position = 0;
// 			bytes_read = read(fd, buffer, BUFFER_SIZE);
// 			if (bytes_read <= 0)
// 				return (NULL);
// 			buffer[bytes_read] = '\0';
// 		}
// 		line = extract_line(buffer, position, line);
// 		if (!line)
// 			return (NULL);
// 		position += ft_strlen(line);
// 		return (line);
// 		free(line);
// 	}
// 	return (NULL);
// }
