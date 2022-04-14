#include "minilibx/mlx.h"
#include <math.h>

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
	// c = 0.5 + 0.5i
	// z(k) = is the point on the screen, a pixel point let's say 500 + 500i
	// z(k + 1) = z(k)^2 + c
	// we can divide the imaginary and real part saperately since c don't have direct way of handling it.
	// x(k + 1) = x(k)^2 - y(k)^2 + Re c
	// y(k + 1) = 2x(k)y(k) + Im c

	double re_c = 10;
	double im_c = 10;
	double x_k = 5;
	double y_k = 5;
	double x_k1 = pow(x_k, 2) - pow(y_k, 2) + re_c;
	double y_k1 = 2*x_k*y_k + im_c;
	my_mlx_pixel_put(&img, x_k1, y_k1, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}