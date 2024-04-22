/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p_x_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:28:23 by tkafanov          #+#    #+#             */
/*   Updated: 2024/04/19 14:28:25 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	to_hex_string(unsigned long value, char *buffer)
// {
// 	char			*hex_digits;
// 	int				len;
// 	unsigned long	temp;
// 	int				num_digits;
// 	char			hex_digit;

// 	hex_digits = ft_strdup("0123456789abcdef");
// 	if (!hex_digits)
// 		return (0);
// 	len = 0;
// 	temp = value;
// 	num_digits = 0;
// 	while (temp != 0)
// 	{
// 		temp >>= 4;
// 		num_digits++;
// 	}
// 	while (num_digits > 0)
// 	{
// 		hex_digit = hex_digits[(value >> ((num_digits - 1) * 4)) & 0xf];
// 		buffer[len++] = hex_digit;
// 		num_digits--;
// 	}
// 	free(hex_digits);
// 	return (len);
// }

// void	handle_p(va_list type, int *count)
// {
// 	void			*ptr;
// 	char			buffer[20];
// 	int				len;
// 	unsigned long	addr;

// 	ptr = va_arg(type, void *);
// 	if (!ptr)
// 	{
// 		ft_putstr("(nil)", count);
// 		return ;
// 	}
// 	addr = (unsigned long)ptr;
// 	len = to_hex_string(addr, buffer);
// 	ft_putstr("0x", count);
// 	*count += write(1, buffer, len);
// }

// void	put_hex(unsigned long num, int *count)
// {
// 	if (num >= 16)
// 	{
// 		put_hex(num / 16, count);
// 		put_hex(num % 16, count);
// 	}
// 	else
// 	{
// 		if (num <= 9)
// 			ft_putchar(num + '0', count);
// 		else
// 			ft_putchar(num - 10 + 'a', count);
// 	}
// }

void	put_hex(unsigned long num, char chr, int *count)
{
	if (num >= 16)
	{
		put_hex(num / 16, chr, count);
		put_hex(num % 16, chr, count);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0', count);
		else
		{
			if (chr == 'X')
				ft_putchar(num - 10 + 'A', count);
			else
				ft_putchar(num - 10 + 'a', count);
		}
	}
}

void	handle_p(va_list type, int *count, char chr)
{
	unsigned long	num;

	num = va_arg(type, unsigned long);
	if (!num)
		ft_putstr("(nil)", count);
	else
	{
		ft_putstr("0x", count);
		put_hex(num, chr, count);
	}
}

void	handle_x(va_list type, int *count, char chr)
{
	int long	num;

	num = va_arg(type, unsigned int);
	put_hex(num, chr, count);
}

void	handle_percent(int *count)
{
	ft_putchar('%', count);
}
