/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:13:26 by lucas-do          #+#    #+#             */
/*   Updated: 2025/04/17 20:13:30 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	max_value(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static float	mod(float a)
{
	if (a < 0)
		a = -a;
	return (a);
}

static void	set_pixel(t_coords *coords, t_fdf_gen *data)
{
	int	index;

	index = 0;
	if (coords->x >= 0 && coords->x < data->data->win_width && coords->y >= 0
		&& coords->y < data->data->win_height)
	{
		index = ((int)(coords->y) * data->img_data->size_line + (int)(coords->x)
				* (data->img_data->bpp / 8));
		*(int *)(data->img_data->img_data + index) = coords->start_color;
	}
}

void	trace_line(float *x_end, float *y_end, t_coords *coords,
		t_fdf_gen *data)
{
	int	max;

	*x_end = (coords->x1 - coords->x);
	*y_end = (coords->y1 - coords->y);
	max = max_value(mod(*x_end), mod(*y_end));
	*x_end /= max;
	*y_end /= max;
	while ((int)(coords->x - coords->x1) || (int)(coords->y - coords->y1))
	{
		set_pixel(coords, data);
		coords->x += *x_end;
		coords->y += *y_end;
	}
}
