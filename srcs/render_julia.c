#include "../includes/fractol.h"

// void init_render(t_vars *new, double x, double y, double zoom)
// {
	
// }

void render_image(t_vars *new, double x, double y, double zoom)
{
	new->re_c = -0.7;
	new->im_c = 0.27015;
	new->newm = 0;
	new->newi = 0;
	new->oldm = 0;
	new->oldi = 0;
	new->xk = 0;
	new->yk = 0;
	new->mx = x / 1920;
	new->my = y / 1080;
	new->zoom = new->zoom * zoom;
	printf("%f", new->zoom);
	fflush(stdout);
	while (new->xk < 1920)
	{
		new->yk = 0;
		while (new->yk < 1080)
		{
			new->newm = 1.5*(new->xk - 1920 / 2) / (0.5 * new->zoom * 1920) + new->mx;
			new->newi = (new->yk - 1080 / 2) / (0.5 * new->zoom * 1080) + new->my;
			// printf("%f %f", newm, newi);
			int i = 0;
			while (i < 500)
			{
				new->oldm = new->newm;
				new->oldi = new->newi;
				new->newm = new->oldm * new->oldm - new->oldi * new->oldi + new->re_c;
				new->newi = 2 * new->oldm * new->oldi + new->im_c;
				// new->newm = new->oldm + new->re_c*sin(tan(3*new->oldi)) ;
				// new->newi = new->oldi + new->im_c * sin(tan(3*new->oldm)) ;
				if (new->newm * new->newm + new->newi * new->newi > 4)
					break;
				i++;
			}
				int t = 255 * (i / 500.0);
				t = t << 24;
				// int r = 255 * (i / 500.0);
				// int g = 255 * (i / 500.0);
				// int b = 255 * (i / 500.0);
				// printf("%d ", r << 16 | g << | b);
				//printf("%d ", i);
				int trgb = 0x12345678 * (i / 500.0);
				trgb = trgb | t;
				
				// if (trgb < 0)
					// printf("%d ", trgb);
				//int trgb = create_trgb(32 * (i / 500),24 * (i / 500),16 * (i / 500),8 * (i / 500 ));
				// if (i == 0)
				// 	my_mlx_pixel_put(new, new->xk, new->yk,  0x0fff0000);
				// else if (i == 1)
				// 	my_mlx_pixel_put(new, new->xk, new->yk,  0x0f00ff00);
				// else if (i < 10)
				// 	my_mlx_pixel_put(new, new->xk, new->yk,  0x000000ff);
				// else if (i < 50)
				// 	my_mlx_pixel_put(new, new->xk, new->yk,  0x001245ff);
				// else if (i < 100)
				// 	my_mlx_pixel_put(new, new->xk, new->yk,  0x0012ff35);
				// else if (i < 180)
				// 	my_mlx_pixel_put(new, new->xk, new->yk,  0xf0ff1224);
				// else if (i < 255)
				// 	my_mlx_pixel_put(new, new->xk, new->yk,  0x001235ff);
				// else 
					my_mlx_pixel_put(new, new->xk, new->yk,  trgb);
			new->yk++;
		}
		new->xk++;
	}
}

void render_translation(t_vars *new, double x, double y)
{
	new->re_c = -0.7;
	new->im_c = 0.27015;
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
			new->newm = 1.5*(new->xk - 1920 / 2) / (0.5 * new->zoom * 1920) + new->mx;
			new->newi = (new->yk - 1080 / 2) / (0.5 * new->zoom * 1080) + new->my;
			// printf("%f %f %f %f \n", new->xk, new->yk, new->newm, new->newi);
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
				int t = 255 * (i / 500.0);
				t = t << 24;
				// int r = 255 * (i / 500.0);
				// int g = 255 * (i / 500.0);
				// int b = 255 * (i / 500.0);
				// printf("%d ", r << 16 | g << | b);
				//printf("%d ", i);
				int trgb = 0x12345678 * (i / 500.0);
				trgb = trgb | t;
				// int t = 0;
				// int r = 255 * (i / 500.0);
				// int g = 255 * (i / 500.0);
				// int b = 255 * (i / 500.0);
				// int trgb = create_trgb(t, r, g, b);
				// if (trgb < 0)
				// 	printf("%d \n", trgb);
				//int trgb = create_trgb(32 * (i / 500),24 * (i / 500),16 * (i / 500),8 * (i / 500 ));
				my_mlx_pixel_put(new, new->xk, new->yk,  trgb);
			new->yk++;
		}
		new->xk++;
	}
	fflush(stdout);
}