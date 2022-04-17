#include "../includes/fractol.h"

void	ft_help(void)
{
	write(1, "Wrong number of arguements \n", 29);
	write(1, "Fractol's available: use following format. \n", 45);
	write(1, "         1. Julia set >>./fractol 1 \n", 38);
	write(1, "         2. Mandelbrot set >>./fractol 2\n", 42);
}

void	ft_error(void)
{
	write(1, "wrong arguement format \n", 29);
	write(1, "Fractol's available: use following format. \n", 45);
	write(1, "         1. Julia set >>./fractol 1 \n", 38);
	write(1, "         2. Mandelbrot set >>./fractol 2\n", 42);
}

void	init_fractol(t_vars *new, char *str)
{
	new->win_width = 540;
	new->win_hight = 400;
	new->mx = 0;
	new->my = 0;
	new->zoom = 1;
	new->mlx = mlx_init();
	new->win = mlx_new_window(new->mlx, new->win_width, new->win_hight, "Hello world!");
	new->img = mlx_new_image(new->mlx, new->win_width, new->win_hight);
	new->addr = mlx_get_data_addr(new->img, &new->bits_per_pixel, &new->line_length, &new->endian);
	new->zoom = 1;
	if (str[0] == '1' && str[1] == '\0')
		new->flag = 1;
	else if (str[0] == '2' && str[1] == '\0')
		new->flag = 2;
}

int	main(int ac, char **av)
{
	t_vars	*new;

	if (ac == 2)
	{
		new = (t_vars *)malloc(sizeof(t_vars));
		if (!new)
			return (0);
		init_fractol(new, av[1]);
		if (av[1][0] == '1' && av[1][1] == '\0')
			render_image(new, 0, 0, 1);
		else if (av[1][0] == '2' && av[1][1] == '\0')
			render_image_m(new, 0, 0, 1);
		else
			ft_error();
		mlx_put_image_to_window(new->mlx, new->win, new->img, 0, 0);
		mlx_hook(new->win, 4, 0, mouse_move, new);
		mlx_hook(new->win, 17, 1L<<17, ft_exit , 0);
		mlx_hook(new->win, 2, 0, key_check, new);
		mlx_loop(new->mlx);
	}
	else
		ft_help();
	return (0);
}