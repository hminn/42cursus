/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 17:09:52 by yohlee            #+#    #+#             */
/*   Updated: 2020/10/29 17:58:35 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		set_info(t_info *info, char *path)
{
	init_player(&info->player); // 부분 완료
	if (!parse_cub(info, path)) // 추가 예정
		return (exit_error(info));
	init_player_direction(info); // 추가 예정
	info->mlx = mlx_init(); // 완료
	if (!init_buffer(info)) // 부분 완료
		return (exit_error(info));
	if (!init_texture(info)) // 부분 완료
		return (exit_error(info));
	load_texture(info); // 부분 완료
	info->img.img = mlx_new_image(info->mlx, info->width, info->height);
	info->img.data = (int *)mlx_get_data_addr(\
		info->img.img, &info->img.bpp, &info->img.size_l, &info->img.endian);
	return (1);
}

int		process_option(t_info *info, int option)
{
	if (option == 1)
	{
		raycasting(info);
		sprite_raycasting(info, &info->player);
		if (!save_bmp(info))
			return (exit_error(info));
		ft_exit(0);
	}
	else
	{
		info->win =\
			mlx_new_window(info->mlx, info->width, info->height, "yohlee");
		mlx_hook(info->win, X_EVENT_KEY_PRESS, 0, key_press, info);
		mlx_hook(info->win, X_EVENT_KEY_EXIT, 0, ft_exit, 0);
		mlx_loop_hook(info->mlx, main_loop, info);
		mlx_loop(info->mlx);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_info	info;
	int		option;

	option = (argc >= 2 && (ft_strncmp(argv[1], "--save", 6) == 0)) ? 1 : 0;
	if (argc < option + 2)
		return (exit_error(&info));
	if (!set_info(&info, argv[option + 1]))
		return (exit_error(&info));
	if (!process_option(&info, option))
		return (exit_error(&info));
	free_cub(&info);
	return (0);
}
