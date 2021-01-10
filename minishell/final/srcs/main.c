/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:32:07 by hyeokim           #+#    #+#             */
/*   Updated: 2021/01/10 21:43:34 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		catch_signal(void)
{
	signal(SIGINT, (void *)handle_signal);
	signal(SIGQUIT, (void *)handle_signal);
}

void		save_envp(int argc, char **argv, char **envp, t_list **envs)
{
	int		delimiter;
	t_env	*env;

	g_envp = envp;
	if (!argc || !argv[0])
		exit(1);
	while (*envp)
	{
		env = (t_env *)malloc(sizeof(t_env));
		delimiter = ft_strchr(*envp, '=') - *envp;
		env->key = ft_substr(*envp, 0, delimiter);
		env->value = ft_substr(*envp, delimiter + 1,
				ft_strlen(*envp) - delimiter - 1);
		ft_lstadd_back(envs, ft_lstnew(env));
		envp++;
	}
	g_exit_value = 0;
	g_env_user = get_value("USER", *envs);
}

int			main(int argc, char **argv, char **envp)
{
	t_list	*envs;
	char	*line;
	char	**cmds;
	int		i;

	envs = 0;
	line = 0;
	save_envp(argc, argv, envp, &envs);
	catch_signal();
	while (1)
	{
		print_prompt(g_env_user);
		if (!preprocess_input(&line))
			continue ;
		if ((cmds = parse_line(line)) == NULL)
			continue ;
		i = -1;
		while (cmds[++i])
		{
			run_cmds(cmds[i], envs);
			free(cmds[i]);
		}
		free(cmds);
	}
	return (0);
}
