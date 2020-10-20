#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>

# define X_EVENT_KEY_PRESS		2
# define KEY_ESC				53
# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2


typedef struct s_param{
	void		*mlx;
	void		*win;
}				t_param;	

int	key_press(int keycode, t_param *param)
{
	void	*img;

	int		img_width;
	int		img_height;
	
	if (keycode == KEY_W)
		img = mlx_xpm_file_to_image(param->mlx, "../textures/wall_n.xpm", &img_width, &img_height);
	else if (keycode == KEY_S)
		img = mlx_xpm_file_to_image(param->mlx, "../textures/wall_s.xpm", &img_width, &img_height);
	else if (keycode == KEY_A)
		img = mlx_xpm_file_to_image(param->mlx, "../textures/wall_w.xpm", &img_width, &img_height);
	else if (keycode == KEY_D)
		img = mlx_xpm_file_to_image(param->mlx, "../textures/wall_e.xpm", &img_width, &img_height);
	else if (keycode == KEY_ESC)
		exit(0);
	else
		img = 0;
	if (img)
		mlx_put_image_to_window(param->mlx, param->win, img, 200, 200);
	return (0);
}

int	main()
{
	void	*mlx;
	void	*win;
	t_param	param;

	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 700, 700, "my_mlx");
	mlx_hook(param.win, X_EVENT_KEY_PRESS, 0, &key_press, &param);
	mlx_loop(param.mlx);
	return (0);
}
