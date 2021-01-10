/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:32:12 by hyeokim           #+#    #+#             */
/*   Updated: 2021/01/10 18:55:18 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_signal(int signo)
{
	int		status;

	if (signo == SIGINT)
	{
		ft_putstr_fd("\b\b  \b\b\n", 1);
		print_prompt(g_env_user);
		g_exit_value = 1;
		return ;
	}
	else if (signo == SIGQUIT)
	{
		signo = wait(&status);
		ft_putstr_fd("\b\b  \b\b", 1);
		g_exit_value = 127;
		if (signo != -1)
			ft_putstr_fd("^\\Quit: 3\n", 1);
	}
	return ;
}
