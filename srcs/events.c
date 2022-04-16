#include "../includes/fractol.h"

int	ft_exit(void)
{
	exit (1);
	return (0);
}

int	key_check(int keycode, t_vars *new)
{
	if (keycode == 53)
	{
		mlx_destroy_window(new->mlx, new->win);
		exit (1);
	}
	else if (keycode == 123)
	{
		mlx_clear_window(new->mlx, new->win);
		render_translation(new, 10, 0);
		mlx_put_image_to_window(new->mlx, new->win, new->img, 0, 0);
	}
	else if (keycode == 124)
	{
		mlx_clear_window(new->mlx, new->win);
		render_translation(new, -10, 0);
		mlx_put_image_to_window(new->mlx, new->win, new->img, 0, 0);
	}
	else if (keycode == 125)
	{
		mlx_clear_window(new->mlx, new->win);
		render_translation(new, 0, -10);
		mlx_put_image_to_window(new->mlx, new->win, new->img, 0, 0);
	}
	else if (keycode == 126)
	{
		mlx_clear_window(new->mlx, new->win);
		render_translation(new, 0, +10);
		mlx_put_image_to_window(new->mlx, new->win, new->img, 0, 0);
	}
	return (keycode);
}

int mouse_move(int button, int x, int y, t_vars *new)
{
	if (button == 4)
	{
		mlx_clear_window(new->mlx, new->win);
		render_image(new, x, y , 1.3);
		mlx_put_image_to_window(new->mlx, new->win, new->img, 0, 0);
	}
	if (button == 5)
	{
		mlx_clear_window(new->mlx, new->win);
		render_image(new, x, y, 0.7);
		mlx_put_image_to_window(new->mlx, new->win, new->img, 0, 0);
	}
	return (0);
}