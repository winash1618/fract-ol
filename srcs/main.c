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

void	parsing(t_frac *frac, char *choice)
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
		render_sierpinski(frac);
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

void draw_fill_triangle(t_frac *frac)
{
	int start_x = 500;
	int k = 0;
	for (int i = 100; i < start_x; i++)
	{
		for (int j = 0; j < k; j++)
		{
			my_mlx_pixel_put(frac->img, start_x - j, i, 0x00FF0000);
			my_mlx_pixel_put(frac->img, start_x + j, i, 0x00FF0000);
		}
		k++;
	}
}

void draw_triangle(t_frac *frac, t_point *p)
{
	int i = 0;
	while (i < 3)
	{
		if (i == 2)
			plot_line(frac, p[i], p[0]);
		else
			plot_line(frac, p[i], p[i + 1]);
		i++;
	}
}

static void recursive_koch(t_frac *frac, t_point *p, int depth)
{
	if (depth == 0)
	{
		return ;
	}
	t_point *new_p;
	new_p = (t_point *)malloc(sizeof(t_point) * 9);
	new_p[0].x = p[0].x + (p[1].x - p[0].x) / 3.0;
	new_p[0].y = p[0].y + (p[1].y - p[0].y) / 3.0;
	new_p[1].x = p[0].x + (p[1].x - p[0].x) / 3.0 * 2.0;
	new_p[1].y = p[0].y + (p[1].y - p[0].y) / 3.0 * 2.0;
	new_p[2].x = (new_p[1].x - new_p[0].x) * cos(60.0 * M_PI / 180.0) - (new_p[1].y - new_p[0].y) * sin(60.0 * M_PI / 180.0) + new_p[0].x;
	new_p[2].y = (new_p[1].x - new_p[0].x) * sin(60.0 * M_PI / 180.0) + (new_p[1].y - new_p[0].y) * cos(60.0 * M_PI / 180.0) + new_p[0].y;
	new_p[3].x = p[1].x + (p[2].x - p[1].x) / 3.0;
	new_p[3].y = p[1].y + (p[2].y - p[1].y) / 3.0;
	new_p[4].x = p[1].x + (p[2].x - p[1].x) / 3.0 * 2.0;
	new_p[4].y = p[1].y + (p[2].y - p[1].y) / 3.0 * 2.0;
	new_p[5].x = (new_p[4].x - new_p[3].x) * cos(60.0 * M_PI / 180.0) - (new_p[4].y - new_p[3].y) * sin(60.0 * M_PI / 180.0) + new_p[3].x;
	new_p[5].y = (new_p[4].x - new_p[3].x) * sin(60.0 * M_PI / 180.0) + (new_p[4].y - new_p[3].y) * cos(60.0 * M_PI / 180.0) + new_p[3].y;
	new_p[6].x = p[2].x + (p[0].x - p[2].x) / 3.0;
	new_p[6].y = p[2].y + (p[0].y - p[2].y) / 3.0;
	new_p[7].x = p[2].x + (p[0].x - p[2].x) / 3.0 * 2.0;
	new_p[7].y = p[2].y + (p[0].y - p[2].y) / 3.0 * 2.0;
	new_p[8].x = (new_p[7].x - new_p[6].x) * cos(60.0 * M_PI / 180.0) - (new_p[7].y - new_p[6].y) * sin(60.0 * M_PI / 180.0) + new_p[6].x;
	new_p[8].y = (new_p[7].x - new_p[6].x) * sin(60.0 * M_PI / 180.0) + (new_p[7].y - new_p[6].y) * cos(60.0 * M_PI / 180.0) + new_p[6].y;
	plot_line_with_color(frac, new_p[0], new_p[1], 0);
	plot_line(frac, new_p[2], new_p[1]);
	plot_line(frac, new_p[2], new_p[0]);
	plot_line_with_color(frac, new_p[3], new_p[4], 0);
	plot_line(frac, new_p[4], new_p[5]);
	plot_line(frac, new_p[5], new_p[3]);
	plot_line_with_color(frac, new_p[7], new_p[6], 0);
	plot_line(frac, new_p[6], new_p[8]);
	plot_line(frac, new_p[7], new_p[8]);
	recursive_koch(frac, new_p, depth - 1);
	// recursive_koch(frac, (t_point[]){p[0], new_p[0], new_p[7]}, depth - 1);
	recursive_koch(frac, new_p + 3, depth - 1);
	// recursive_koch(frac, (t_point[]){new_p[1], p[1], new_p[3]}, depth - 1);
	recursive_koch(frac, new_p + 6, depth - 1);
	// recursive_koch(frac, (t_point[]){new_p[4], new_p[7], p[2]}, depth - 1);
	free(new_p);
}


void render_koch(t_frac *frac)
{
	t_point *p;

	p = (t_point *)malloc(sizeof(t_point) * 3);
	p[0].x = 100.0;
	p[0].y = 700.0;
	p[1].x = 700.0;
	p[1].y = 700.0;
	p[2].x = 400.0;
	p[2].y = 700.0 - sqrt(600.0 * 600.0 - 300.0 * 300.0);
	frac->depth = 2;
	draw_triangle(frac, p);
	recursive_koch(frac, p, frac->depth);
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
	// draw_triangle(frac);
	// render_sierpinski(frac);
	render_koch(frac);
	mlx_put_image_to_window(frac->mlx->mlx, frac->mlx->win, frac->img->img, 0, 0);
	mlx_loop(frac->mlx->mlx);

	return (0);
}

