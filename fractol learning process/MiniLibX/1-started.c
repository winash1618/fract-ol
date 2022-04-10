#include "minilibx/mlx.h"

int	main(void)
{
	void	*mlx;

	mlx = mlx_init();
}
// When you run the code, you can’t help but 
// notice that nothing pops up and that nothing is being rendered.
// Well, this obviously has something to do with the fact that you are not creating a window yet