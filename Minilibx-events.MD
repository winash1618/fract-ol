# Minilibx : Events [read more](https://harm-smits.github.io/42docs/libs/minilibx/events.html)
## Introduction
  - Events are the foundation of writing interactive applications in MiniLibX. It is therefore of essence that you fully comprehend this chapter
  as this will be of use in your future graphical projects.
  - All hooks in MiniLibX are nothing more than a function that gets called whenever a event is triggered. Mastering all these events won’t be
  neccessary, however, we will quickly go over each X11 event accordingly.
## MacOS version
  - On MacOS - Cocoa (AppKit) and OpenGL - version, minilibx has partial support of X11 events and doesn’t support X11 mask (x_mask argument of 
  mlx_hook is useless, keep it at 0).
## Supported events:
```
  enum {
    ON_KEYDOWN = 2,
    ON_KEYUP = 3,
    ON_MOUSEDOWN = 4,
    ON_MOUSEUP = 5,
    ON_MOUSEMOVE = 6,
    ON_EXPOSE = 12,
    ON_DESTROY = 17
  };

  // usage:
  mlx_hook(vars.win, ON_DESTROY, 0, close, &vars);
```
- If you can’t figure out what some events are, don’t worry, because you probably won’t need them. If you do, 
[go read the documentation of each X11 events](https://tronche.com/gui/x/xlib/events/).

## Examples
### Mouse enters the window, you should print Hello! in your terminal, when it leaves, you should print Bye!
```
#include "minilibx/mlx.h"
#include <math.h>
#include <stdio.h>
typedef struct	s_vars {
	void	*mlx;
	void	*win;
	double	x;
	double y;
}	t_vars;


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

int	key_check(int keycode, t_vars *vars)
{
	printf("%d", keycode);
	fflush(stdout);
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	return (keycode);
}
int	mouse_move(int x, int y, t_vars *vars)
{
	if(x > 0 && y > 0)
	{
		printf("Hello! Welcome to the screen \n");
		fflush(stdout);
	}
	else
	{
		printf("Bye \n");
		fflush(stdout);
	}
	(void)vars;
	return (0);
}
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_vars	new;
	t_data	img;

	new.mlx = mlx_init();
	new.win = mlx_new_window(new.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(new.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_put_image_to_window(new.mlx, new.win, img.img, 0, 0);
	mlx_hook(new.win, 2, 0, key_check, &new);
	mlx_hook(new.win, 6, 0, mouse_move, &new);
	mlx_loop(new.mlx);
}
```
