#include "../includes/fractol.h"

static void	init_mandelbrot(t_vars *new)
{
	double temp1;
	double temp2;

	temp1 =	1.5 * (new->xk - new->win_width / 2);
	temp2 =(0.5 * new->zoom * new->win_width);
	new->re_c = temp1 / temp2 + new->mx;
	temp1 = (new->yk - new->win_hight / 2);
	temp2 = (0.5 * new->zoom * new->win_hight);
	new->im_c = temp1 / temp2 + new->my;
	new->newm = 0;
	new->newi = 0;
	new->oldm = 0;
	new->oldi = 0;
	new->i = 0;
}

void	render_image_m(t_vars *new, double x, double y, double zoom)
{
	init_zoom(new, x, y, zoom);
	while (new->xk < new->win_width)
	{
		new->yk = 0;
		while (new->yk < new->win_hight)
		{
			init_mandelbrot(new);
			i_breaker(new);
			new->trgb = new->base_color * (new->i / (float)(new->max_iter));
			my_mlx_pixel_put(new, new->xk, new->yk, new->trgb);
			new->yk++;
		}
		new->xk++;
	}
}

void render_translation_m(t_vars *new, double x, double y)
{
	init_translation(new, x, y);
	while (new->xk < new->win_width)
	{
		new->yk = 0;
		while (new->yk < new->win_hight)
		{
			init_mandelbrot(new);
			i_breaker(new);
			new->trgb = new->base_color * (new->i / (float)(new->max_iter));
			my_mlx_pixel_put(new, new->xk, new->yk, new->trgb);
			new->yk++;
		}
		new->xk++;
	}
}