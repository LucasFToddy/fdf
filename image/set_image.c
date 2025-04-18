/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:13:13 by lucas-do          #+#    #+#             */
/*   Updated: 2025/04/18 15:22:23 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	initial_(t_coords *coords, t_fdf_gen *data)
{
	coords->x *= data->design->spacing;
	coords->y *= data->design->spacing;
	coords->x1 *= data->design->spacing;
	coords->y1 *= data->design->spacing;
}

void	center_map(t_coords *coords, t_fdf_gen *data)
{
	coords->x -= (data->data->width - 1) * data->design->spacing / 2.0;
	coords->y -= (data->data->height - 1) * data->design->spacing / 2.0;
	coords->x1 -= (data->data->width - 1) * data->design->spacing / 2.0;
	coords->y1 -= (data->data->height - 1) * data->design->spacing / 2.0;
}

static void	bresehnam(t_coords coords, t_fdf_gen *data)
{
	float	x_end;
	float	y_end;

	x_end = 0;
	y_end = 0;
	coords.z = 0;
	coords.z1 = 0;
	coords.start_color = 0;
	get_initial_values(&coords, data->data);
	initial_(&coords, data);
	center_map(&coords, data);
	isometric(&coords.x, &coords.y, coords.z, data->design);
	isometric(&coords.x1, &coords.y1, coords.z1, data->design);
	map_offset(data, &coords);
	trace_line(&x_end, &y_end, &coords, data);
}

static void	drawing(t_coords *coords, t_fdf_gen *data)
{
	if (coords->x < data->data->width - 1)
	{
		coords->x1 = coords->x + 1;
		coords->y1 = coords->y;
		bresehnam(*coords, data);
	}
	if (coords->y < data->data->height - 1)
	{
		coords->x1 = coords->x;
		coords->y1 = coords->y + 1;
		bresehnam(*coords, data);
	}
}

void	insert_image(t_fdf_gen *data)
{
	t_coords	coords;

	coords.y = 0;
	clear_window(data);
	while (coords.y < data->data->height)
	{
		coords.x = 0;
		while (coords.x < data->data->width)
		{
			drawing(&coords, data);
			coords.x++;
		}
		coords.y++;
	}
	mlx_put_image_to_window(data->data->mlx_ptr, data->data->win_ptr,
		data->img_data->img_ptr, 0, 0);
}
