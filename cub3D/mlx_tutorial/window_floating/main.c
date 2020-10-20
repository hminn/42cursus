#include <mlx.h>

int		main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "mlx_project");
	mlx_loop(mlx);
}
