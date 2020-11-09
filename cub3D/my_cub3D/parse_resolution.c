/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:32:37 by hyeokim           #+#    #+#             */
/*   Updated: 2020/11/10 01:56:42 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		check_resolution_format(char *line)
{
	int			idx;
	int			space_cnt;

	idx = 0;
	space_cnt = 0;
	while (line[idx])
	{
		if (ft_isdigit(line[idx]) || line[idx] == ' ')
		{
			if (line[idx] == ' ')
				space_cnt++;
		}
		else
			break ;
		idx++;
	}
	if (space_cnt != 1 || idx != ((int)ft_strlen(line)))
		exit_program("Resolution format is invalid");
}

static void		adjust_resolution(t_config *config)
{
	if (config->res[X] > 1400 || config->res[Y] > 1050)
	{
		config->res[X] = 1400;
		config->res[Y] = 1050;
	}
	else
	{
		config->res[X] = 1280;
		config->res[Y] = 960;
	}
}

void			parse_resolution(char *line, t_config *config)
{
	char		**buf;
	char		*tmp;
	int			idx;

	if (ft_isspace_str(line))
		exit_program("Resolution value is empty");
	tmp = NULL;
	tmp = ft_strtrim(line, " ");
	check_resolution_format(tmp);
	buf = ft_split(tmp, ' ');
	free(tmp);
	config->res[X] = ft_atoi(buf[0]);
	config->res[Y] = ft_atoi(buf[1]);
	idx = -1;
	while (++idx < 2)
		free(buf[idx]);
	free(buf);
	adjust_resolution(config);
	config->id[ID_R]++;
}
