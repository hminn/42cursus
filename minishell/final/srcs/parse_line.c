/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:23:17 by hyeokim           #+#    #+#             */
/*   Updated: 2021/01/10 21:43:25 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			check_error(char *line)
{
	int		i;
	char	*cmd;

	i = -1;
	cmd = ft_strtrim(line, " ");
	while (cmd[++i])
	{
		if (cmd[0] == ';' || (cmd[i] == ';' && cmd[i + 1] == ';'))
		{
			free(cmd);
			free(line);
			ft_putendl_fd("syntax error near unexpected token `;'", 2);
			return (1);
		}
	}
	free(cmd);
	return (0);
}

char		**parse_line(char *line)
{
	char	**cmds;
	char	*cmd;
	int		i;

	if (check_error(line))
		return (NULL);
	cmds = ft_split(line, ';');
	free(line);
	i = -1;
	while (cmds[++i])
	{
		cmd = ft_strtrim(cmds[i], " ");
		free(cmds[i]);
		if (!cmd || !(*cmd))
		{
			free(cmds);
			ft_putendl_fd("syntax error near unexpected token `;'", 2);
			return (NULL);
		}
		cmds[i] = cmd;
	}
	return (cmds);
}
