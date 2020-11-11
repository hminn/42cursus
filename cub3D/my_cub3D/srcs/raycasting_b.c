/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 23:30:02 by hyeokim           #+#    #+#             */
/*   Updated: 2020/11/11 19:28:44 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		perp_and_height(t_ray *ray, t_player *player, t_info *info)
{
	if (ray->side == 0 || ray->side == 1)
		ray->perp_wall_dist =
						(ray->map.x - player->pos.x + (1 - ray->step.x) / 2)
						/ ray->ray_dir.x;
	else
		ray->perp_wall_dist =
						(ray->map.y - player->pos.y + (1 - ray->step.y) / 2)
						/ ray->ray_dir.y;
	ray->line_height = (int)(info->config.res[Y] / ray->perp_wall_dist);
	ray->draw_start = (-ray->line_height / 2 + ((info->config.res[Y] / 2)
		* info->config.player.cam_height));
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (ray->line_height / 2 + ((info->config.res[Y] / 2)
		* info->config.player.cam_height));
	if (ray->draw_end >= info->config.res[Y])
		ray->draw_end = info->config.res[Y] - 1;
}

static void	predict_wall_face(t_ray *ray)
{
	if (ray->side_dist.x < ray->side_dist.y)
	{
		ray->side_dist.x += ray->delta_dist.x;
		ray->map.x += ray->step.x;
		if (ray->step.x == 1)
			ray->side = 0;
		else if (ray->step.x == -1)
			ray->side = 1;
	}
	else
	{
		ray->side_dist.y += ray->delta_dist.y;
		ray->map.y += ray->step.y;
		if (ray->step.y == 1)
			ray->side = 2;
		else if (ray->step.y == -1)
			ray->side = 3;
	}
}

void		hit(t_ray *ray, t_info *info)
{
	while (ray->hit == 0)
	{
		predict_wall_face(ray);
		if (check_valid_chr(info->config.map[ray->map.y][ray->map.x]) == 1)
			ray->hit = 1;
		if (check_valid_chr(info->config.map[ray->map.y][ray->map.x]) == 2)
			is_sprite(ray, info);
	}
}
