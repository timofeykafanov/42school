/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:41:29 by tkafanov          #+#    #+#             */
/*   Updated: 2024/04/30 08:50:59 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strchr(char *s, char c);
char	*ft_strjoin(char **s1, char **s2);
char	*ft_strdup(char *s);
void	free_and_null(char **p);
