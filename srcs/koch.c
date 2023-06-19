/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:04:37 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/06/18 14:04:44 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void recursive_koch(t_frac *frac, t_point p1, t_point p2, int depth)
{
	t_point *p;
	double angle = 60 * M_PI / 180;
	p = (t_point *)malloc(sizeof(t_point) * 3);
	p[0].x = (2 * p1.x + p2.x) / 3;
	p[0].y = (2 * p1.y + p2.y) / 3;
	p[2].x = (p1.x + 2 * p2.x) / 3;
	p[2].y = (p1.y + 2 * p2.y) / 3;
	p[1].x = p[0].x + (p[2].x - p[0].x) * cos(angle) + (p[2].y - p[0].y) * -sin(angle); // change the sign of sin(angle) to do an inverse koch
	p[1].y = p[0].y + (p[2].x - p[0].x) * sin(angle) + (p[2].y - p[0].y) * cos(angle);
	if (depth == 0)
		plot_line(frac, p1, p2);
	else
	{
		recursive_koch(frac, p1, p[0], depth - 1);
		recursive_koch(frac, p[0], p[1], depth - 1);
		recursive_koch(frac, p[1], p[2], depth - 1);
		recursive_koch(frac, p[2], p2, depth - 1);
	}
	free(p);
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
	recursive_koch(frac, p[0], p[1], frac->depth);
	recursive_koch(frac, p[1], p[2], frac->depth);
	recursive_koch(frac, p[2], p[0], frac->depth);
}