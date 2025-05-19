/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iorsini- <iorsini-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 19:17:18 by iorsini-          #+#    #+#             */
/*   Updated: 2025/05/16 20:26:24 by iorsini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putunbr(unsigned int n)
{
	unsigned int	size;

	size = 0;
	if (n > 9)
		size = size + ft_putunbr (n / 10);
	size = size + ft_putchar ((n % 10) + '0');
	return (size);
}
