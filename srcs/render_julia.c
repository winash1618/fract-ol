#include "../includes/fractol.h"

void render_image(t_vars *new, double x, double y, double zoom)
{
	init_zoom(new, x, y, zoom);
	while (new->xk < 1920)
	{
		new->yk = 0;
		while (new->yk < 1080)
		{
			new->newm = 1.5*(new->xk - 1920 / 2) / (0.5 * new->zoom * 1920) + new->mx;
			new->newi = (new->yk - 1080 / 2) / (0.5 * new->zoom * 1080) + new->my;
			new->i = 0;
			i_breaker(new);
			int t = 255 * (new->i / 500.0);
			t = t << 24;
			new->trgb = new->base_color * (new->i / 500.0);
			new->trgb = new->trgb | t;
			my_mlx_pixel_put(new, new->xk, new->yk,  new->trgb);
			new->yk++;
		}
		new->xk++;
	}
}

void render_translation(t_vars *new, double x, double y)
{
	init_translation(new, x, y);
	while (new->xk < 1920)
	{
		new->yk = 0;
		while (new->yk < 1080)
		{
			new->newm = 1.5*(new->xk - 1920 / 2) / (0.5 * new->zoom * 1920) + new->mx;
			new->newi = (new->yk - 1080 / 2) / (0.5 * new->zoom * 1080) + new->my;
			new->i = 0;
			i_breaker(new);
			int t = 255 * (new->i / 500.0);
			t = t << 24;
			new->trgb = new->base_color * (new->i / 500.0);
			new->trgb = new->trgb | t;
			my_mlx_pixel_put(new, new->xk, new->yk,  new->trgb);
			new->yk++;
		}
		new->xk++;
	}
	fflush(stdout);
}