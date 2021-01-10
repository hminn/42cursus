/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:32:17 by hyeokim           #+#    #+#             */
/*   Updated: 2021/01/10 21:42:02 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			check_quote(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (1);
	}
	return (0);
}

int			check_env(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '$')
			return (1);
	}
	return (0);
}

int			check_pipe(char *str)
{
	int		num;

	num = 0;
	while (*str)
	{
		if (*str == '|')
			num++;
		str++;
	}
	return (num);
}

int			check_redirect_type(char *line, int i)
{
	if (line[i] == '>' && line[i + 1] == '>')
		return (DREDIR);
	else if (line[i] == '>' && line[i - 1] != '>' && line[i + 1] != '>')
		return (LREDIR);
	return (RREDIR);
}

int			check_redirect(char *line)
{
	int		num;

	num = 0;
	while (*line)
	{
		if (ft_strchr("<>", *line))
			num++;
		line++;
	}
	return (num);
}
