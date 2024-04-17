/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:03:44 by tkafanov          #+#    #+#             */
/*   Updated: 2024/04/17 15:33:09 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"
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
	//free(str);
}

void	handle_d_and_i(va_list type, int *count)
{
	char	*str;

	str = ft_itoa(va_arg(type, int));
	ft_putstr(str, count);
	free(str);
}

void	define_format(char chr, va_list type, int *count)
{
	if (chr == 'c')
	{
		handle_c(type, count);
	}
	else if (chr == 's')
	{
		handle_s(type, count);
	}
	else if (chr == 'd' || chr == 'i')
	{
		handle_d_and_i(type, count);
	}
}

int	ft_printf(const char *s, ...)
{
	int			i;
	int			count;
	va_list		type;

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

int	main(void)
{
	int ft_print;
	int print;

	print = printf("Char: %c\nString: %s\n\n", 'A', "");
	ft_print = ft_printf("Char: %c\nString: %s\n\n", 'A', "");
	print += printf("Digit: %d\nInteger: %i\n\n", 0, 0);
    ft_print += ft_printf("Digit: %d\nInteger: %i\n\n", 0, 0);


	printf("%d = %d", ft_print, print);
}
