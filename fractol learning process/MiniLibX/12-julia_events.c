#include "minilibx/mlx.h"
#include <math.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	keycode++;
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_vars	new;
	t_data	img;

	new.mlx = mlx_init();
	new.win = mlx_new_window(new.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(new.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	double re_c = 0.5;
	double im_c = -0.5;
	double newm = 0;
	double newi = 0;
	double oldm = 0;
	double oldi = 0;
	double xk = 0;
	double yk = 0;
	// double xk1 = 0;
	// double yk1 = 0;

	
	while (xk < 1920)
	{
		yk = 0;
		while (yk < 1080)
		{
			newm = 1.5*(xk - 1920 / 2) / (0.5 * 1920);
			newi = (yk - 1080 / 2) / (0.5 * 1080);
			// printf("%f %f", newm, newi);
	// 		newm = 1.5*(xk - 1920 / 2) / (0.5 * 1920);
	// 		newi = (yk - 1080 / 2) / (0.5 * 1080);
			int i = 0;
			while (i < 1000)
			{
				oldm = newm;
				oldi = newi;
				newm = oldm * oldm - oldi * oldi - re_c;
				newi = 2 * oldm * oldi - im_c;
				if (newm * newm + newi * newi > 4)
					break;
				i++;
			}
			if (newm * newm + newi * newi < 4)
			{
				// printf("%f \n", newm * newm + newi * newi);
				my_mlx_pixel_put(&img, xk, yk, 0x00FF0000);
			}
			yk++;
		}
		xk++;
	}
	mlx_put_image_to_window(new.mlx, new.win, img.img, 0, 0);
	mlx_hook(new.win, 2, 1L<<0, close, &new);
	mlx_loop(new.mlx);
}