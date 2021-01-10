/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:22:42 by hyeokim           #+#    #+#             */
/*   Updated: 2020/11/11 19:33:06 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		init_game_speed(t_info *info)
{
	info->speed_mov = 0.1;
	info->speed_rot = 0.1;
}

static void		init_game_key(t_info *info)
{
	if (!(info->key = malloc(sizeof(t_key))))
		exit_program("Memory allocation failed");
	ft_bzero(info->key, sizeof(t_key));
	info->key->go = 0;
	info->key->back = 0;
	info->key->left = 0;
	info->key->right = 0;
	info->key->turn = 0;
	info->key->cam_up = 0;
	info->key->cam_down = 0;
	info->key->rotate_left = 0;
	info->key->rotate_right = 0;
}

static void		init_game_textures(t_info *info, int cnt)
{
	int idx;

	idx = 0;
	if (!(info->tex = malloc(sizeof(t_img *) * cnt - 1)))
		exit_program("Memory allocation failed");
	while (idx < cnt)
	{
		if (!(info->tex[idx] = malloc(sizeof(t_img))))
			exit_program("Memory allocation failed");
		ft_bzero(info->tex[idx], sizeof(t_img));
		idx++;
	}
}

static void		init_game_sprite(t_info *info)
{
	if (!(info->sprite = malloc(sizeof(t_img))))
		exit_program("Memory allocation failed");
	ft_bzero(info->sprite, sizeof(t_img));
	if (!(info->sprites_on_screen = malloc(sizeof(t_list))))
		exit_program("Memory allocation failed");
	ft_bzero(info->sprites_on_screen, sizeof(t_list));
	info->sprites_on_screen->coord.x = 0;
	info->sprites_on_screen->coord.y = 0;
}

void			init_hub(t_info *info)
{
	init_game_speed(info);
	init_game_key(info);
	init_game_textures(info, 5);
	init_game_sprite(info);
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx,
				info->config.res[X], info->config.res[Y], "cub3D");
	info->img = new_image(info, info->config.res[X], info->config.res[Y]);
	convert_xpm_to_img(info);
}
