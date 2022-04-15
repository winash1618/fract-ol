#include "../minilibx/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int	color;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	re_c;
	double	im_c;
	double	newm;
	double	newi;
	double	oldm;
	double	oldi;
	double	xk;
	double	yk;
	double	zoom;
	double	mx;
	double	my;
}	t_vars;


int	ft_exit(void)
{
	exit (1);
	return (0);
}

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}
void render_image(t_vars *new, double x, double y, double zoom)
{
	new->re_c = -0.7;
	new->im_c = 0.27015;
	new->newm = 0;
	new->newi = 0;
	new->oldm = 0;
	new->oldi = 0;
	new->xk = 0;
	new->yk = 0;
	new->mx = x / 1920;
	new->my = y / 1080;
	new->zoom = new->zoom * zoom;
	printf("%f", new->zoom);
	fflush(stdout);
	while (new->xk < 1920)
	{
		new->yk = 0;
		while (new->yk < 1080)
		{
			new->newm = 1.5*(new->xk - 1920 / 2) / (0.5 * new->zoom * 1920) + new->mx;
			new->newi = (new->yk - 1080 / 2) / (0.5 * new->zoom * 1080) + new->my;
			// printf("%f %f", newm, newi);
			int i = 0;
			while (i < 500)
			{
				new->oldm = new->newm;
				new->oldi = new->newi;
				new->newm = new->oldm * new->oldm - new->oldi * new->oldi + new->re_c;
				new->newi = 2 * new->oldm * new->oldi + new->im_c;
				if (new->newm * new->newm + new->newi * new->newi > 4)
					break;
				i++;
			}
				int t = 0;
				int r = 255 * (i / 500.0);
				int g = 255 * (i / 500.0);
				int b = 255 * (i / 500.0);
				int trgb = create_trgb(t, r, g, b);
				if (trgb < 0)
					printf("%d \n", trgb);
				//int trgb = create_trgb(32 * (i / 500),24 * (i / 500),16 * (i / 500),8 * (i / 500 ));
				my_mlx_pixel_put(new, new->xk, new->yk,  trgb);
			new->yk++;
		}
		new->xk++;
	}
}

void render_translation(t_vars *new, double x, double y)
{
	new->re_c = -0.7;
	new->im_c = 0.27015;
	new->newm = 0;
	new->newi = 0;
	new->oldm = 0;
	new->oldi = 0;
	new->xk = 0;
	new->yk = 0;
	new->mx += x / 1920;
	new->my += y / 1080;
	while (new->xk < 1920)
	{
		new->yk = 0;
		while (new->yk < 1080)
		{
			new->newm = 1.5*(new->xk - 1920 / 2) / (0.5 * new->zoom * 1920) + new->mx;
			new->newi = (new->yk - 1080 / 2) / (0.5 * new->zoom * 1080) + new->my;
			// printf("%f %f", newm, newi);
			int i = 0;
			while (i < 500)
			{
				new->oldm = new->newm;
				new->oldi = new->newi;
				new->newm = new->oldm * new->oldm - new->oldi * new->oldi + new->re_c;
				new->newi = 2 * new->oldm * new->oldi + new->im_c;
				if (new->newm * new->newm + new->newi * new->newi > 4)
					break;
				i++;
			}
				int t = 0;
				int r = 255 * (i / 500.0);
				int g = 255 * (i / 500.0);
				int b = 255 * (i / 500.0);
				int trgb = create_trgb(t, r, g, b);
				if (trgb < 0)
					printf("%d \n", trgb);
				//int trgb = create_trgb(32 * (i / 500),24 * (i / 500),16 * (i / 500),8 * (i / 500 ));
				my_mlx_pixel_put(new, new->xk, new->yk,  trgb);
			new->yk++;
		}
		new->xk++;
	}
}
int mouse_move(int button, int x, int y, t_vars *new)
{
	if (button == 1)
	{
		// mlx_clear_window(new->mlx, new->win);
		// new->img = mlx_new_image(new->mlx, 1920, 1080);
		// new->addr = mlx_get_data_addr(new->img, &new->bits_per_pixel, &new->line_length, &new->endian);
		render_image(new, x, y , 1.3);
		mlx_put_image_to_window(new->mlx, new->win, new->img, 0, 0);
	}
	if (button == 2)
	{
		// mlx_clear_window(new->mlx, new->win);
		// new->img = mlx_new_image(new->mlx, 1920, 1080);
		// new->addr = mlx_get_data_addr(new->img, &new->bits_per_pixel, &new->line_length, &new->endian);
		render_image(new, x, y, 0.7);
		mlx_put_image_to_window(new->mlx, new->win, new->img, 0, 0);
	}
	return (0);
}

int	key_check(int keycode, t_vars *new)
{
	printf("%d \n", keycode);
	fflush(stdout);
	if (keycode == 53)
		mlx_destroy_window(new->mlx, new->win);
	else if (keycode == 0)
	{
		// mlx_destroy_image(new->mlx, new->img);
		// mlx_clear_window(new->mlx, new->win);
		// new->img = mlx_new_image(new->mlx, 1920, 1080);
		// new->addr = mlx_get_data_addr(new->img, &new->bits_per_pixel, &new->line_length, &new->endian);
		render_translation(new, -10, 0);
		mlx_put_image_to_window(new->mlx, new->win, new->img, 0, 0);
	}
	else if (keycode == 1)
	{
		// mlx_destroy_image(new->mlx, new->img);
		// mlx_clear_window(new->mlx, new->win);
		// new->img = mlx_new_image(new->mlx, 1920, 1080);
		// new->addr = mlx_get_data_addr(new->img, &new->bits_per_pixel, &new->line_length, &new->endian);
		render_translation(new, 10, 0);
		mlx_put_image_to_window(new->mlx, new->win, new->img, 0, 0);
	}
	return (keycode);
}

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