/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:13:10 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/04/18 06:42:46 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_julia(t_vars *new)
{
	double	temp1;
	double	temp2;

	if (new->re_c != 0)
	{
		temp1 = 1.5 * (new->xk - new->win_width / 2);
		temp2 = (0.5 * new->zoom * new->win_width);
		new->newm = temp1 / temp2 + new->mx;
	}
	if (new->im_c != 0)
	{
		temp1 = (new->yk - new->win_hight / 2);
		temp2 = (0.5 * new->zoom * new->win_hight);
		new->newi = temp1 / temp2 + new->my;
	}
	new->i = 0;
}

void	render_image(t_vars *new, double x, double y, double zoom)
{
	init_zoom(new, x, y, zoom);
	while (new->xk < new->win_width)
	{
		new->yk = 0;
		while (new->yk < new->win_hight)
		{
			init_julia(new);
			i_breaker(new);
			new->t = 255 * (new->i / (float)(new->max_iter));
			new->t = new->t << 24;
			new->trgb = new->base_color * (new->i / (float)(new->max_iter));
			new->trgb = new->trgb | new->t;
			my_mlx_pixel_put(new, new->xk, new->yk, new->trgb);
			new->yk++;
		}
		new->xk++;
	}
}

void	render_translation(t_vars *new, double x, double y)
{
	init_translation(new, x, y);
	while (new->xk < new->win_width)
	{
		new->yk = 0;
		while (new->yk < new->win_hight)
		{
			init_julia(new);
			i_breaker(new);
			new->t = 255 * (new->i / (float)(new->max_iter));
			new->t = new->t << 24;
			new->trgb = new->base_color * (new->i / (float)(new->max_iter));
			new->trgb = new->trgb | new->t;
			my_mlx_pixel_put(new, new->xk, new->yk, new->trgb);
			new->yk++;
		}
		new->xk++;
	}
	fflush(stdout);
}
