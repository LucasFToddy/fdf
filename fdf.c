/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:14:25 by lucas-do          #+#    #+#             */
/*   Updated: 2025/04/17 21:30:20 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\v' || c == '\t' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

int	ft_atoi_hexa(const char *str)
{
	int	result;
	int	digit;

	digit = 0;
	result = 0;
	while (is_space(*str))
		str++;
	if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
		str += 2;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			digit = *str - '0';
		else if (*str >= 'a' && *str <= 'f')
			digit = *str - 'a' + 10;
		else if (*str >= 'A' && *str <= 'F')
			digit = *str - 'A' + 10;
		else
			break ;
		result = result * 16 + digit;
		str++;
	}
	return (result);
}

void	get_initial_values(t_coords *coords, t_fdf *data)
{
	coords->z = data->z_matrix[(int)(coords->y * data->width
			+ coords->x)].value;
	coords->z1 = data->z_matrix[(int)(coords->y1 * data->width
			+ coords->x1)].value;
	coords->start_color = ft_atoi_hexa(data->z_matrix[(int)(coords->y
				* data->width + coords->x)].color);
}

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
		return (0);
	if (init_mlx(&data))
	{
		make_img(&data);
		mlx_hook(data.data->win_ptr, 2, 1L << 0, key_hook, &data);
		mlx_hook(data.data->win_ptr, 17, 0, close_win, &data);
		mlx_loop(data.data->mlx_ptr);
	}
	mlx_destroy_window(data.data->mlx_ptr, data.data->win_ptr);
	mlx_destroy_display(data.data->mlx_ptr);
	free(data.data->mlx_ptr);
	free_matrix(data.data);
	return (0);
}
