/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barnsley.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 14:31:32 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/06/18 14:32:02 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void render_barnsley(t_frac *frac)
{
	double x = 0.0;
	double y = 0.0;
	int n = 0;
	while (n++ < frac->depth)
	{
		double r = (double)rand() / (double)RAND_MAX;
		if (r < 0.01)
		{
			x = 0.0;
			y = 0.16 * y;
		}
		else if (r < 0.86)
		{
			double x0 = x;
			x = 0.85 * x + 0.04 * y;
			y = -0.04 * x0 + 0.85 * y + 1.6;
		}
		else if (r < 0.93)
		{
			double x0 = x;
			x = 0.2 * x - 0.26 * y;
			y = 0.23 * x0 + 0.22 * y + 1.6;
		}
		else
		{
			double x0 = x;
			x = -0.15 * x + 0.28 * y;
			y = 0.26 * x0 + 0.24 * y + 0.44;
		}
		double x1 = 0.5 * x + 0.5 * y;
		double y1 = -0.5 * x + 0.5 * y;

		my_mlx_pixel_put(frac->img, 100 * x1 + 300 , 100 * y1 + 200, 0x0000FF00);
	}
}