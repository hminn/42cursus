/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:13:27 by hyeokim           #+#    #+#             */
/*   Updated: 2020/11/11 01:29:40 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		next_step(t_ray *ray, t_player *player)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (player->pos.x - ray->map.x)
						* ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1.0 - player->pos.x)
						* ray->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (player->pos.y - ray->map.y)
						* ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1.0 - player->pos.y)
						* ray->delta_dist.y;
	}
}

static void		init_ray(t_ray *ray, t_player *player, t_info *info)
{
	ray->camera_x = (2 * ray->pix) / (double)info->config.res[X] - 1;
	ray->ray_dir.x = player->dir.x + player->plane.x * ray->camera_x;
	ray->ray_dir.y = player->dir.y + player->plane.y * ray->camera_x;
	ray->map.x = (int)player->pos.x;
	ray->map.y = (int)player->pos.y;
	ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
	ray->hit = 0;
}

static void		do_raycasting(t_ray *ray, t_info *info)
{
	init_ray(ray, &info->config.player, info);
	next_step(ray, &info->config.player);
	hit(ray, info);
	perp_and_height(ray, &info->config.player, info);
	ray->z_buffer[ray->pix] = ray->perp_wall_dist;
	texturisation(ray, info);
	ray->pix++;
}

int				raycasting(t_info *info)
{
	t_ray		*ray;

	if (!(ray = malloc(sizeof(t_ray))))
		exit_program("Memory allocation failed");
	ft_bzero(ray, sizeof(t_ray));
	if (!(ray->z_buffer = malloc(sizeof(double) * info->config.res[X])))
		exit_program("Memory allocation failed");
	ft_bzero(ray->z_buffer, sizeof(double) * info->config.res[X]);
	while (ray->pix < info->config.res[X])
		do_raycasting(ray, info);
	if (!draw_sprite(ray, info))
		return (-1);
	if (info->config.flag[SAVE])
		create_screenshot(info->img, "screenshot");
	mlx_put_image_to_window(info->mlx, info->win, info->img->img, 0, 0);
	free(ray->z_buffer);
	free(ray);
	return (1);
}
