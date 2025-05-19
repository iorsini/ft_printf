/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iorsini- <iorsini-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:04:26 by iorsini-          #+#    #+#             */
/*   Updated: 2025/05/19 15:35:39 by iorsini-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int				ft_printf(const char *str, ...);
int				ft_putchar(int c);
int				ft_putstr(char *str);
int				ft_putnbr(int n);
unsigned int	ft_putunbr(unsigned int n);
int				ft_puthex(unsigned int n);
int				ft_puthex_upper(unsigned int n);
int				ft_putptr(unsigned long n);

#endif
