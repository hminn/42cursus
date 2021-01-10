/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:12:52 by hyeokim           #+#    #+#             */
/*   Updated: 2020/11/11 22:14:28 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		main_loop(void *parameter)
{
	t_info *info;

	info = (t_info *)parameter;
	if (!(raycasting(info)))
		exit(EXIT_FAILURE);
	key_manager(info);
	return (1);
}

static void		mlx_hub(t_info *info)
{
	mlx_hook(info->win, MLX_KEY_PRESS, 0, key_pressed, info);
	mlx_hook(info->win, MLX_KEY_RELEASE, 0, key_released, info);
	mlx_hook(info->win, MLX_KEY_EXIT, 0, exit_window, info);
	mlx_loop_hook(info->mlx, &main_loop, info);
	mlx_loop(info->mlx);
}

int				main(int argc, char *argv[])
{
	t_info		*info;

	if (!(info = (t_info *)malloc(sizeof(t_info))))
		exit_program("Memory allocation failed");
	parse_hub(argc, argv, info);
	init_hub(info);
	mlx_hub(info);
	return (EXIT_SUCCESS);
}
