/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:11:17 by lucas-do          #+#    #+#             */
/*   Updated: 2025/02/22 16:47:21 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_wr_ptr(unsigned long n, unsigned long base, char *digit)
{
	int	i;

	i = 0;
	if (n >= base)
	{
		i += ft_putnbr_wr_ptr(n / base, base, digit);
		i += ft_putnbr_wr_ptr(n % base, base, digit);
	}
	else
		i += ft_putchar(digit[n]);
	return (i);
}

int	ft_putnbr_ptr(void *n)
{
	int	i;

	i = 0;
	if (n == NULL)
		return (ft_putstr("(nil)"));
	i += ft_putchar('0');
	i += ft_putchar('x');
	i += ft_putnbr_wr_ptr((unsigned long)n, 16, "0123456789abcdef");
	return (i);
}
