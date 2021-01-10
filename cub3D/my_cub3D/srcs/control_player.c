/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:23:27 by hyeokim           #+#    #+#             */
/*   Updated: 2020/11/11 22:11:58 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		move_go(t_info *info)
{
	if ((check_valid_chr(info->config.map[(int)info->config.player.pos.y]
		[(int)(info->config.player.pos.x + info->config.player.dir.x
		* info->speed_mov)]) == 0) ||
		(check_valid_chr(info->config.map[(int)info->config.player.pos.y]
		[(int)(info->config.player.pos.x + info->config.player.dir.x
		* info->speed_mov)]) == 3))
		info->config.player.pos.x += info->config.player.dir.x
		* info->speed_mov;
	if ((check_valid_chr(info->config.map[(int)(info->config.player.pos.y
		+ info->config.player.dir.y * info->speed_mov)]
		[(int)info->config.player.pos.x]) == 0) ||
		(check_valid_chr(info->config.map[(int)(info->config.player.pos.y
		+ info->config.player.dir.y * info->speed_mov)]
		[(int)info->config.player.pos.x]) == 3))
		info->config.player.pos.y += info->config.player.dir.y
		* info->speed_mov;
}

void		move_back(t_info *info)
{
	if ((check_valid_chr(info->config.map[(int)info->config.player.pos.y]
		[(int)(info->config.player.pos.x - info->config.player.dir.x
		* info->speed_mov)]) == 0) ||
		(check_valid_chr(info->config.map[(int)info->config.player.pos.y]
		[(int)(info->config.player.pos.x - info->config.player.dir.x
		* info->speed_mov)]) == 3))
		info->config.player.pos.x -= info->config.player.dir.x
		* info->speed_mov;
	if ((check_valid_chr(info->config.map[(int)(info->config.player.pos.y
		- info->config.player.dir.y * info->speed_mov)]
		[(int)info->config.player.pos.x]) == 0) ||
		(check_valid_chr(info->config.map[(int)(info->config.player.pos.y
		- info->config.player.dir.y * info->speed_mov)]
		[(int)info->config.player.pos.x]) == 3))
		info->config.player.pos.y -= info->config.player.dir.y
		* info->speed_mov;
}

void		move_left(t_info *info)
{
	if ((check_valid_chr(info->config.map[(int)info->config.player.pos.y]
		[(int)(info->config.player.pos.x - info->config.player.plane.x
		* info->speed_mov)]) == 0) ||
		(check_valid_chr(info->config.map[(int)info->config.player.pos.y]
		[(int)(info->config.player.pos.x - info->config.player.plane.x
		* info->speed_mov)]) == 3))
		info->config.player.pos.x -= info->config.player.plane.x
		* info->speed_mov;
	if ((check_valid_chr(info->config.map[(int)(info->config.player.pos.y
		- info->config.player.plane.y * info->speed_mov)]
		[(int)info->config.player.pos.x]) == 0) ||
		(check_valid_chr(info->config.map[(int)(info->config.player.pos.y
		- info->config.player.plane.y * info->speed_mov)]
		[(int)info->config.player.pos.x]) == 3))
		info->config.player.pos.y -= info->config.player.plane.y
		* info->speed_mov;
}

void		move_right(t_info *info)
{
	if ((check_valid_chr(info->config.map[(int)info->config.player.pos.y]
		[(int)(info->config.player.pos.x + info->config.player.plane.x
		* info->speed_mov)]) == 0) ||
		(check_valid_chr(info->config.map[(int)info->config.player.pos.y]
		[(int)(info->config.player.pos.x + info->config.player.plane.x
		* info->speed_mov)]) == 3))
		info->config.player.pos.x += info->config.player.plane.x
		* info->speed_mov;
	if ((check_valid_chr(info->config.map[(int)(info->config.player.pos.y
		+ info->config.player.plane.y * info->speed_mov)]
		[(int)info->config.player.pos.x]) == 0) ||
		(check_valid_chr(info->config.map[(int)(info->config.player.pos.y
		+ info->config.player.plane.y * info->speed_mov)]
		[(int)info->config.player.pos.x]) == 3))
		info->config.player.pos.y += info->config.player.plane.y
		* info->speed_mov;
}
