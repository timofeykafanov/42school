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
	else if (chr == 'x' || chr == 'X')
		handle_x(type, count, chr);
	else if (chr == '%')
		handle_percent(count);
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
		if (s[i] != '\0' && s[i] != '%')
		{
			count += write(1, &s[i], 1);
			i++;
		}
	}
	va_end(type);
	return (count);
}
