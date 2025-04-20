/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:14:25 by lucas-do          #+#    #+#             */
/*   Updated: 2025/04/18 11:37:12 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	make_img(t_fdf_gen *data)
{
	data->img_data->img_ptr = mlx_new_image(data->data->mlx_ptr,
			data->data->win_width, data->data->win_height);
	data->img_data->img_data = mlx_get_data_addr(data->img_data->img_ptr,
			&data->img_data->bpp, &data->img_data->size_line,
			&data->img_data->endian);
	insert_image(data);
}

int	main(int argc, char **argv)
{
	t_fdf_gen	data;

	if (argc < 2)
		return (0);
	if (!init_structs(&data))
		return (0);
	if (!read_file(argv[1], data.data))
	{
		free_general(&data);
		return (0);
	}
	if (init_mlx(&data))
	{
		make_img(&data);
		mlx_hook(data.data->win_ptr, 2, 1L << 0, key_hook, &data);
		mlx_hook(data.data->win_ptr, 17, 0, close_win, &data);
		mlx_loop(data.data->mlx_ptr);
	}
	free_pointer_server(&data);
	free_general(&data);
	return (0);
}
