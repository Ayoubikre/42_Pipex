#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	printf("%d\n", INT_MAX);
	printf("%d\n", 0);
	printf("%d\n", INT_MIN);
	ft_printf("%d\n", INT_MAX);
	ft_printf("%d\n", 0);
	ft_printf("%d\n", INT_MIN);

	printf("\n---------\n");

	printf("%i\n", INT_MAX);
	printf("%i\n", 0);
	printf("%i\n", INT_MIN);
	ft_printf("%i\n", INT_MAX);
	ft_printf("%i\n", 0);
	ft_printf("%i\n", INT_MIN);

	printf("\n---------\n");

	printf("%u\n", INT_MAX);
	printf("%u\n", 0);
	printf("%u\n", INT_MIN);
	ft_printf("%u\n", INT_MAX);
	ft_printf("%u\n", 0);
	ft_printf("%u\n", INT_MIN);

	printf("\n---------\n");

	printf("%p\n", "hello world");
	printf("%p\n", 10);
	ft_printf("%p\n", "hello world");
	ft_printf("%p\n", 10);


	printf("\n---------\n");

	printf("%s\n", "hello world");
	ft_printf("%s\n", "hello world");

	printf("\n---------\n");

	printf("%c\n", 'a');
	ft_printf("%c\n", 'a');

	printf("\n---------\n");
	printf("%p\n", "hello world");
	printf("%p\n", "hello world");
	ft_printf("%p\n", "hello world");
	ft_printf("%p\n", "hello world");

	printf("\n---------\n");

	printf("%x\n", INT_MAX);
	printf("%x\n", 0);
	printf("%x\n", INT_MIN);
	ft_printf("%x\n", INT_MAX);
	ft_printf("%x\n", 0);
	ft_printf("%x\n", INT_MIN);

	printf("\n---------\n");

	printf("%X\n", INT_MAX);
	printf("%X\n", 0);
	printf("%X\n", INT_MIN);
	ft_printf("%X\n", INT_MAX);
	ft_printf("%X\n", 0);
	ft_printf("%X\n", INT_MIN);

	printf("\n---------\n");

	printf("%%\n" );
	ft_printf("%%\n" );



}