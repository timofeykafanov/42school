/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c_s_d_i_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:22:07 by tkafanov          #+#    #+#             */
/*   Updated: 2024/04/19 14:27:16 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_c(va_list type, int *count)
{
	char	c;

	c = va_arg(type, int);
	*count += write(1, &c, 1);
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

void	handle_u(va_list type, int *count)
{
	char	*str;

	str = ft_itoa_u(va_arg(type, unsigned int));
	if (!str)
		return ;
	ft_putstr(str, count);
	free(str);
}
