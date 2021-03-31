/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:10:44 by hyeokim           #+#    #+#             */
/*   Updated: 2021/03/31 15:25:46 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sort.h"
#include "../../includes/checker.h"

int		check_cmd(char *cmd)
{
	if (!ft_strcmp(cmd, "sa") || !ft_strcmp(cmd, "sb") ||
		!ft_strcmp(cmd, "ss") || !ft_strcmp(cmd, "pa") ||
		!ft_strcmp(cmd, "pb") || !ft_strcmp(cmd, "ra") ||
		!ft_strcmp(cmd, "rb") || !ft_strcmp(cmd, "rr") ||
		!ft_strcmp(cmd, "rra") || !ft_strcmp(cmd, "rrb") ||
		!ft_strcmp(cmd, "rrr"))
		return (1);
	return (0);
}

void	exec_cmd(t_stack *a_stack, t_stack *b_stack, char *cmd)
{
	int		i;

	i = 0;
	if (!ft_strcmp(cmd, "sa"))
		exec_s(a_stack, 0);
	else if (!ft_strcmp(cmd, "sb"))
		exec_s(b_stack, 0);
	else if (!ft_strcmp(cmd, "ss"))
		exec_ss(a_stack, b_stack);
	else if (!ft_strcmp(cmd, "pa"))
		exec_p(a_stack, b_stack, &i, 0);
	else if (!ft_strcmp(cmd, "pb"))
		exec_p(b_stack, a_stack, &i, 0);
	else if (!ft_strcmp(cmd, "ra"))
		exec_r(a_stack, &i, 0);
	else if (!ft_strcmp(cmd, "rb"))
		exec_r(b_stack, &i, 0);
	else if (!ft_strcmp(cmd, "rr"))
		exec_rr(a_stack, b_stack, &i);
	else if (!ft_strcmp(cmd, "rra"))
		exec_reverse_r(a_stack, 0);
	else if (!ft_strcmp(cmd, "rrb"))
		exec_reverse_r(b_stack, 0);
	else if (!ft_strcmp(cmd, "rrr"))
		exec_reverse_rr(a_stack, b_stack);
}

void	output_result(int i)
{
	if (i == 1)
	{
		ft_putstr_fd("OK\n", 1);
		return ;
	}
	ft_putstr_fd("KO\n", 1);
}

int		main(int argc, char *argv[])
{
	char		*cmd;
	t_stack		*a_stack;
	t_stack		*b_stack;

	if (argc < 2)
		return (0);
	init_stack(&a_stack, argc, argv);
	init_stack(&b_stack, 0, NULL);
	while ((get_next_line(0, &cmd)) > 0)
	{
		if (!check_cmd(cmd))
		{
			ft_putstr_fd("Error\n", 2);
			break ;
		}
		exec_cmd(a_stack, b_stack, cmd);
	}
	output_result(sort_check(a_stack));
	delete_stack(a_stack);
	delete_stack(b_stack);
	return (0);
}
