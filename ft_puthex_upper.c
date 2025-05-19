/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iorsini- <iorsini-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:54:31 by iorsini-          #+#    #+#             */
/*   Updated: 2025/05/19 15:28:25 by iorsini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_upper(unsigned int n)
{
	char	*b;
	int		res;

	b = "0123456789ABCDEF";
	res = 0;
	if (n >= 16)
	{
		res = ft_puthex_upper(n / 16);
		res = res + write(1, &b[n % 16], 1);
	}
	else
		res = write(1, &b[n % 16], 1);
	return (res);
}
