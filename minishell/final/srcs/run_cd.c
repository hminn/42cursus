/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:28:02 by hyeokim           #+#    #+#             */
/*   Updated: 2021/01/10 16:21:24 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_path(char *argv, char *path)
{
	if (path)
	{
		if (chdir(path) == -1)
			ft_putendl_fd(strerror(errno), 2);
	}
	else
		if (chdir(argv) == -1)
			ft_putendl_fd(strerror(errno), 2);
}

void	run_cd(char **argv, t_list *envs)
{
	char	*path;

	path = 0;
	if (argv[1] == NULL ||!ft_strncmp(argv[1], "~", ft_strlen(argv[1])))
	{
		path = get_value("HOME", envs);
	}
	else if (*argv[1] == '$')
		path = get_value(argv[1] + 1, envs);
	check_path(argv[1], path);
	return ;
}
