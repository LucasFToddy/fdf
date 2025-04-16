/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:27:00 by lucas-do          #+#    #+#             */
/*   Updated: 2025/02/22 16:53:52 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *c, ...);
int	ft_putstr(char *s);
int	ft_putnbr_base(unsigned int n, unsigned int base, char *digit);
int	ft_putnbr_ptr(void *n);
int	ft_putchar(char c);
int	ft_putnbr(int n);
#endif
