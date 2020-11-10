/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:23:42 by hyeokim           #+#    #+#             */
/*   Updated: 2020/11/11 00:57:39 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		set_texture(char *path, int idx, t_info *info)
{
	if (!(info->tex[idx]->img = mlx_xpm_file_to_image(info->mlx, path,
												&info->tex[idx]->width,
												&info->tex[idx]->height)))
		exit_program("No such file(.xpm) or directory");
	info->tex[idx]->data = mlx_get_data_addr(info->tex[idx]->img,
											&info->tex[idx]->bpp,
											&info->tex[idx]->size_l,
											&info->tex[idx]->endian);
}

static void		set_sprite(char *path, t_info *info)
{
	if (!(info->sprite->img = mlx_xpm_file_to_image(info->mlx, path,
											&info->sprite->width,
											&info->sprite->height)))
		exit_program("No such file(.xpm) or directory");
	info->sprite->data = mlx_get_data_addr(info->sprite->img,
											&info->sprite->bpp,
											&info->sprite->size_l,
											&info->sprite->endian);
}

void			convert_xpm_to_img(t_info *info)
{
	set_texture(info->config.texture[0], 0, info);
	set_texture(info->config.texture[1], 1, info);
	set_texture(info->config.texture[2], 2, info);
	set_texture(info->config.texture[3], 3, info);
	set_sprite(info->config.texture[4], info);
}
