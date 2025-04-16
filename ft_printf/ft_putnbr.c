/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:55:37 by lucas-do          #+#    #+#             */
/*   Updated: 2025/02/22 16:47:21 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	itoalen(long int nb)
{
	long int	slots;

	slots = 0;
	if (nb < 0 || nb == 0)
	{
		if (nb == -2147483648)
			nb--;
		nb *= -1;
		slots++;
	}
	while (nb > 0)
	{
		slots++;
		nb = nb / 10;
	}
	return (slots);
}

static void	ft_putnbr_int(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
		ft_putnbr(n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + 48);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	i = itoalen(n);
	ft_putnbr_int(n);
	return (i);
}
