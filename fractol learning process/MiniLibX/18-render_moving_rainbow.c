#include "minilibx/mlx.h"
#include <math.h>
#include <stdio.h>
typedef struct	s_vars {
	void	*mlx;
	void	*win;
	double	x;
	double y;
}	t_vars;


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

int	key_check(int keycode, t_vars *vars)
{
	printf("%d", keycode);
	fflush(stdout);
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	return (keycode);
}
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	main(void)
{
	t_vars	new;
	t_data	img;

	new.mlx = mlx_init();
	new.win = mlx_new_window(new.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(new.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);double re_c = 0.5;
	
	double newm = 0;
	double newi = 0;
	double oldm = 0;
	double oldi = 0;
	double xk = 0;
	double yk = 0;
	
	while (xk < 1920)
	{
		yk = 0;
		while (yk < 1080)
		{
			int trgb = create_trgb(t, r, g, b);
			my_mlx_pixel_put(&img, xk, yk,  trgb);
			yk++;
		}
		xk++;
	}
	mlx_put_image_to_window(new.mlx, new.win, img.img, 0, 0);
	mlx_hook(new.win, 2, 0, key_check, &new);
	mlx_loop(new.mlx);
}



























