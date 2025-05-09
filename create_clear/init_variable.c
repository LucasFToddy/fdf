/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:12:11 by lucas-do          #+#    #+#             */
/*   Updated: 2025/04/20 08:28:44 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	clear_window(t_fdf_gen *data)
{
	mlx_destroy_image(data->data->mlx_ptr, data->img_data->img_ptr);
	data->img_data->img_ptr = mlx_new_image(data->data->mlx_ptr,
			data->data->win_width, data->data->win_height);
	data->img_data->img_data = mlx_get_data_addr(data->img_data->img_ptr,
			&data->img_data->bpp, &data->img_data->size_line,
			&data->img_data->endian);
}

int	init_structs(t_fdf_gen *data)
{
	data->data = (t_fdf *)malloc(sizeof(t_fdf));
	data->img_data = (t_img *)malloc(sizeof(t_img));
	data->design = (t_design *)malloc(sizeof(t_design));
	if (!data->data || !data->img_data || !data->design)
	{
		free_general(data);
		return (0);
	}
	return (1);
}

int	init_mlx(t_fdf_gen *data)
{
	data->data->mlx_ptr = mlx_init();
	if (data->data->mlx_ptr == NULL)
		return (0);
	mlx_get_screen_size(data->data->mlx_ptr, &data->data->win_width,
		&data->data->win_height);
	data->data->win_ptr = mlx_new_window(data->data->mlx_ptr,
			data->data->win_width, data->data->win_height, "FDF");
	if (data->data->win_ptr == NULL)
	{
		mlx_destroy_display(data->data->mlx_ptr);
		free(data->data->mlx_ptr);
		return (0);
	}
	initial_design(data);
	return (1);
}
