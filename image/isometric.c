/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:12:56 by lucas-do          #+#    #+#             */
/*   Updated: 2025/04/17 20:13:00 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	isometric(float *x, float *y, int z, t_design *design)
{
	float	x_rot;
	float	y_rot;
	float	z_rot;

	z *= design->profundity;
	y_rot = *y * cos(design->angle_x) - z * sin(design->angle_x);
	z_rot = *y * sin(design->angle_x) + z * cos(design->angle_x);
	x_rot = *x * cos(design->angle_y) + z_rot * sin(design->angle_y);
	z_rot = -*x * sin(design->angle_y) + z_rot * cos(design->angle_y);
	*x = x_rot;
	*y = y_rot;
}
