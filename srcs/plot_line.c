/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 08:40:46 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/06/18 08:43:57 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void plot_line(t_frac *frac, t_point p1, t_point p2)
{
    float dx = abs(p2.x - p1.x);
    float sx = p1.x < p2.x ? 1 : -1;
    float dy = -abs(p2.y - p1.y);
    float sy = p1.y < p2.y ? 1 : -1;
    float error = dx + dy;
    
    while (1)
	{
		my_mlx_pixel_put(frac->img, p1.x, p1.y, 0x00FF0000);
		if (p1.x == p2.x && p1.y == p2.y)
			break;
		float e2 = 2 * error;
		if (e2 >= dy)
		{
			error += dy;
			p1.x += sx;
		}
		if (e2 <= dx)
		{
			error += dx;
			p1.y += sy;
		}
	}
}