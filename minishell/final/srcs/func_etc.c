/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_etc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 16:13:25 by hyeokim           #+#    #+#             */
/*   Updated: 2021/01/10 16:14:01 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_puterror_fd(char *s1, char *s2, int fd)
{
	ft_putstr_fd(s1, fd);
	ft_putendl_fd(s2, fd);
	return (127);
}

void	free_double_arr(char **arr)
{
	int		idx;

	if (!arr)
		return ;
	idx = -1;
	while (arr[++idx])
		free(arr[idx]);
	free(arr);
}

void free_pipe(t_pipe *p)
{
	free_double_arr(p->argv);
	free(p->line);
}