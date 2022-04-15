#include "minilibx/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
int	ft_exit(void)
{
	exit (1);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
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
			while (i < 100)
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
				my_mlx_pixel_put(&img, xk, yk,);
			}
			yk++;
		}
		xk++;
	}
	mlx_hook(mlx_win, 17, 1L<<17, ft_exit , 0);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}