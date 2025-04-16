#include "../fdf.h"

void	move_map(t_fdf_gen *data, int keycode)
{
	if (keycode == KEY_IN)
		data->design->spacing += 2;
	if (keycode == KEY_OUT)
		data->design->spacing -= 2;
	if (keycode == KEY_UP)
		data->design->map_offset_y -= 10;
	if (keycode == KEY_DOWN)
		data->design->map_offset_y += 10;
	if (keycode == KEY_LEFT)
		data->design->map_offset_x -= 10;
	if (keycode == KEY_RIGHT)
		data->design->map_offset_x += 10;
}	

int	key_hook(int keycode, t_fdf_gen *data)
{
	if (keycode == 53 || keycode == 65307)
	{
		ft_printf("closing the program...\n");
		mlx_destroy_window(data->data->mlx_ptr, data->data->win_ptr);
		mlx_destroy_display(data->data->mlx_ptr);
		free(data->data->mlx_ptr);
		ft_printf("program closed\n");
		exit(0);
	}
	move_map(data, keycode);
	insert_image(data);
	return (0);
}