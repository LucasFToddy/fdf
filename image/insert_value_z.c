/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_value_z.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 08:28:57 by lucas-do          #+#    #+#             */
/*   Updated: 2025/04/20 08:29:00 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\v' || c == '\t' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

static int	ft_atoi_hexa(const char *str)
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
