/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:59:45 by lucas-do          #+#    #+#             */
/*   Updated: 2025/02/22 16:47:21 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base_wr(unsigned int n, unsigned int base, char *digit)
{
	int	i;

	i = 0;
	// if (n < 0)
	// {
	// 	i += ft_putchar('-');
	// 	i += ft_putnbr_base_wr((n *= -1), base, digit);
	// }
	if (n >= base)
	{
		i += ft_putnbr_base_wr(n / base, base, digit);
		i += ft_putnbr_base_wr(n % base, base, digit);
	}
	else
		i += ft_putchar(digit[n]);
	return (i);
}

int	ft_putnbr_base(unsigned int n, unsigned int base, char *digit)
{
	int	i;

	i = ft_putnbr_base_wr(n, base, digit);
	return (i);
}
