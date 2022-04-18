/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:48:27 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/04/18 13:48:29 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	color_shift(t_vars *new, int color)
{
	new->base_color = color;
	if (new->flag == 1)
		render_image(new, 0, 0, 1);
	else if (new->flag == 2)
		render_image_m(new, 0, 0, 1);
	mlx_put_image_to_window(new->mlx, new->win, new->img, 0, 0);
}

void	ft_help(void)
{
	write(1, "Wrong number of arguements \n", 29);
	write(1, "Fractol's available: use following format. \n", 45);
	write(1, "         1. Julia set >>./fractol 1 re_c(-2,2) im_c(-2,2)\n", 59);
	write(1, "For example : >>./fractol 1 -0.7 0.27015\n", 42);
	write(1, "         2. Mandelbrot set >>./fractol 2\n", 42);
}

void	ft_error(t_vars *new)
{
	write(1, "wrong arguement format \n", 29);
	write(1, "Fractol's available: use following format. \n", 45);
	write(1, "         1. Julia set >>./fractol 1 re_c(-2,2) im_c(-2,2)\n", 59);
	write(1, "For example : >>./fractol 1 -0.7 0.27015\n", 42);
	write(1, "         2. Mandelbrot set >>./fractol 2\n", 42);
	free(new);
	exit(1);
}

void	init_fractol(t_vars *new, char **av, int ac)
{
	new->base_color = 0x12345678;
	new->win_width = 540;
	new->win_hight = 400;
	new->mx = 0;
	new->my = 0;
	new->zoom = 1;
	new->mlx = mlx_init();
	new->win = mlx_new_window(new->mlx, new->win_width, new->win_hight, "frac");
	new->img = mlx_new_image(new->mlx, new->win_width, new->win_hight);
	new->addr = mlx_get_data_addr(new->img, &new->bpp, &new->len, &new->end);
	new->zoom = 1;
	if (av[1][0] == '1' && av[1][1] == '\0' && ac == 4)
	{
		new->re_c = ft_atof(av[2], new);
		new->im_c = ft_atof(av[3], new);
		new->flag = 1;
	}
	else if (av[1][0] == '2' && av[1][1] == '\0' && ac == 2)
	{
		new->re_c = 0;
		new->im_c = 0;
		new->flag = 2;
	}
	else
		ft_error(new);
}

int	main(int ac, char **av)
{
	t_vars	*new;

	if (ac <= 4 && ac > 0 && ac != 1 && ac != 3)
	{
		new = (t_vars *)malloc(sizeof(t_vars));
		if (!new)
			return (0);
		init_fractol(new, av, ac);
		if (av[1][0] == '1' && av[1][1] == '\0')
			render_image(new, 0, 0, 1);
		else if (av[1][0] == '2' && av[1][1] == '\0')
			render_image_m(new, 0, 0, 1);
		else
			ft_error(new);
		mlx_put_image_to_window(new->mlx, new->win, new->img, 0, 0);
		mlx_hook(new->win, 4, 0, mouse_move, new);
		mlx_hook(new->win, 17, 1L << 17, ft_exit, 0);
		mlx_hook(new->win, 2, 0, key_check, new);
		mlx_loop(new->mlx);
	}
	else
		ft_help();
	return (0);
}
