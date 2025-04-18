/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:13:43 by lucas-do          #+#    #+#             */
/*   Updated: 2025/04/17 21:24:55 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	set_color_null(t_point *z_line)
{
	if (z_line->value == 0)
		z_line->color = ft_strdup("0xFFFFFF");
	else if (z_line->value > 0)
		z_line->color = ft_strdup("0x00BFFF");
	else
		z_line->color = ft_strdup("0xFF0000");
}

int	set_value_and_color(t_point *z_line, char *value)
{
	char	**value_color;

	value_color = ft_split(value, ',');
	if (!value_color)
		return (0);
	if (value_color[1])
		z_line->color = ft_strdup(value_color[1]);
	else
		set_color_null(z_line);
	free(value_color[0]);
	if (value_color[1])
		free(value_color[1]);
	free(value_color);
	return (1);
}

void	fill_matriz(t_point *z_line, char *line)
{
	int		i;
	char	**list_;

	i = 0;
	list_ = ft_split(line, ' ');
	if (!list_)
	{
		free(list_);
		return ;
	}
	while (list_[i])
	{
		z_line[i].value = ft_atoi(list_[i]);
		set_value_and_color(&z_line[i], list_[i]);
		free(list_[i]);
		i++;
	}
	free(list_);
}

int	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	int		i;
	char	*line;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_matrix = (t_point *)malloc(sizeof(t_point) * data->height
			* data->width);
	if (!data->z_matrix)
		return (0);
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		fill_matriz(&data->z_matrix[i * data->width], line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (1);
}
