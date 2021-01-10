/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:29:14 by hyeokim           #+#    #+#             */
/*   Updated: 2021/01/10 21:44:54 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		print_exit_status(void)
{
	ft_putstr_fd(ft_itoa(g_exit_value), 1);
	ft_putendl_fd(": command not found", 1);
	return (1);
}

static int		run_dollar(char *line)
{
	if (line[0] == '$' && line[1] == '?')
	{
		print_exit_status();
		return (1);
	}
	return (0);
}

int				run_base(char *line, t_list *envs)
{
	char **argv;

	argv = get_argv(line, envs);
	if (!ft_strncmp(argv[0], "cd", ft_strlen(argv[0])))
		run_cd(argv, envs);
	else if (!ft_strncmp(argv[0], "echo", ft_strlen(argv[0])))
		run_echo(argv);
	else if (!ft_strncmp(argv[0], "pwd", ft_strlen(argv[0])))
		run_pwd();
	else if (!ft_strncmp(argv[0], "env", ft_strlen(argv[0])))
		run_env(argv, envs);
	else if (!ft_strncmp(argv[0], "export", ft_strlen(argv[0])))
		run_export(argv, envs);
	else if (!ft_strncmp(argv[0], "unset", ft_strlen(argv[0])))
		run_unset(argv, envs);
	else if (!ft_strncmp(argv[0], "exit", ft_strlen(argv[0])))
		run_exit(argv);
	else
	{
		free_double_arr(argv);
		return (0);
	}
	free_double_arr(argv);
	g_exit_value = 0;
	return (1);
}

void			command_unregistered(char *line, t_list *envs)
{
	int		status;
	char	*path;
	char	**argv;
	pid_t	child;

	argv = get_argv(line, envs);
	path = find_path(argv[0], envs);
	if (!path)
	{
		ft_puterror_fd(argv[0], ": command not found", 2);
		return ;
	}
	child = fork();
	if (child == 0)
	{
		if (execve(path, argv, g_envp) == -1)
			exit(ft_puterror_fd(argv[0], ": command not found", 2));
		exit(EXIT_SUCCESS);
	}
	wait(&status);
	free(path);
	free_double_arr(argv);
	g_exit_value = status / 256;
}

void			run_cmds(char *line, t_list *envs)
{
	if (check_pipe(line))
		run_pipe(line, envs);
	else if (check_redirect(line))
		run_redirect(line, envs);
	else if (!run_dollar(line) && !run_base(line, envs))
		command_unregistered(line, envs);
}
