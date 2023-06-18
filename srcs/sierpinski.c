/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 08:36:48 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/06/18 08:50:06 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void recursive_sierpinski(t_frac *frac, t_point *point, int depth)
{
	t_point *new_point;

	if (depth == 0)
		return ;
	new_point = (t_point *)malloc(sizeof(t_point) * 3);
	new_point[0].x = (point[0].x + point[1].x) / 2;
	new_point[0].y = (point[0].y + point[1].y) / 2;
	new_point[1].x = (point[1].x + point[2].x) / 2;
	new_point[1].y = (point[1].y + point[2].y) / 2;
	new_point[2].x = (point[2].x + point[0].x) / 2;
	new_point[2].y = (point[2].y + point[0].y) / 2;
	plot_line(frac, point[0], point[1]);
	plot_line(frac, point[1], point[2]);
	plot_line(frac, point[2], point[0]);
	recursive_sierpinski(frac, (t_point[]){point[0], new_point[0], new_point[2]}, depth - 1);
	recursive_sierpinski(frac, (t_point[]){new_point[0], point[1], new_point[1]}, depth - 1);
	recursive_sierpinski(frac, (t_point[]){new_point[2], new_point[1], point[2]}, depth - 1);
	free(new_point);
}

void render_sierpinski(t_frac *frac)
{
	t_point *point;

	point = (t_point *)malloc(sizeof(t_point) * 3);

	point[0].x = 100;
	point[0].y = 700;
	point[1].x = 700;
	point[1].y = 700;
	point[2].x = 400;
	point[2].y = 700 - sqrt(600 * 600 - 300 * 300);
	frac->depth = 5;
	recursive_sierpinski(frac, point, frac->depth);
	free(point);
}
