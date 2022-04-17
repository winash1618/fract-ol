#include "../includes/fractol.h"

int	ft_exit(void)
{
	exit (1);
	return (0);
}

void	event_activator(t_vars *new, int x, int y)
{
	mlx_clear_window(new->mlx, new->win);
	if (new->flag == 1)
		render_translation(new, x, y);
	else if (new->flag == 2)
		render_translation_m(new, x, y);
	mlx_put_image_to_window(new->mlx, new->win, new->img, 0, 0);
}

void	zoom_activator(t_vars *new, int x, int y, double zoom)
{
	mlx_clear_window(new->mlx, new->win);
	if (new->flag == 1)
		render_image(new, x, y, zoom);
	else if (new->flag == 2)
		render_image_m(new, x, y, zoom);
	mlx_put_image_to_window(new->mlx, new->win, new->img, 0, 0);
}

int	key_check(int keycode, t_vars *new)
{
	if (keycode == 53)
	{
		mlx_destroy_window(new->mlx, new->win);
		exit (1);
	}
	else if (keycode == 123)
		event_activator(new, 10, 0);
	else if (keycode == 124)
		event_activator(new, -10, 0);
	else if (keycode == 125)
		event_activator(new, 0, -10);
	else if (keycode == 126)
		event_activator(new, 0, 10);
	return (0);
}

int mouse_move(int button, int x, int y, t_vars *new)
{
	if (button == 5)
		zoom_activator(new, x, y, 1.3);
	else if (button == 4)
		zoom_activator(new, x, y, 0.7);
	return (0);
}