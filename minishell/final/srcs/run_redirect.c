/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:35:06 by hyeokim           #+#    #+#             */
/*   Updated: 2021/01/10 18:08:35 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			parse_redirect(char *line, t_redir *redir)
{
	int		i;
	int		j;
	int		start;

	i = -1;
	j = 0;
	start = 0;
	while (line[++i])
	{
		if (ft_strchr("<>", line[i]))
		{
			if (j > 0 && ((redir->types[0] == RREDIR && line[i] != '<') ||
				(redir->types[0] != RREDIR && line[i] == '<')))
				return (0);
			redir->argv[j] = preprocess_line(line, start, i - start, " ");
			if (j == 0)
				redir->cmds = ft_split(redir->argv[j], ' ');
			redir->types[j] = check_redirect_type(line, i);
			redir->types[j++] == DREDIR ? i++ : 0;
			start = i + 1;
		}
	}
	redir->argv[j] = preprocess_line(line, start, i - start, " ");
	return (return_redirect(redir, j));
}

void		init_redirect(char *line, t_redir *redir)
{
	int		i;

	i = 0;
	while (*line)
	{
		if (ft_strchr("<>", *line))
			i++;
		line++;
	}
	redir->argc = i + 1;
	redir->argv = (char **)malloc(sizeof(char *) * (redir->argc + 1));
	redir->types = (char *)malloc(sizeof(char) * (redir->argc + 1));
	redir->cmds = NULL;
}

void		open_files(t_redir *r)
{
	int	i;
	int	fd;

	i = 1;
	while (i < r->argc - 1)
	{
		if (i > 1)
			close(fd);
		if (r->types[i - 1] == LREDIR)
			fd = open(r->argv[i], O_WRONLY | O_CREAT | O_TRUNC, 0744);
		else if (r->types[i - 1] == DREDIR)
			fd = open(r->argv[i], O_WRONLY | O_CREAT | O_APPEND, 0744);
		else
			fd = open(r->argv[i], O_RDONLY, 0644);
		i++;
	}
	close(fd);
}

void		run_redirect(char *line, t_list *envs)
{
	t_redir		redir;
	int			result;
	int			i;

	i = -1;
	init_redirect(line, &redir);
	result = parse_redirect(line, &redir);
	if (result <= 0)
	{
		if (result < 0)
			ft_putendl_fd("syntax error near unexpected token `newline'", 1);
		return ;
	}
	while (redir.cmds[++i])
	{
		if (check_quote(redir.cmds[i]))
			redir.cmds[i] = change_argv(redir.cmds[i], envs);
	}
	open_files(&redir);
	cmd_redirect(&redir, envs);
}