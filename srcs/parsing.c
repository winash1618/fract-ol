/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 06:48:02 by mkaruvan          #+#    #+#             */
/*   Updated: 2023/06/19 06:48:11 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void help_message(void)
{
	printf("\n\033[32;1musage: ./fractol fractal_name\033[0;36m");
	printf("\n\tAvailable fractals:");
	printf("\n\t- Mandelbrot\n\t- Julia\n\t- Burning Ship");
	printf("\t- Burning Julia\n\t- Sierpinski\n\t- Koch\n\t- Barnsley");
	printf("\t- Flower");
	printf("\n\tUse \"./fractol menu\" to display the main menu window\n");
}

void parsing(t_frac *frac, char *choice)
{
	if (ft_strncmp(choice, "Mandelbrot", 10) == 0)
		printf("Mandelbrot\n");
	else if (ft_strncmp(choice, "Julia", 5) == 0)
		printf("Julia\n");
	else if (ft_strncmp(choice, "Burning Ship", 12) == 0)
		printf("Burning Ship\n");
	else if (ft_strncmp(choice, "Burning Julia", 13) == 0)
		printf("Burning Julia\n");
	else if (ft_strncmp(choice, "Sierpinski", 10) == 0)
		render_sierpinski(frac);
	else if (ft_strncmp(choice, "Koch", 4) == 0)
		render_koch(frac);
	else if (ft_strncmp(choice, "Barnsley", 8) == 0)
		render_barnsley(frac);
	else if (ft_strncmp(choice, "Flower", 6) == 0)
		printf("Flower\n");
	else if (ft_strncmp(choice, "Canopy", 4) == 0)
		render_canopy(frac);
	else if (ft_strncmp(choice, "menu", 4) == 0)
		printf("menu\n");
	else
	{
		help_message();
		printf("\nTry again!...........\n");
	}
}
