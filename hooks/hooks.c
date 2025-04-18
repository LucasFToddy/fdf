/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:12:38 by lucas-do          #+#    #+#             */
/*   Updated: 2025/04/18 16:02:47 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	move_map(t_fdf_gen *data, int keycode)
{
	if (keycode == KEY_IN)
	{
		if (data->design->spacing <= 23)
		{
			data->design->spacing += 1;
			data->design->profundity += (data->design->profundity * 0.4);
		}
	}
	if (keycode == KEY_OUT)
	{
		if (data->design->spacing >= 3)
		{
			data->design->spacing -= 1;
			data->design->profundity -= (data->design->profundity * 0.4);
		}
	}
	if (keycode == KEY_UP)
		data->design->map_offset_y -= 10;
	if (keycode == KEY_DOWN)
		data->design->map_offset_y += 10;
	if (keycode == KEY_LEFT)
		data->design->map_offset_x -= 10;
	if (keycode == KEY_RIGHT)
		data->design->map_offset_x += 10;
}

int	key_hook(int keycode, t_fdf_gen *data)
{
	if (keycode == 53 || keycode == 65307)
		return (mlx_loop_end(data->data->mlx_ptr));
	move_map(data, keycode);
	insert_image(data);
	return (0);
}

int	close_win(t_fdf_gen *data)
{
	return (mlx_loop_end(data->data->mlx_ptr));
}
