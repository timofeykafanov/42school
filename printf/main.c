#include "ft_printf.h"

int	main(void)
{
	int	i;
	int	*ptr;
	int	ft_print;
	int	print;

	i = 0;
	print = 0;
	ft_print = 0;
	ptr = &i;
	// print +=       printf("Char: %c\n\n", 'A');
	// ft_print += ft_printf("Char: %c\n\n", 'A');
	// print +=       printf("String: %s\n\n", "QWERTY");
	// ft_print += ft_printf("String: %s\n\n", "QWERTY");
	// print +=       printf("String: %s\n\n", NULL);
	// ft_print += ft_printf("String: %s\n\n", NULL);
	// print +=       printf("Integer: %i\n\n", INT_MIN);
	// ft_print += ft_printf("Integer: %i\n\n", INT_MIN);
	// print +=       printf("Digit: %d\n\n", INT_MAX);
	// ft_print += ft_printf("Digit: %d\n\n", INT_MAX);
	// print +=       printf("Unsigned: %u\n\n", -5);
	// ft_print += ft_printf("Unsigned: %u\n\n", -5);
	// print +=       printf("Pointer: %p\n\n", (void *)ptr);
	// ft_print += ft_printf("Pointer: %p\n\n", (void *)ptr);
	// print +=       printf("Pointer: %p\n\n", NULL);
	// ft_print += ft_printf("Pointer: %p\n\n", NULL);
	// print +=       printf(NULL);
	// ft_print += ft_printf(NULL);
	print +=       printf("Hex: %k\n\n", 555);
	ft_print += ft_printf("Hex: %k\n\n", 555);
	printf("%d = %d", print, ft_print);
}