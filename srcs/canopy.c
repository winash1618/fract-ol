/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canopy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 06:51:42 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/06/19 07:27:35 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void recursive_canopy(t_frac *frac, t_point p[2], int len, int depth)
{
	t_point p1, p2;

	p1.x = p[1].x + ((p[1].x - p[0].x) * cos(frac->angle) + (p[1].y - p[0].y) * sin(frac->angle)) * frac->ratio;
	p1.y = p[1].y + (-(p[1].x - p[0].x) * sin(frac->angle) + (p[1].y - p[0].y) * cos(frac->angle)) * frac->ratio;
	p2.x = p[1].x + ((p[1].x - p[0].x) * cos(-frac->angle) + (p[1].y - p[0].y) * sin(-frac->angle)) * frac->ratio;
	p2.y = p[1].y + (-(p[1].x - p[0].x) * sin(-frac->angle) + (p[1].y - p[0].y) * cos(-frac->angle)) * frac->ratio;
	plot_line_with_color(frac, p[0], p[1], 0x00FFFFFF);
	if (depth > 0)
	{
		recursive_canopy(frac, (t_point []){p[1], p1}, len * frac->ratio, depth - 1);
		recursive_canopy(frac, (t_point []){p[1], p2}, len * frac->ratio, depth - 1);
	}
}

void render_canopy(t_frac *frac)
{
	t_point start;
	t_point end;
	frac->depth = 12;
	frac->len = 200;
	frac->angle = 2 * M_PI / 11;
	frac->ratio = 0.7;
	start.x = IMG_WIDTH / 2;
	start.y = IMG_HEIGHT - 1;
	end.x = IMG_WIDTH / 2;
	end.y = IMG_HEIGHT - 1 - frac->len;
	recursive_canopy(frac, (t_point []){start, end}, frac->len, frac->depth);
}