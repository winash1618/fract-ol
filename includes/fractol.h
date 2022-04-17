#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <unistd.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	re_c;
	double	im_c;
	double	newm;
	double	newi;
	double	oldm;
	double	oldi;
	double	xk;
	double	yk;
	double	zoom;
	double	mx;
	double	my;
	int		win_width;
	int		win_hight;
	int		base_color;
	int		i;
	int		trgb;
	int		max_iter;
}	t_vars;

int key_check(int keycode, t_vars *new);
int mouse_move(int button, int x, int y, t_vars *new);
int ft_exit(void);
void render_image(t_vars *new, double x, double y, double zoom);
void render_translation(t_vars *new, double x, double y);
void render_image_m(t_vars *new, double x, double y, double zoom);
void render_translation_m(t_vars *new, double x, double y);
void my_mlx_pixel_put(t_vars *data, int x, int y, int color);
void i_breaker(t_vars *new);
void init_translation(t_vars *new, double x, double y);
void init_zoom(t_vars *new, double x, double y, double zoom);

#endif