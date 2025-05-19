/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iorsini- <iorsini-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:14:08 by iorsini-          #+#    #+#             */
/*   Updated: 2025/05/19 19:50:16 by iorsini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(const char *str, va_list args)
{
	if (*str == '%')
		return (write (1, "%", 1));
	else if (*str == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*str == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*str == 'p')
		return (ft_putptr((unsigned long)va_arg(args, void *)));
	else if (*str == 'd' || *str == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (*str == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (*str == 'x')
		return (ft_puthex(va_arg(args, unsigned int)));
	else if (*str == 'X')
		return (ft_puthex_upper(va_arg(args, unsigned int)));
	else
		return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			count = count + ft_format(&str[i], args);
		}
		else
		{
			write(1, &str[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}
/*
#include <stdio.h>

int	main(void)
{
	int a;

	a = 0;
	printf("=== Teste %%c ===\n");
	a = ft_printf("ft_printf: char = %c\n", 'A');
	printf("Retorno ft_printf: %d\n", a);
	a = printf("printf:    char = %c\n", 'A');
	printf("Retorno printf:    %d\n\n", a);

	printf("=== Teste %%s ===\n");
	a = ft_printf("ft_printf: string = %s\n", "hello");
	printf("Retorno ft_printf: %d\n", a);
	a = printf("printf:    string = %s\n", "hello");
	printf("Retorno printf:    %d\n\n", a);

	printf("=== Teste %%d e %%i ===\n");
	a = ft_printf("ft_printf: int = %d\n", -42);
	printf("Retorno ft_printf: %d\n", a);
	a = printf("printf:    int = %d\n", -42);
	printf("Retorno printf:    %d\n\n", a);

	printf("=== Teste %%u com valor negativo (conversão) ===\n");
	a = ft_printf("ft_printf: unsigned = %u\n", -4);
	printf("Retorno ft_printf: %d\n", a);
	a = printf("printf:    unsigned = %u\n", -4);
	printf("Retorno printf:    %d\n\n", a);

	printf("=== Teste %%u com valor positivo ===\n");
	a = ft_printf("ft_printf: unsigned = %u\n", 214648);
	printf("Retorno ft_printf: %d\n", a);
	a = printf("printf:    unsigned = %u\n", 214648);
	printf("Retorno printf:    %d\n\n", a);

	printf("=== Teste %%x (hex lowercase) ===\n");
	a = ft_printf("ft_printf: hex = %x\n", 305441741);
	printf("Retorno ft_printf: %d\n", a);
	a = printf("printf:    hex = %x\n", 305441741);
	printf("Retorno printf:    %d\n\n", a);

	printf("=== Teste %%X (hex uppercase) ===\n");
	a = ft_printf("ft_printf: HEX = %X\n", 305441741);
	printf("Retorno ft_printf: %d\n", a);
	a = printf("printf:    HEX = %X\n", 305441741);
	printf("Retorno printf:    %d\n\n", a);

	printf("=== Teste %%p (pointer) ===\n");
	int x = 42;
	a = ft_printf("ft_printf: ptr = %p\n", &x);
	printf("Retorno ft_printf: %d\n", a);
	a = printf("printf:    ptr = %p\n", &x);
	printf("Retorno printf:    %d\n\n", a);

	printf("=== Teste com %%%% (percent literal) ===\n");
	a = ft_printf("ft_printf: Percent %% test\n");
	printf("Retorno ft_printf: %d\n", a);
	a = printf("printf:    Percent %% test\n");
	printf("Retorno printf:    %d\n\n", a);

	return (0);
}*/
