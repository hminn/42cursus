/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 16:19:26 by hyeokim           #+#    #+#             */
/*   Updated: 2021/01/10 21:43:02 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			is_valid_for_env(char *arg)
{
	if (arg[0] == '=')
		return (1);
	if (!ft_strchr(arg, '='))
		return (2);
	return (0);
}

int			is_valid_for_export(char *arg)
{
	if (ft_isdigit(arg[0]) || arg[0] == '=')
		return (0);
	if (ft_strchr(arg, '='))
		return (1);
	return (0);
}

int			is_exist_key(char *key, t_list *envs)
{
	int		len;
	int		len_find;
	int		len_exist;

	len_find = ft_strlen(key);
	len_exist = ft_strlen((char *)((t_env *)envs->content)->key);
	len = (len_find > len_exist) ? len_find : len_exist;
	if (ft_strncmp(key, ((t_env *)envs->content)->key, len) == 0)
		return (1);
	return (0);
}

char		*get_value(char *key, t_list *envs)
{
	char	*env_key;

	while (envs)
	{
		env_key = ((t_env *)envs->content)->key;
		if (!(ft_strncmp(env_key, key, ft_strlen(key))))
			return (((t_env *)envs->content)->value);
		envs = envs->next;
	}
	return ("");
}

char		*find_path(char *argv, t_list *envs)
{
	int			idx;
	char		*temp;
	char		*new_path;
	char		**paths;
	struct stat	s;

	if (!(temp = get_value("PATH", envs)))
		return (NULL);
	paths = ft_split(temp, ':');
	idx = -1;
	while (paths[++idx])
	{
		temp = ft_strjoin("/", argv);
		new_path = ft_strjoin(paths[idx], temp);
		free(temp);
		if (stat(new_path, &s) == 0)
		{
			free_double_arr(paths);
			return (new_path);
		}
		free(new_path);
	}
	free_double_arr(paths);
	return (ft_strdup(argv));
}
