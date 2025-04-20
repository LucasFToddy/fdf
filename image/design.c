/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:12:47 by lucas-do          #+#    #+#             */
/*   Updated: 2025/04/20 08:31:04 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	initial_design(t_fdf_gen *data)
{
	float	map_center_x;
	float	map_center_y;

	map_center_x = 0;
	map_center_y = 0;
	data->design->spacing = 4;
	data->design->profundity = 0.8;
	map_center_x = (data->data->width - 1) * data->design->spacing / 50.0;
	map_center_y = (data->data->height - 1) * data->design->spacing / 50.0;
	data->design->map_offset_x = (data->data->win_width / 2) - map_center_x;
	data->design->map_offset_y = (data->data->win_height / 2) - map_center_y;
}

void	map_offset(t_fdf_gen *data, t_coords *coords)
{
	coords->x += data->design->map_offset_x;
	coords->y += data->design->map_offset_y;
	coords->x1 += data->design->map_offset_x;
	coords->y1 += data->design->map_offset_y;
}
