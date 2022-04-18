/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:13:32 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/04/18 06:50:50 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	init_zoom(t_vars *new, double x, double y, double zoom)
{
	new->max_iter = 500;
	new->i = 0;
	new->newm = 0;
	new->newi = 0;
	new->oldm = 0;
	new->oldi = 0;
	new->xk = 0;
	new->yk = 0;
	new->mx = x / (new->win_width);
	new->my = y / (new->win_hight);
	new->zoom *= zoom;
}

void	init_translation(t_vars *new, double x, double y)
{
	new->max_iter = 500;
	new->i = 0;
	new->newm = 0;
	new->newi = 0;
	new->oldm = 0;
	new->oldi = 0;
	new->xk = 0;
	new->yk = 0;
	new->mx += x / (new->win_width);
	new->my += y / (new->win_hight);
}

void	i_breaker(t_vars *new)
{
	while (new->i < new->max_iter)
	{
		new->oldm = new->newm;
		new->oldi = new->newi;
		new->newm = new->oldm * new->oldm - new->oldi * new->oldi + new->re_c;
		new->newi = 2 * new->oldm * new->oldi + new->im_c;
		if (new->newm * new->newm + new->newi * new->newi > 4)
			break ;
		new->i++;
	}
}
