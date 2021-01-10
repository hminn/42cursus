/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 23:22:10 by hyeokim           #+#    #+#             */
/*   Updated: 2020/11/11 19:31:09 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		key_released(int key, void *parameter)
{
	t_info	*info;

	info = (t_info *)parameter;
	(key == KEY_W && info->key->go == 1) ? info->key->go = 0 : 0;
	(key == KEY_S && info->key->back == 1) ? info->key->back = 0 : 0;
	(key == KEY_A && info->key->left == 1) ? info->key->left = 0 : 0;
	(key == KEY_D && info->key->right == 1) ? info->key->right = 0 : 0;
	(key == KEY_UP && info->key->cam_up == 1) ? info->key->cam_up = 0 : 0;
	(key == KEY_DOWN && info->key->cam_down == 1) ?
											info->key->cam_down = 0 : 0;
	(key == KEY_LEFT && info->key->rotate_left == 1) ?
											info->key->rotate_left = 0 : 0;
	(key == KEY_RIGHT && info->key->rotate_right == 1) ?
											info->key->rotate_right = 0 : 0;
	return (1);
}

int		key_pressed(int key, void *parameter)
{
	t_info	*info;

	info = (t_info *)parameter;
	(key == KEY_ESC) ? exit(EXIT_SUCCESS) : 0;
	(key == KEY_W && info->key->go == 0) ? info->key->go = 1 : 0;
	(key == KEY_S && info->key->back == 0) ? info->key->back = 1 : 0;
	(key == KEY_A && info->key->left == 0) ? info->key->left = 1 : 0;
	(key == KEY_D && info->key->right == 0) ? info->key->right = 1 : 0;
	(key == KEY_UP && info->key->cam_up == 0) ? info->key->cam_up = 1 : 0;
	(key == KEY_DOWN && info->key->cam_down == 0) ?
											info->key->cam_down = 1 : 0;
	(key == KEY_LEFT && info->key->rotate_left == 0) ?
											info->key->rotate_left = 1 : 0;
	(key == KEY_RIGHT && info->key->rotate_right == 0) ?
											info->key->rotate_right = 1 : 0;
	return (1);
}

int		key_manager(t_info *info)
{
	(info->key->go == 1) ? move_go(info) : 0;
	(info->key->back == 1) ? move_back(info) : 0;
	(info->key->left == 1) ? move_left(info) : 0;
	(info->key->right == 1) ? move_right(info) : 0;
	(info->key->cam_up == 1) ? camera_up(info) : 0;
	(info->key->cam_down == 1) ? camera_down(info) : 0;
	(info->key->rotate_left == 1) ? rotate_left(info) : 0;
	(info->key->rotate_right == 1) ? rotate_right(info) : 0;
	return (1);
}

int		exit_window(void *parameter)
{
	t_info *info;

	info = (t_info *)parameter;
	exit_program("The game was forced to shutdown");
	return (1);
}
