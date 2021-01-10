/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 10:32:01 by hyeokim           #+#    #+#             */
/*   Updated: 2021/01/10 16:01:04 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*change_argv(char *str, t_list *envs)
{
	char	*ret;

	ret = 0;
	if (check_quote(str))
		ret = parse_quote(str, envs);
	else if (!strncmp(str, "$?", 3))
		ret = ft_itoa(g_exit_value);
	else if (check_env(str))
		ret = parse_env(str, envs);
	free(str);
	return (ret);
}

char	**get_argv(char *line, t_list *envs)
{
	int		i;
	char	**argv;

	if (!(argv = ft_split(line, ' ')))
		return (0);
	i = -1;
	while (argv[++i])
	{
		if ((ft_strlen(argv[i]) != 1)
			&& (check_quote(argv[i]) || check_env(argv[i])))
			argv[i] = change_argv(argv[i], envs);
	}
	return (argv);
}
