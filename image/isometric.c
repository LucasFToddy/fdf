/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:12:56 by lucas-do          #+#    #+#             */
/*   Updated: 2025/04/20 08:32:18 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	isometric(float *x, float *y, int z, t_design *design)
{
	float	a;

	a = 119.75;
	z *= design->profundity;
	*x = (*x * cos(a)) + (*y * cos(a + 2)) + (z * cos(a - 2));
	*y = (*x * sin(a)) + (*y * sin(a + 2)) + (z * sin(a - 2));
}
