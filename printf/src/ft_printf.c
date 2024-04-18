/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:03:44 by tkafanov          #+#    #+#             */
/*   Updated: 2024/04/18 14:27:10 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void	ft_putstr(char *str, int *count)
{
	while (*str)
	{
		write(1, &(*str), 1);
		str++;
		(*count)++;
	}
}

void	handle_c(va_list type, int *count)
{
	char	c;

	c = va_arg(type, int);
	write(1, &c, 1);
	(*count)++;
}

void	handle_s(va_list type, int *count)
{
	char	*str;

	str = va_arg(type, char *);
	if (!str)
	{
		ft_putstr("(null)", count);
		return ;
	}
	ft_putstr(str, count);
}

void	handle_d_and_i(va_list type, int *count)
{
	char	*str;

	str = ft_itoa(va_arg(type, int));
	if (!str)
		return ;
	ft_putstr(str, count);
	free(str);
}

int	to_hex_string(unsigned long value, char *buffer)
{
	char			*hex_digits;
	int				len;
	unsigned long	temp;
	int				num_digits;
	char			hex_digit;

	hex_digits = ft_strdup("0123456789abcdef");
	if (!hex_digits)
		return (0);
	len = 0;
	temp = value;
	num_digits = 0;
	while (temp != 0)
	{
		temp >>= 4;
		num_digits++;
	}
	while (num_digits > 0)
	{
		hex_digit = hex_digits[(value >> ((num_digits - 1) * 4)) & 0xf];
		buffer[len++] = hex_digit;
		num_digits--;
	}
	free(hex_digits);
	return (len);
}

void	handle_p(va_list type, int *count)
{
	void			*ptr;
	char			buffer[20];
	int				len;
	unsigned long	addr;

	ptr = va_arg(type, void *);
	if (!ptr)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	addr = (unsigned long)ptr;
	len = to_hex_string(addr, buffer);
	ft_putstr("0x", count);
	write(1, buffer, len);
	*count += len;
}

void	handle_u(va_list type, int *count)
{
	char    *str;

    str = ft_itoa_u(va_arg(type, unsigned int));
    if (!str)
        return ;
    ft_putstr(str, count);
    free(str);
}

void	define_format(char chr, va_list type, int *count)
{
	if (chr == 'c')
		handle_c(type, count);
	else if (chr == 's')
		handle_s(type, count);
	else if (chr == 'p')
		handle_p(type, count);
	else if (chr == 'd' || chr == 'i')
		handle_d_and_i(type, count);
	else if (chr == 'u')
		handle_u(type, count);
}

int	ft_printf(const char *s, ...)
{
	int			i;
	int			count;
	va_list		type;

	if (!s)
		return (-1);
	count = 0;
	va_start(type, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			define_format(s[i], type, &count);
			i++;
		}
		if (s[i] != '\0')
		{
			write(1, &s[i], 1);
			count++;
			i++;
		}
	}
	va_end(type);
	return (count);
}

