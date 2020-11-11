/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 03:21:55 by hyeokim           #+#    #+#             */
/*   Updated: 2020/11/11 17:09:16 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			calcul_values(t_draw_sprite *ds, t_info *info)
{
	ds->inv_det = 1.0 / (info->config.player.plane.x * info->config.player.dir.y
		- info->config.player.dir.x * info->config.player.plane.y);
	ds->transform.x = ds->inv_det * (info->config.player.dir.y * ds->sprite.x
		- info->config.player.dir.x * ds->sprite.y);
	ds->transform.y = ds->inv_det * (-info->config.player.plane.y * ds->sprite.x
		+ info->config.player.plane.x * ds->sprite.y);
	ds->sprite_screen_x = (int)((info->config.res[X] / 2) * (1 + ds->transform.x
		/ ds->transform.y));
	ds->sprite_height = abs((int)(info->config.res[Y] / ds->transform.y));
	ds->draw_start.y = -ds->sprite_height / 2 + ((info->config.res[Y] / 2)
		* info->config.player.cam_height);
	if (ds->draw_start.y < 0)
		ds->draw_start.y = 0;
	ds->draw_end.y = ds->sprite_height / 2 + ((info->config.res[Y] / 2)
		* info->config.player.cam_height);
	if (ds->draw_end.y >= info->config.res[Y])
		ds->draw_end.y = info->config.res[Y] - 1;
	ds->sprite_width = abs((int)(info->config.res[Y] / ds->transform.y));
	ds->draw_start.x = -ds->sprite_width / 2 + ds->sprite_screen_x;
	if (ds->draw_start.x < 0)
		ds->draw_start.x = 0;
	ds->draw_end.x = ds->sprite_width / 2 + ds->sprite_screen_x;
	if (ds->draw_end.x >= info->config.res[X])
		ds->draw_end.x = info->config.res[X] - 1;
	ds->stripe = ds->draw_start.x;
}

static void			pix_on_sprite_image(t_draw_sprite *ds, t_info *info)
{
	ds->d = ds->y * info->sprite->size_l - (info->config.res[Y]
		* info->config.player.cam_height)
		* (info->sprite->size_l / 2) + ds->sprite_height
		* info->sprite->size_l / 2;
	ds->tex.y = ((ds->d * info->sprite->height) / ds->sprite_height)
		/ info->sprite->size_l;
	ds->totcolor = info->sprite->data[ds->tex.y
		* info->sprite->size_l + ds->tex.x
		* info->sprite->bpp / 8]
		+ info->sprite->data[ds->tex.y
		* info->sprite->size_l + ds->tex.x
		* info->sprite->bpp / 8 + 1]
		+ info->sprite->data[ds->tex.y
		* info->sprite->size_l + ds->tex.x
		* info->sprite->bpp / 8 + 2];
}

static void			is_black(t_draw_sprite *ds, t_info *info)
{
	info->img->data[ds->y * info->img->size_l
		+ ds->stripe * info->img->bpp / 8] =
		info->sprite->data[ds->tex.y
		* info->sprite->size_l + ds->tex.x
		* info->sprite->bpp / 8];
	info->img->data[ds->y * info->img->size_l
		+ ds->stripe * info->img->bpp / 8 + 1] =
		info->sprite->data[ds->tex.y
		* info->sprite->size_l + ds->tex.x
		* info->sprite->bpp / 8 + 1];
	info->img->data[ds->y * info->img->size_l
		+ ds->stripe * info->img->bpp / 8 + 2] =
		info->sprite->data[ds->tex.y
		* info->sprite->size_l + ds->tex.x
		* info->sprite->bpp / 8 + 2];
}

static void			make_sprite(t_draw_sprite *ds, t_info *info, t_ray *ray)
{
	ds->sprite.x = ds->sprites[ds->i].coord.x -
					(info->config.player.pos.x - 0.5);
	ds->sprite.y = ds->sprites[ds->i].coord.y -
					(info->config.player.pos.y - 0.5);
	calcul_values(ds, info);
	while (ds->stripe < ds->draw_end.x)
	{
		ds->tex.x = (int)(info->sprite->size_l * (ds->stripe
		- (-ds->sprite_width / 2 + ds->sprite_screen_x))
			* info->sprite->width / ds->sprite_width) / info->sprite->size_l;
		if (ds->transform.y > 0 && ds->stripe > 0 && ds->stripe
			< info->config.res[X] && ds->transform.y
			< ray->z_buffer[ds->stripe])
		{
			ds->y = ds->draw_start.y;
			while (ds->y < ds->draw_end.y)
			{
				pix_on_sprite_image(ds, info);
				if (ds->totcolor != 0)
					is_black(ds, info);
				ds->y++;
			}
		}
		ds->stripe++;
	}
}

int					draw_sprite(t_ray *ray, t_info *info)
{
	t_draw_sprite *ds;

	if (!(ds = malloc(sizeof(t_draw_sprite))))
		exit_program("Memory allocation failed");
	ft_bzero(ds, sizeof(t_draw_sprite));
	ds->i = 0;
	ds->sprites = list_to_tab(info);
	sort_sprite(info, ds->sprites,
		ft_lstsize((t_list *)info->sprites_on_screen));
	while (ds->i < ft_lstsize((t_list *)info->sprites_on_screen))
	{
		make_sprite(ds, info, ray);
		ds->i++;
	}
	free(ds);
	free(ds->sprites);
	return (1);
}
