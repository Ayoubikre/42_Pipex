# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tt                                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noctis <noctis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/14 09:53:13 by noctis            #+#    #+#              #
#    Updated: 2025/02/14 11:45:00 by noctis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int	ft_w_s(char *t)
{
	int	i;

	i = 0;
	if (!t)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (t[i])
	{
		write(1, &t[i], 1);
		i++;
	}
	return (i);
}

int	ft_w_d(int k)
{
	int	count;

	count = 0;
	if (k == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (k < 0)
	{
		write(1, "-", 1);
		count++;
		k *= -1;
	}
	if (k > 9)
	{
		count += ft_w_d(k / 10);
		count += ft_w_d(k % 10);
	}
	else if (0 <= k && k <= 9)
	{
		write(1, &(char){k + '0'}, 1);
		count++;
	}
	return (count);
}

int	ft_w_x(unsigned int k)
{
	int	count;

	count = 0;
	if (k > 15)
	{
		count += ft_w_x(k / 16);
		count += ft_w_x(k % 16);
	}
	else if (10 <= k && k <= 15)
	{
		write(1, &(char){k + 'a' - 10}, 1);
		count++;
	}
	else if (k <= 9)
	{
		write(1, &(char){k + '0'}, 1);
		count++;
	}
	return (count);
}

int	ft_w_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_w_u(unsigned int k)
{
	int	count;

	count = 0;
	if (k > 9)
	{
		count = ft_w_u(k / 10);
		count = ft_w_u(k % 10);
	}
	else
	{
		write(1, &(char){k + '0'}, 1);
		count++;
	}
	return (count);
}

int	ft_w_X(unsigned int k)
{
	int	count;

	count = 0;
	if (k > 16)
	{
		count += ft_w_X(k / 16);
		count += ft_w_X(k % 16);
	}
	else if (10 <= k && k <= 15)
	{
		write(1, &(char){k + 'A' - 10}, 1);
		count++;
	}
	else if (k <= 9)
	{
		write(1, &(char){k + '0'}, 1); count++;
	}
	return (count);
}

int	ft_write(va_list ptr, char c)
{
	int	count;

	count = 0;
	if (c == 's')
		count += ft_w_s(va_arg(ptr, char *));
	else if (c == 'c')
		count += ft_w_c(va_arg(ptr, int));
	else if (c == 'd')
		count += ft_w_d(va_arg(ptr, int));
	else if (c == 'i')
		count += ft_w_d(va_arg(ptr, int));
	else if (c == 'u')
		count += ft_w_u(va_arg(ptr, unsigned int));
	else if (c == 'p')
	{
		write(1, "0x", 2);
		count = count + 2 + ft_w_x(va_arg(ptr, unsigned long));
	}
	else if (c == 'X')
		count += ft_w_X(va_arg(ptr, unsigned int ));
	else if (c == 'x')
		count += ft_w_x(va_arg(ptr, unsigned int));
	else
	{
		write(1, &c, 1);
		count++;
	}
	return (count);
}

int	ft_printf(const char *t, ...)
{
	int		count;
	va_list	ptr;
	int		i;

	count = 0;
	va_start(ptr, t);
	if (!t || write(1, NULL, 0) == -1)
		return (-1);
	i = 0;
	while (t[i])
	{
		if (t[i] == '%' && t[i + 1] != '\0')
		{
			count += ft_write(ptr, t[++i]);
		}
		else
		{
			write(1, &t[i], 1);
			count++;
		}
		i++;
	}
	va_end(ptr);
	return (count);
}

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
	printf("%p\n", 255);
	ft_printf("%p\n", "hello world");
	ft_printf("%p\n", 255);


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
