#include "../includes/fractol.h"

// void render_image(t_vars *new, double x, double y, double zoom)
// {

// }
void render_image_m(t_vars *new, double x, double y, double zoom)
{
	//init_render(new, x, y, zoom);
	new->newm = 0;
	new->newi = 0;
	new->oldm = 0;
	new->oldi = 0;
	new->xk = 0;
	new->yk = 0;
	new->mx = x / 1920;
	new->my = y / 1080;
	new->mx = 0;
	new->my = 0;
	new->zoom = new->zoom * zoom;
	printf("%f", new->zoom);
	fflush(stdout);
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
			int i = 0;
			while (i < 500)
			{
				new->oldm = new->newm;
				new->oldi = new->newi;
				new->newm = new->oldm * new->oldm - new->oldi * new->oldi + new->re_c;
				new->newi = 2 * new->oldm * new->oldi + new->im_c;
				if (new->newm * new->newm + new->newi * new->newi > 4)
					break;
				i++;
			}
				int max =  0x12345678;
				int trgb = max * (i / 500.0);
				my_mlx_pixel_put(new, new->xk, new->yk,  trgb);
			new->yk++;
		}
		new->xk++;
	}
}

void render_translation_m(t_vars *new, double x, double y)
{
	new->newm = 0;
	new->newi = 0;
	new->oldm = 0;
	new->oldi = 0;
	new->xk = 0;
	new->yk = 0;
	new->mx += x / 1920;
	new->my += y / 1080;
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
			int i = 0;
			while (i < 500)
			{
				new->oldm = new->newm;
				new->oldi = new->newi;
				new->newm = new->oldm * new->oldm - new->oldi * new->oldi + new->re_c;
				new->newi = 2 * new->oldm * new->oldi + new->im_c;
				if (new->newm * new->newm + new->newi * new->newi > 4)
					break;
				i++;
			}
			int max =  0x12345678;
				int trgb = max * (i / 500.0);
				my_mlx_pixel_put(new, new->xk, new->yk,  trgb);
			new->yk++;
		}
		new->xk++;
	}
}