/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:51:51 by lucas-do          #+#    #+#             */
/*   Updated: 2025/02/22 16:54:22 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_check_arg(const char *str, va_list list)
{
	int	len;

	len = 0;
	str++;
	if (*str == 'c')
		len += ft_putchar((char)va_arg(list, int));
	else if (*str == 's')
		len += ft_putstr(va_arg(list, char *));
	else if (*str == 'p')
		len += ft_putnbr_ptr(va_arg(list, void *));
	else if (*str == 'd' || *str == 'i')
		len += ft_putnbr(va_arg(list, int));
	else if (*str == 'u')
		len += ft_putnbr_base(va_arg(list, unsigned int), 10, "0123456789");
	else if (*str == 'x')
		len += ft_putnbr_base(
				va_arg(list, unsigned int), 16, "0123456789abcdef");
	else if (*str == 'X')
		len += ft_putnbr_base(
				va_arg(list, unsigned int), 16, "0123456789ABCDEF");
	else
		len += ft_putchar(*str);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		r;
	va_list	list;

	va_start(list, s);
	r = 0;
	while (*s)
	{
		if (*s == '%')
		{
			r += ft_check_arg(s, list);
			s++;
		}
		else
			r += ft_putchar(*s);
		s++;
	}
	va_end(list);
	return (r);
}
