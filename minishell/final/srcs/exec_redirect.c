/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 16:06:26 by hyeokim           #+#    #+#             */
/*   Updated: 2021/01/10 18:10:41 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*preprocess_line(char *line, int start, int num, char *charset)
{
	char	*sub_result;
	char	*result;

	sub_result = ft_substr(line, start, num);
	result = ft_strtrim(sub_result, charset);
	free(sub_result);
	return (result);
}

static int		exec_lredir(t_redir *r, t_list *envs)
{
	int		fd;
	char	*path;

	fd = open(r->argv[r->argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0744);
	if (fd < 0)
	{
		ft_puterror_fd(r->argv[r->argc - 1], ": No such file or directory", 2);
		return (EXIT_FAILURE);
	}
	if (!(path = find_path(r->cmds[0], envs)))
		return (ft_puterror_fd(r->cmds[0], ": command not found", 2));
	dup2(fd, STDOUT_FILENO);
	close(fd);
	if (!run_base(r->argv[r->argc - 1], envs) &&
		(execve(path, r->cmds, g_envp) == -1))
		return (ft_puterror_fd(r->cmds[0], ": command not found", 2));
	free(path);
	free_double_arr(r->cmds);
	return (EXIT_SUCCESS);
}

static int		exec_dredir(t_redir *r, t_list *envs)
{
	int		fd;
	char	*path;

	fd = open(r->argv[r->argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0744);
	if (fd < 0)
	{
		ft_puterror_fd(r->argv[r->argc - 1], ": No such file or directory", 2);
		return (EXIT_FAILURE);
	}
	if (!(path = find_path(r->cmds[0], envs)))
		return (ft_puterror_fd(r->cmds[0], ": command not found", 2));
	dup2(fd, STDOUT_FILENO);
	close(fd);
	if (!run_base(r->argv[r->argc - 1], envs) &&
		(execve(path, r->cmds, g_envp) == -1))
		return (ft_puterror_fd(r->cmds[0], ": command not found", 2));
	free(path);
	free_double_arr(r->cmds);
	return (EXIT_SUCCESS);
}

static int		exec_rredir(t_redir *r, t_list *envs)
{
	int		fd;
	char	*path;

	fd = open(r->argv[r->argc - 1], O_RDONLY, 0644);
	if (fd < 0)
	{
		ft_puterror_fd(r->argv[r->argc - 1], ": No such file or directory", 2);
		return (EXIT_FAILURE);
	}
	if (!(path = find_path(r->cmds[0], envs)))
		return (ft_puterror_fd(r->cmds[0], ": command not found", 2));
	dup2(fd, STDIN_FILENO);
	close(fd);
	if (!run_base(r->argv[r->argc - 1], envs) &&
		(execve(path, r->cmds, g_envp) == -1))
		return (ft_puterror_fd(r->cmds[0], ": command not found", 2));
	free(path);
	free_double_arr(r->cmds);
	return (EXIT_SUCCESS);
}

void			cmd_redirect(t_redir *r, t_list *envs)
{
	int		ret;
	int		status;
	pid_t	child;

	child = fork();
	if (child == 0)
	{
		if (r->types[r->argc - 2] == LREDIR)
			ret = exec_lredir(r, envs);
		else if (r->types[r->argc - 2] == DREDIR)
			ret = exec_dredir(r, envs);
		else
			ret = exec_rredir(r, envs);
		exit(ret);
	}
	wait(&status);
	g_exit_value = status / 256;
	free(r->types);
	free_double_arr(r->argv);
	free_double_arr(r->cmds);
}