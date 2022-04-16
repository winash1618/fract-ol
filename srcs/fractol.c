#include "../includes/fractol.h"

int	main(void)
{
	t_vars	*new;

	new = (t_vars *)malloc(sizeof(t_vars));
	new->mlx = mlx_init();
	new->win = mlx_new_window(new->mlx, 1920, 1080, "Hello world!");
	new->img = mlx_new_image(new->mlx, 1920, 1080);
	new->addr = mlx_get_data_addr(new->img, &new->bits_per_pixel, &new->line_length, &new->endian);
	new->zoom = 1;
	render_image(new, 0, 0, 1);
	mlx_put_image_to_window(new->mlx, new->win, new->img, 0, 0);
	mlx_hook(new->win, 4, 0, mouse_move, new);
	mlx_hook(new->win, 17, 1L<<17, ft_exit , 0);
	mlx_hook(new->win, 2, 0, key_check, new);
	mlx_loop(new->mlx);
}