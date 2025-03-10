/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 21:52:26 by hyeokim           #+#    #+#             */
/*   Updated: 2021/01/06 21:52:32 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		delete_key(char *argv, t_list *envs)
{
	t_list *curr;
	t_list *next;

	curr = envs;
	while (curr->next)
	{
		if (is_exist_key(argv, curr->next))
		{
			next = curr->next;
			curr->next = next->next;
			free(((t_env *)next->content)->key);
			free(((t_env *)next->content)->value);
			free(next->content);
			free(next);
			return ;
		}
		curr = curr->next;
	}
}

void			run_unset(char **argv, t_list *envs)
{
	argv++;
	while (*argv)
	{
		delete_key(*argv, envs);
		argv++;
	}
}
