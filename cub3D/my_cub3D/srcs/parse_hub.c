/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 12:14:30 by hyeokim           #+#    #+#             */
/*   Updated: 2020/11/11 19:28:14 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		init_config(t_config *config)
{
	int			idx;

	idx = 0;
	while (idx < (int)(sizeof(config->id) / sizeof(int)))
		config->id[idx++] = 0;
	idx = 0;
	while (idx < (int)(sizeof(config->color) / sizeof(int)))
		config->color[idx++] = 0;
	idx = 0;
	while (config->texture[idx])
		config->texture[idx++] = NULL;
	config->res[X] = 0;
	config->res[Y] = 0;
	config->row = 0;
	config->col = 0;
	config->flag = 0;
	config->player.cnt = 0;
	config->player.id = 0;
	config->player.pos.x = 0;
	config->player.pos.y = 0;
}

static int		parse_using_gnl(int fd, int ret, char *line, t_config *config)
{
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (line[0] == 'R' && line[1] == ' ')
			parse_resolution(line + 2, config);
		else if ((line[0] == 'N' && line[1] == 'O' && line[2] == ' ') ||
			(line[0] == 'S' && line[1] == 'O' && line[2] == ' ') ||
			(line[0] == 'W' && line[1] == 'E' && line[2] == ' ') ||
			(line[0] == 'E' && line[1] == 'A' && line[2] == ' ') ||
			(line[0] == 'S' && line[1] == ' '))
			parse_texture(line + 2, check_texture_id(line, config), config);
		else if ((line[0] == 'F' && line[1] == ' ') ||
			(line[0] == 'C' && line[1] == ' '))
			parse_color(line + 2, check_color_id(line, config), config);
		else if (ft_isspace_str(line) && config->id[ID_MAP] == 0)
		{
			free(line);
			continue ;
		}
		else
			parse_map(ret, line, config);
		free(line);
	}
	parse_map(ret, line, config);
	free(line);
	return (ret);
}

static void		check_arguments(int argc, char *argv[], t_config *config)
{
	if (argc == 1)
		exit_program("Mapfile path required for first argument");
	else if (argc == 2 || argc == 3)
	{
		if (check_filename_ext(argv[1], "cub") == 0)
			exit_program("Map filename extension is invalid");
		if (argc == 3)
		{
			if (ft_strncmp(argv[2], "--save", 8) == 0)
				config->flag = 1;
			else
				exit_program("Invalid arguments");
		}
	}
	else
		exit_program("Too many arguments");
}

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
	info->config.map_name = ft_strdup(argv[1]);
	ret = parse_using_gnl(fd, ret, line, &info->config);
	close(fd);
	check_identifiers_exist(ret, &info->config);
}
