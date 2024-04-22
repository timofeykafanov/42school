/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:00:22 by tkafanov          #+#    #+#             */
/*   Updated: 2024/04/19 14:32:12 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
char	*ft_itoa_u(unsigned int n);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
void	ft_putstr(char *str, int *count);
void	ft_putchar(char c, int *count);
void	handle_c(va_list type, int *count);
void	handle_s(va_list type, int *count);
void	handle_d_and_i(va_list type, int *count);
void	handle_u(va_list type, int *count);
void	handle_p(va_list type, int *count, char chr);
void	put_hex(unsigned long num, char chr, int *count);
void	handle_x(va_list type, int *count, char chr);
void	handle_percent(int *count);

#endif
