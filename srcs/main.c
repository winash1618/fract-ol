#include "fractol.h"

void		help_message(void)
{
	printf("\n\033[32;1musage: ./fractol fractal_name\033[0;36m");
	printf("\n\tAvailable fractals:");
	printf("\n\t- Mandelbrot\n\t- Julia\n\t- Burning Ship");
	printf("\t- Burning Julia\n\t- Sierpinski\n\t- Koch\n\t- Barnsley");
	printf("\t- Flower");
	printf("\n\tUse \"./fractol menu\" to display the main menu window\n");
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	parsing(char *choice)
{
	if (ft_strncmp(choice, "Mandelbrot", 10) == 0)
		printf("Mandelbrot\n");
	else if (ft_strncmp(choice, "Julia", 5) == 0)
		printf("Julia\n");
	else if (ft_strncmp(choice, "Burning Ship", 12) == 0)
		printf("Burning Ship\n");
	else if (ft_strncmp(choice, "Burning Julia", 13) == 0)
		printf("Burning Julia\n");
	else if (ft_strncmp(choice, "Sierpinski", 10) == 0)
		printf("Sierpinski\n");
	else if (ft_strncmp(choice, "Koch", 4) == 0)
		printf("Koch\n");
	else if (ft_strncmp(choice, "Barnsley", 8) == 0)
		printf("Barnsley\n");
	else if (ft_strncmp(choice, "Flower", 6) == 0)
		printf("Flower\n");
	else if (ft_strncmp(choice, "menu", 4) == 0)
		printf("menu\n");
	else
	{
		help_message();
		printf("\nTry again!...........\n");
	}
}

void draw_triangle(t_frac *frac)
{
	int start_x;
	int start_y;

	start_x = 500;
	start_y = 100;
	int start = 0;
	int count = 0;
	while (start_y < 500)
	{
	printf("start_x = %d\n", start_x);
	printf("start_y = %d\n", start_y);
	printf("start = %d\n", start);
	printf("count = %d\n", count);
	printf("-------------------\n");
	count = 0;
		while (start_x <= 500 + start)
		{
			my_mlx_pixel_put(frac->img, 500 + count, start_y, 0x00FF0000);
			my_mlx_pixel_put(frac->img, 500 - count, start_y, 0x00FF0000);
			start_x++;
			count++;
		}
		start= count;
		start_x = start_x - count;
		start_y++;
	}
}

int main(int argc, char **argv)
{
	t_frac *frac;
	(void) argc, (void) argv;
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
	draw_triangle(frac);
	mlx_put_image_to_window(frac->mlx->mlx, frac->mlx->win, frac->img->img, 0, 0);
	mlx_loop(frac->mlx->mlx);

	return (0);
}

