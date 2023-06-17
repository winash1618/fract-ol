/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:12:16 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/06/17 17:22:45 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include "color.h"
# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
# define IMG_WIDTH 1000
# define IMG_HEIGHT 1000
# define PI 3.14159265359

typedef struct	s_img {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_mlx {
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct	s_frac
{
	t_mlx		*mlx;
	t_img		*img;
	int			img_arr[WIN_WIDTH][WIN_HEIGHT];
}				t_frac;


#endif
