/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iorsini- <iorsini-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:29:06 by iorsini-          #+#    #+#             */
/*   Updated: 2025/05/19 16:45:02 by iorsini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_ptr(unsigned long n)
{
	char	*b;
	int		res;

	b = "0123456789abcdef";
	res = 0;
	if (n >= 16)
	{
		res = ft_puthex_ptr(n / 16);
		res = res + write(1, &b[n % 16], 1);
	}
	else
		res = write(1, &b[n % 16], 1);
	return (res);
}

int	ft_putptr(unsigned long n)
{
	int	b;

	if (n == 0)
		return (write(1, "(nil)", 5));
	b = write(1, "0x", 2);
	b = b + ft_puthex_ptr(n);
	return (b);
}
