/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:27:32 by hyeokim           #+#    #+#             */
/*   Updated: 2021/01/10 16:14:20 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	close_fd(int fd[2])
{
	close(fd[0]);
	close(fd[1]);
}

void	parse_pipe(char **line, t_pipe *p, t_list *envs)
{
	int		i;
	char	*temp;
	char	*temp2;

	i = -1;
	while ((*line)[++i])
	{
		if ((*line)[i] == '|')
		{
			temp = ft_substr(*line, 0, i);
			p->line = ft_strtrim(temp, " ");
			free(temp);
			temp = ft_substr(*line, i + 1, ft_strlen(*line) - i);
			temp2 = ft_strtrim(temp, " ");
			free(temp);
			*line = temp2;
			p->argv = get_argv(p->line, envs);
			return ;
		}
	}
}

void	prev_pipe(int child, int fd[2], t_list *envs, t_pipe p)
{
	if (!child)
	{
		dup2(fd[1], STDOUT_FILENO);
		close_fd(fd);
		run_cmds(p.line, envs);
		exit(EXIT_SUCCESS);
	}
}

void	next_pipe(int child, int fd[2], t_list *envs, char *line)
{
	if (!child)
	{
		dup2(fd[0], STDIN_FILENO);
		close_fd(fd);
		run_cmds(line, envs);
		exit(EXIT_SUCCESS);
	}
}

void	run_pipe(char *line, t_list *envs)
{
	int		fd[2];
	int		child[2];
	int		status[2];
	t_pipe	p;

	parse_pipe(&line, &p, envs);
	pipe(fd);
	child[0] = fork();
	prev_pipe(child[0], fd, envs, p);
	free_pipe(&p);
	child[1] = fork();
	next_pipe(child[1], fd, envs, line);
	free(line);
	close_fd(fd);
	waitpid(child[1], &status[1], 0);
	waitpid(child[0], &status[0], WNOHANG);
}
