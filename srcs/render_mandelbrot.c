#include "../includes/fractol.h"

void render_image_m(t_vars *new, double x, double y, double zoom)
{
	init_zoom(new, x, y, zoom);
	while (new->xk < 1920)
	{
		new->yk = 0;
		while (new->yk < 1080)
		{
			new->re_c = 1.5 * (new->xk - 1920 / 2) / (0.5 * new->zoom * 1920) + new->mx;
			new->im_c = (new->yk - 1080 / 2) / (0.5 * new->zoom * 1080) + new->my;
			new->newm = 0;
			new->newi = 0;
			new->oldm = 0;
			new->oldi = 0;
			new->i = 0;
			i_breaker(new);
			new->trgb = new->base_color * (new->i / 500.0);
			my_mlx_pixel_put(new, new->xk, new->yk, new->trgb);
			new->yk++;
		}
		new->xk++;
	}
}

void render_translation_m(t_vars *new, double x, double y)
{
	init_translation(new, x, y);
	while (new->xk < 1920)
	{
		new->yk = 0;
		while (new->yk < 1080)
		{
			new->re_c = 1.5*(new->xk - 1920 / 2) / (0.5 * new->zoom * 1920) + new->mx;
			new->im_c = (new->yk - 1080 / 2) / (0.5 * new->zoom * 1080) + new->my;
			new->newm = 0;
			new->newi = 0;
			new->oldm = 0;
			new->oldi = 0;
			new->i = 0;
			i_breaker(new);
			new->trgb = new->base_color * (new->i / 500.0);
			my_mlx_pixel_put(new, new->xk, new->yk, new->trgb);
			new->yk++;
		}
		new->xk++;
	}
}