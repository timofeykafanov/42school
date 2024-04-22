/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:40:25 by tkafanov          #+#    #+#             */
/*   Updated: 2024/04/19 14:40:28 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <limits.h>
// #include <stdio.h>
// #include "include/ft_printf.h"

// int	main(void)
// {
// 	int	i;
// 	int	*ptr;
// 	int	ft_print;
// 	int	print;

// 	i = 0;
// 	print = 0;
// 	ft_print = 0;
// 	ptr = &i;
// 	print +=       printf("Char: %c\n\n", 'A');
// 	ft_print += ft_printf("Char: %c\n\n", 'A');
// 	print +=       printf("String: %s\n\n", "QWERTY");
// 	ft_print += ft_printf("String: %s\n\n", "QWERTY");
// 	print +=       printf("String: %s\n\n", NULL);
// 	ft_print += ft_printf("String: %s\n\n", NULL);
// 	print +=       printf("Integer: %i\n\n", INT_MIN);
// 	ft_print += ft_printf("Integer: %i\n\n", INT_MIN);
// 	print +=       printf("Digit: %d\n\n", INT_MAX);
// 	ft_print += ft_printf("Digit: %d\n\n", INT_MAX);
// 	print +=       printf("Unsigned: %u\n\n", -5);
// 	ft_print += ft_printf("Unsigned: %u\n\n", -5);
// 	print +=       printf("Pointer: %p\n\n", ULONG_MAX);
// 	ft_print += ft_printf("Pointer: %p\n\n", ULONG_MAX);
// 	print +=       printf("Pointer: %p\n\n", NULL);
// 	ft_print += ft_printf("Pointer: %p\n\n", NULL);
// 	print +=       printf(NULL);
// 	ft_print += ft_printf(NULL);
// 	print +=       printf("Hex: %x\n\n", ULONG_MAX);
// 	ft_print += ft_printf("Hex: %x\n\n", ULONG_MAX);
// 	print +=       printf("HEX: %X\n\n", 555555555);
// 	ft_print += ft_printf("HEX: %X\n\n", 555555555);
// 	print +=       printf("Hex: %x\n\n", 0);
// 	ft_print += ft_printf("Hex: %x\n\n", 0);
// 	print +=       printf("Percent: %%%%%%\n\n");
// 	ft_print += ft_printf("Percent: %%%%%%\n\n");
//     print +=       printf("___printf = Check %%:%");
//     print +=       printf("\n\n", 0);
// 	ft_print += ft_printf("ft_ptintf = Check %%:%");
// 	ft_print += ft_printf("\n\n", 0);
//     print +=       printf("Hex: %k%r\n\n", 0);
// 	ft_print += ft_printf("Hex: %k%r\n\n", 0);
// 	printf("%d = %d\n\n", print, ft_print);
// }
