#include "fractol.h"

int main(int argc, char **argv)
{
	t_frac *frac;
	(void)argc, (void)argv;
	// if (argc != 2)
	// {
	// 	help_message();
	// 	printf(RED"\nError: Try again!...........\n\n"ANSI_RESET);
	// 	return (0);
	// }
	// parsing(argv[1]);

	frac = (t_frac *)malloc(sizeof(t_frac));
	frac->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	frac->img = (t_img *)malloc(sizeof(t_img));
	frac->mlx->mlx = mlx_init();
	frac->mlx->win = mlx_new_window(frac->mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "frac");
	frac->img->img = mlx_new_image(frac->mlx->mlx, IMG_WIDTH, IMG_HEIGHT);
	frac->img->addr = mlx_get_data_addr(frac->img->img, &frac->img->bits_per_pixel,
										&frac->img->line_length, &frac->img->endian);
	// draw_triangle(frac);
	// render_sierpinski(frac);
	// render_koch(frac);
	// frac->depth = 10000000;
	// render_barnsley(frac);
	render_canopy(frac);

	mlx_put_image_to_window(frac->mlx->mlx, frac->mlx->win, frac->img->img, 0, 0);
	mlx_loop(frac->mlx->mlx);

	return (0);
}
