/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_etc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:52:06 by hyeokim           #+#    #+#             */
/*   Updated: 2021/01/10 01:09:11 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_pwd(void)
{
	char	*pwd;

	pwd = getcwd(0, 1024);
	ft_putendl_fd(pwd, 1);
	free(pwd);
}

void	run_echo(char **argv)
{
	int		idx;
	int		nline;

	idx = 0;
	nline = 0;
	while (argv[++idx])
	{
		if (!ft_strncmp(argv[idx], "-n", 3) && idx == 1)
		{
			nline++;
			continue ;
		}
		ft_putstr_fd(argv[idx], 1);
		if (argv[idx + 1] != NULL)
			ft_putstr_fd(" ", 1);
	}
	!nline ? ft_putstr_fd("\n", 1) : 0;
}
