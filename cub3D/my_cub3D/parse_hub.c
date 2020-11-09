/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 12:14:30 by hyeokim           #+#    #+#             */
/*   Updated: 2020/11/09 20:35:41 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			parse_hub(int argc, char *argv[], t_info *info)
{
	int			fd;
	int			ret;
	char		*line;

	ret = 0;
	line = NULL;
	init_config(&info->config);
	check_arguments(argc, argv, &info->config);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		exit_program("No such file(.cub) or directory");
	game->config.map_name = ft_strdup(argv[1]);
	ret = parse_using_gnl(fd, ret, line, &info->config);
	close(fd);
}
