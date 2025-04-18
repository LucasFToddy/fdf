/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas-do <lucas-do@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:14:56 by lucas-do          #+#    #+#             */
/*   Updated: 2025/04/18 15:14:48 by lucas-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MALLOC_ERROR 1
# define WIDTH 1920
# define HEIGHT 1080
# define SCALE 50
# define KEY_IN 105
# define KEY_OUT 111
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_LEFT 65361
# define KEY_DOWN 65364

typedef struct s_point
{
	int			value;
	char		*color;
}				t_point;

typedef struct s_fdf
{
	int			width;
	int			win_width;
	int			height;
	int			win_height;
	t_point		*z_matrix;

	void		*mlx_ptr;
	void		*win_ptr;
}				t_fdf;

typedef struct s_img
{
	int			bpp;
	int			size_line;
	int			endian;
	void		*img_ptr;
	char		*img_data;
}				t_img;

typedef struct s_coords
{
	float		x;
	float		y;
	float		x1;
	float		y1;
	int			z;
	int			z1;
	int			start_color;
}				t_coords;

typedef struct s_design
{
	int			spacing;
	int			map_offset_x;
	int			map_offset_y;
	float		angle_x;
	float		angle_y;
	float		profundity;
}				t_design;

typedef struct s_fdf_gen
{
	t_fdf		*data;
	t_img		*img_data;
	t_design	*design;
}				t_fdf_gen;

int				read_file(char *file_name, t_fdf *data);
int				get_height(char *file_name);
int				get_width(char *file_name);
int				init_structs(t_fdf_gen *data);
int				init_mlx(t_fdf_gen *data);
int				close_win(t_fdf_gen *data);
int				key_hook(int keycode, t_fdf_gen *data);
void			free_matrix(t_fdf *data);
void			get_initial_values(t_coords *coords, t_fdf *data);
void			insert_image(t_fdf_gen *data);
void			trace_line(float *x_end, float *y_end, t_coords *coords,
					t_fdf_gen *data);
void			isometric(float *x, float *y, int z, t_design *data);
void			initial_design(t_fdf_gen *data);
void			clear_window(t_fdf_gen *data);
void			map_offset(t_fdf_gen *design, t_coords *coords);
void			free_general(t_fdf_gen *data);
int				free_pointer_server(t_fdf_gen *data);

#endif