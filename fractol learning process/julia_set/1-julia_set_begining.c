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
}	t_vars;


int	ft_exit(void)
{
	exit (1);
	return (0);
}

int	key_check(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	return (keycode);
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

int mouse_move(int button, int x, int y, t_vars *new)
{
	if (button == 1)
	{
		mlx_destroy_image(new->mlx, new->img);
		mlx_clear_window(new->mlx, new->win);
		new->win = mlx_new_window(new->mlx, 1920, 1080, "Hello world!");
		new->img = mlx_new_image(new->mlx, 1920, 1080);
		new->addr = mlx_get_data_addr(new->img, &new->bits_per_pixel, &new->line_length, &new->endian);

		double re_c = -0.7;
		double im_c = 0.27015;
		double newm = 0;
		double newi = 0;
		double oldm = 0;
		double oldi = 0;
		double xk = 0;
		double yk = 0;
		double zoom = 2;
		double mx = x / 1920;
		double my = y / 1080;

		while (xk < 1920)
		{
			yk = 0;
			while (yk < 1080)
			{
				newm = 1.5*(xk - 1920 / 2) / (0.5 * zoom * 1920) + mx;
				newi = (yk - 1080 / 2) / (0.5 * zoom * 1080) + my;
				// printf("%f %f", newm, newi);
				int i = 0;
				while (i < 500)
				{
					oldm = newm;
					oldi = newi;
					newm = oldm * oldm - oldi * oldi + re_c;
					newi = 2 * oldm * oldi + im_c;
					if (newm * newm + newi * newi > 4)
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
					my_mlx_pixel_put(new, xk, yk,  trgb);
				yk++;
			}
			xk++;
		}
		mlx_put_image_to_window(new->mlx, new->win, new->img, 0, 0);
	}
	if (button == 2)
	{
		mlx_destroy_image(new->mlx, new->img);
		mlx_clear_window(new->mlx, new->win);
		new->img = mlx_new_image(new->mlx, 1920, 1080);
		new->addr = mlx_get_data_addr(new->img, &new->bits_per_pixel, &new->line_length, &new->endian);
		double re_c = -0.7;
		double im_c = 0.27015;
		double newm = 0;
		double newi = 0;
		double oldm = 0;
		double oldi = 0;
		double xk = 0;
		double yk = 0;
		double zoom = 1 * 0.5;
		double mx = x / 1920;
		double my = y / 1080;

		while (xk < 1920)
		{
			yk = 0;
			while (yk < 1080)
			{
				newm = 1.5*(xk - 1920 / 2) / (0.5 * zoom * 1920) + mx;
				newi = (yk - 1080 / 2) / (0.5 * zoom * 1080) + my;
				// printf("%f %f", newm, newi);
				int i = 0;
				while (i < 500)
				{
					oldm = newm;
					oldi = newi;
					newm = oldm * oldm - oldi * oldi + re_c;
					newi = 2 * oldm * oldi + im_c;
					if (newm * newm + newi * newi > 4)
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
					my_mlx_pixel_put(new, xk, yk,  trgb);
				yk++;
			}
			xk++;
		}
		mlx_put_image_to_window(new->mlx, new->win, new->img, 0, 0);
	}
	return (0);
}

int	main(void)
{
	t_vars	new;

	new.mlx = mlx_init();
	new.win = mlx_new_window(new.mlx, 1920, 1080, "Hello world!");
	new.img = mlx_new_image(new.mlx, 1920, 1080);
	new.addr = mlx_get_data_addr(new.img, &new.bits_per_pixel, &new.line_length, &new.endian);
	double re_c = -0.7;
	double im_c = 0.27015;
	double newm = 0;
	double newi = 0;
	double oldm = 0;
	double oldi = 0;
	double xk = 0;
	double yk = 0;
	double zoom = 1;
	double mx = 0;
	double my = 0;

	
	while (xk < 1920)
	{
		yk = 0;
		while (yk < 1080)
		{
			newm = 1.5*(xk - 1920 / 2) / (0.5 * zoom * 1920) + mx;
			newi = (yk - 1080 / 2) / (0.5 * zoom * 1080) + my;
			// printf("%f %f", newm, newi);
			int i = 0;
			while (i < 500)
			{
				oldm = newm;
				oldi = newi;
				newm = oldm * oldm - oldi * oldi + re_c;
				newi = 2 * oldm * oldi + im_c;
				if (newm * newm + newi * newi > 4)
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
				my_mlx_pixel_put(&new, xk, yk,  trgb);
			yk++;
		}
		xk++;
	}
	mlx_put_image_to_window(new.mlx, new.win, new.img, 0, 0);
	mlx_hook(new.win, 4, 0, mouse_move, &new);
	mlx_hook(new.win, 17, 1L<<17, ft_exit , 0);
	mlx_hook(new.win, 2, 0, key_check, &new);
	mlx_loop(new.mlx);
}