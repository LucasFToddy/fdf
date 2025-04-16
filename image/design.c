#include "../fdf.h"

void	initial_design(t_fdf_gen *data)
{
	data->design->spacing = 8;
	data->design->profundity = 3;
	data->design->angle_x = 0.2;
	data->design->angle_y = 0.2;
	data->design->map_offset_x = 0;
	data->design->map_offset_y = 0;
}

void	map_offset(t_design *design, t_coords *coords)
{
	coords->x += design->map_offset_x;
	coords->y += design->map_offset_y;
	coords->x1 += design->map_offset_x;
	coords->y1 += design->map_offset_y;
}