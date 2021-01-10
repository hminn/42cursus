/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:51:24 by hyeokim           #+#    #+#             */
/*   Updated: 2021/01/10 03:33:00 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_isdigit_str(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (!ft_isdigit(str[idx]))
			return (0);
		idx++;
	}
	return (1);
}

void			run_exit(char **argv)
{
	int	argc;

	argc = 0;
	while (argv[argc] != NULL)
		argc++;
	if (argc == 1)
	{
		ft_putendl_fd("exit", 1);
		exit(EXIT_SUCCESS);
	}
	else if (argc == 2 && ft_isdigit_str(argv[1]))
	{
		ft_putendl_fd("exit", 1);
		exit(ft_atoi(argv[1]));
	}
	else if (argc > 2 && ft_isdigit_str(argv[1]))
		ft_putendl_fd("exit\nexit: too many arguments", 1);
	else
	{
		ft_putendl_fd("exit\nexit: numeric argument required", 1);
		exit(2);
	}
}
