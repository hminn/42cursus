/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 00:58:08 by hyeokim           #+#    #+#             */
/*   Updated: 2021/01/10 17:35:45 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		treat_ctrld(int ctrld, char **line)
{
	char	*temp;
	char	*buf;

	buf = "";
	while (!(get_next_line(0, line)))
	{
		temp = ft_strjoin(buf, *line);
		*buf ? free(buf) : 0;
		buf = temp;
		if (!(**line) && !ctrld)
		{
			ft_putstr_fd("exit\n", 1);
			free(buf);
			exit(EXIT_SUCCESS);
		}
		ft_putstr_fd("  \b\b", 1);
		ctrld = 1;
		free(*line);
	}
	if (ctrld)
	{
		free(*line);
		*line = ft_strdup(buf);
	}
	*buf ? free(buf) : 0;
}

int				preprocess_input(char **line)
{
	int		ctrld;
	char	*temp;

	ctrld = 0;
	treat_ctrld(ctrld, line);
	if (**line == '\n')
	{
		free(*line);
		return (0);
	}
	if (*line != NULL)
	{
		temp = ft_strtrim(*line, " ");
		if (*line)
		{
			free(*line);
			*line = NULL;
		}
		*line = temp;
	}
	return (1);
}

void			print_front(char *tmp, char *set, char *pwd, char*user)
{
	ft_putstr_fd(user, 1);
	ft_putstr_fd(" \033[44m\033[30m ", 1);
	if (ft_strncmp(tmp, set, ft_strlen(tmp)) != 0)
		ft_putstr_fd(pwd, 1);
	else if (ft_strncmp(tmp, "/", ft_strlen(tmp)) == 0)
		ft_putstr_fd("/", 1);
	else if (ft_strncmp(tmp, "/Users/", ft_strlen(tmp)) == 0)
		ft_putstr_fd("/Users", 1);
	else if (ft_strncmp(tmp, set, ft_strlen(tmp)) == 0)
		ft_putstr_fd("~", 1);
	ft_putstr_fd(" \033[0m $ ", 1);
}

void			print_prompt(char *user)
{
	char	*pwd;
	char	*tmp[2];
	char	*set;

	tmp[0] = getcwd(0, 1024);
	set = !(ft_strncmp(tmp[0], "/Users/", 7)) ? ft_strjoin("/Users/", user)
		: ft_strdup("/");
	tmp[1] = ft_strtrim(tmp[0], set);
	pwd = !(ft_strncmp(tmp[0], "/Users/", 7)) ? ft_strjoin("~/", tmp[1])
		: ft_strjoin("/", tmp[1]);
	free(tmp[1]);
	print_front(tmp[0], set, pwd, user);
	free(set);
	free(tmp[0]);
	free(pwd);
}

// void			print_header(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("ascii_art", O_RDONLY);
// 	while (get_next_line(fd, &line))
// 	{
// 		ft_putstr_fd("\033[36m", 1);
// 		ft_putendl_fd(line, STDOUT_FILENO);
// 		free(line);
// 	}
// 	close(fd);
// 	free(line);
// 	ft_putendl_fd("\033[0m", 1);
// }
