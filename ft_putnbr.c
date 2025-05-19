/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iorsini- <iorsini-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:59:26 by iorsini-          #+#    #+#             */
/*   Updated: 2025/05/16 20:06:58 by iorsini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	size;

	size = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		size = write (1, "-", 1);
		n = -n;
	}
	if (n > 9)
		size = size + ft_putnbr (n / 10);
	size = size + ft_putchar ((n % 10) + '0');
	return (size);
}
