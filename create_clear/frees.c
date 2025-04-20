/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:44:41 by lucas-do          #+#    #+#             */
/*   Updated: 2025/04/20 08:33:34 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	free_general(t_fdf_gen *data)
{
	if (data->data)
		free(data->data);
	if (data->design)
		free(data->design);
	if (data->img_data)
		free(data->img_data);
}

void	free_matrix(t_fdf *data)
{
	int	i;

	i = 0;
	if (!data)
		return ;
	if (data->z_matrix)
	{
		while (i < data->height * data->width)
		{
			if (data->z_matrix[i].color)
				free(data->z_matrix[i].color);
			i++;
		}
		free(data->z_matrix);
	}
	free(data);
	data = NULL;
}

int	free_pointer_server(t_fdf_gen *data)
{
	if (!data->data)
		return (0);
	if (data->data->mlx_ptr && data->data->win_ptr)
	{
		mlx_destroy_image(data->data->mlx_ptr, data->img_data->img_ptr);
		mlx_destroy_window(data->data->mlx_ptr, data->data->win_ptr);
		data->data->win_ptr = NULL;
	}
	if (data->data->mlx_ptr)
	{
		mlx_destroy_display(data->data->mlx_ptr);
		free(data->data->mlx_ptr);
		data->data->mlx_ptr = NULL;
	}
	if (data->data)
		free_matrix(data->data);
	data->data = NULL;
	return (0);
}
