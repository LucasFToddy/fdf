#ifndef FDF_H

# define FDF_H

# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"

#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

#define MALLOC_ERROR	1
#define WIDTH		600
#define HEIGHT		400
#define SCALE		50
#define KEY_IN		105
#define KEY_OUT		111
#define KEY_UP		65362
#define KEY_RIGHT		65363
#define KEY_LEFT		65361
#define KEY_DOWN		65364

typedef struct s_point
{
	int	value;
	char	*color;
}	t_point;

typedef struct s_fdf
{
	int	width;	  // Largura do mapa (número de colunas)
	int	win_width;
	int	height;	 // Altura do mapa (número de linhas)
	int	win_height;
	t_point	*z_matriz; // Matriz que armazena os valores de altura (altitude)

	void	*mlx_ptr;  // Ponteiro para a instância do MiniLibX
	void	*win_ptr;  // Ponteiro para a janela aberta no MiniLibX
} 	t_fdf;

typedef struct s_img
{
	int		bpp;
	int		size_line;
	int		endian;
	void	*img_ptr;
	char	*img_data;
}		t_img;

typedef struct s_coords
{
	float	x;
	float	y;
	float	x1;
	float	y1;
	int		z;
	int		z1;
	int		start_color;
}	t_coords;

typedef struct s_design
{
	int	spacing;
	int	map_offset_x;
	int	map_offset_y;
	float	angle_x;
	float	angle_y;
	float	profundity;
}	t_design;


typedef struct s_fdf_gen
{
	t_fdf	*data;
	t_img	*img_data;
	t_design *design;
}	t_fdf_gen;

int	read_file(char *file_name, t_fdf *data);
int	get_height(char *file_name);
int	get_width(char *file_name);
void	get_initial_values(t_coords *coords, t_fdf *data);
void	insert_image(t_fdf_gen *data);
void	trace_line(float *x_end, float *y_end, t_coords *coords, t_fdf_gen *data);
void	isometric(float *x, float *y, int z, t_design *data);
void    initial_design(t_fdf_gen *data);
int	key_hook(int keycode, t_fdf_gen *data);
void	clear_window(t_fdf_gen *data);
void	map_offset(t_design *design, t_coords *coords);
int	init_structs(t_fdf_gen *data);
int	init_mlx(t_fdf_gen *data);

#endif