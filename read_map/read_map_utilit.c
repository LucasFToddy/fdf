/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utilit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:22:46 by lucas-do          #+#    #+#             */
/*   Updated: 2025/04/18 12:42:56 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	check_line_width_consistency(int fd, int width)
{
	char	*line;
	int		current_width;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		current_width = count_tokens(line, ' ');
		if (current_width != width)
		{
			free(line);
			close(fd);
			return (-1);
		}
		free(line);
	}
	close(fd);
	return (width);
}

int	get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		return (-1);
	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	get_width(char *file_name)
{
	char	*line;
	int		width;
	int		fd;

	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	if (line == NULL)
	{
		write(1, "Erro line get_width", 19);
		close(0);
		return (0);
	}
	width = count_tokens(line, ' ');
	free(line);
	if (check_line_width_consistency(fd, width) == -1)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (width);
}
