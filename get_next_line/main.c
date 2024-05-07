/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:12:33 by tkafanov          #+#    #+#             */
/*   Updated: 2024/04/29 12:13:19 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// #include <stdio.h>
// #include <fcntl.h>
// #include "get_next_line.h"

// int	main(void)
// {
// 	char	*line;
// 	int		fd;
// 	// int		i;

// 	// i = 0;
// 	fd = open("empty.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// }


// #include <stdio.h>
// #include <fcntl.h>
// #include "get_next_line.h"

// int	main(void)
// {
// 	char	*line;
// 	int		fd;
// 	// int		i;

// 	// i = 0;
// 	fd = open("empty.txt", O_RDONLY);
//     line = get_next_line(fd);
//     printf("Line: %s", line);
//     free(line);
//     line = get_next_line(fd);
//     printf("Line: %s", line);
//     free(line);
//     do {
//         line = get_next_line(fd);
//         free(line);
//     } while (line != NULL);
//     close(fd);
//     fd = open("empty.txt", O_RDONLY);
//     line = get_next_line(fd);
//     printf("Line: %s", line);
//     free(line);
//     line = get_next_line(fd);
//     printf("Line: %s", line);
//     free(line);
//     line = get_next_line(fd);
//     printf("Line: %s", line);
//     free(line);
//     line = get_next_line(fd);
//     printf("Line: %s", line);
//     free(line);
//     line = get_next_line(fd);
//     printf("Line: %s", line);
//     free(line);
//     close(fd);
//     printf("\n");
// 	// if (fd == -1)
// 	// {
// 	// 	printf("fd error");
// 	// 	return (1);
// 	// }
// 	// while (1)
// 	// {
//     //     line = get_next_line(fd);
//     //     if (!line)
//     //         break;
// 	// 	printf("Line: %s", line);
// 	// 	free(line);
// 	// 	i++;
// 	// }
//     // close(fd);

// 	// line = get_next_line(fd);
// 	// printf("Line: %s", line);
// 	// free(line);
// 	// line = get_next_line(fd);
// 	// printf("Line: %s", line);
// 	// free(line);
// 	// line = get_next_line(fd);
// 	// printf("Line: %s", line);
// 	// free(line);
// 	// while ((line = get_next_line(0)) != NULL)
// 	// {
// 	// 	printf("Line: %s", line);
// 	// 	free(line);
// 	// }
// 	// line = get_next_line(2);
// 	// printf("Line: %s\n", line);
// 	// free(line);
// 	// line = get_next_line(2);
// 	// printf("Line: %s\n", line);
// 	// free(line);
// 	return (0);
// }
