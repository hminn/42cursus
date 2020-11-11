/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 15:34:40 by jwon              #+#    #+#             */
/*   Updated: 2020/11/11 16:47:50 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		set_texture(char *path, int idx, t_game *game)
{
	if (!(game->tex[idx]->img = mlx_xpm_file_to_image(game->mlx, path,
												&game->tex[idx]->width,
												&game->tex[idx]->height)))
		exit_program("No such file(.xpm) or directory");
	game->tex[idx]->data = mlx_get_data_addr(game->tex[idx]->img,
											&game->tex[idx]->bpp,
											&game->tex[idx]->size_l,
											&game->tex[idx]->endian);
}

static void		set_sprite(char *path, t_game *game)
{
	if (!(game->sprite->img = mlx_xpm_file_to_image(game->mlx, path,
											&game->sprite->width,
											&game->sprite->height)))
		exit_program("No such file(.xpm) or directory");
	game->sprite->data = mlx_get_data_addr(game->sprite->img,
											&game->sprite->bpp,
											&game->sprite->size_l,
											&game->sprite->endian);
}

void			convert_xpm_to_img(t_game *game)
{
	set_texture(game->config.texture[TEX_NO], TEX_NO, game);
	set_texture(game->config.texture[TEX_SO], TEX_SO, game);
	set_texture(game->config.texture[TEX_WE], TEX_WE, game);
	set_texture(game->config.texture[TEX_EA], TEX_EA, game);
	set_sprite(game->config.texture[TEX_S], game);
}
