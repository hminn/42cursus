/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:16:33 by hyeokim           #+#    #+#             */
/*   Updated: 2020/11/11 19:27:02 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			rotate_left(t_info *info)
{
	double		pre_dir_x;
	double		pre_plane_x;

	pre_dir_x = info->config.player.dir.x;
	pre_plane_x = info->config.player.plane.x;
	info->config.player.dir.x =
				info->config.player.dir.x * cos(-info->speed_rot)
				- info->config.player.dir.y * sin(-info->speed_rot);
	info->config.player.dir.y =
				pre_dir_x * sin(-info->speed_rot)
				+ info->config.player.dir.y * cos(-info->speed_rot);
	info->config.player.plane.x =
				info->config.player.plane.x * cos(-info->speed_rot)
				- info->config.player.plane.y * sin(-info->speed_rot);
	info->config.player.plane.y =
				pre_plane_x * sin(-info->speed_rot)
				+ info->config.player.plane.y * cos(-info->speed_rot);
}

void			rotate_right(t_info *info)
{
	double		pre_dir_x;
	double		pre_plane_x;

	pre_dir_x = info->config.player.dir.x;
	pre_plane_x = info->config.player.plane.x;
	info->config.player.dir.x =
				info->config.player.dir.x * cos(info->speed_rot)
				- info->config.player.dir.y * sin(info->speed_rot);
	info->config.player.dir.y =
				pre_dir_x * sin(info->speed_rot)
				+ info->config.player.dir.y * cos(info->speed_rot);
	info->config.player.plane.x =
				info->config.player.plane.x * cos(info->speed_rot)
				- info->config.player.plane.y * sin(info->speed_rot);
	info->config.player.plane.y =
				pre_plane_x * sin(info->speed_rot)
				+ info->config.player.plane.y * cos(info->speed_rot);
}

void			camera_up(t_info *info)
{
	if (info->config.player.cam_height < 1.8)
		info->config.player.cam_height += 0.1;
}

void			camera_down(t_info *info)
{
	if (info->config.player.cam_height > 0.2)
		info->config.player.cam_height -= 0.1;
}
