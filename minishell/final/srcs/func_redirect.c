/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:59:30 by hyeokim           #+#    #+#             */
/*   Updated: 2021/01/10 16:03:01 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			redir_error_check(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr(" \n", str[i]))
			return (0);
		i++;
	}
	return (1);
}

int			return_redirect(t_redir *redir, int j)
{
	if (redir_error_check(redir->argv[j]))
		return (-1);
	redir->types[j++] = 0;
	redir->argv[j] = 0;
	redir->argc = j;
	return (1);
}
