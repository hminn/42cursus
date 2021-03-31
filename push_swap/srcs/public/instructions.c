/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:07:02 by hyeokim           #+#    #+#             */
/*   Updated: 2021/03/31 01:28:35 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "push_swap.h"

void	exec_s(t_stack *stack, const char c)
{
	int		temp;
	char	output_cmd[3];

	if (stack->size >= 2)
	{
		temp = stack->top->value;
		stack->top->value = stack->top->next->value;
		stack->top->next->value = temp;
	}
	output_cmd[0] = 's';
	output_cmd[1] = c;
	output_cmd[2] = '\0';
	if (c != 0)
		ft_putendl_fd(output_cmd, 1);
}

void	exec_ss(t_stack *a_stack, t_stack *b_stack)
{
	exec_s(a_stack, 0);
	exec_s(b_stack, 0);
}

void	exec_p(t_stack *dst_stack, t_stack *src_stack, int *cnt, const char c)
{
	char	output_cmd[3];

	if (src_stack->size > 0)
		push(dst_stack, pop(src_stack));
	(*cnt)++;

	output_cmd[0] = 'p';
	output_cmd[1] = c;
	output_cmd[2] = '\0';
	if (c != 0)
		ft_putendl_fd(output_cmd, 1);
}

void	exec_r(t_stack *stack, int *cnt, const char c)
{
	t_node	*temp_node;
	char	output_cmd[3];
	int		temp;

	if (stack->size >= 2)
	{
		temp = stack->top->value;
		temp_node = stack->top->next;
		while (temp_node != stack->top)
		{
			temp_node->prev->value = temp_node->value;
			temp_node = temp_node->next;
		}
		stack->bottom->value = temp;
	}
	(*cnt)++;
	output_cmd[0] = 'r';
	output_cmd[1] = c;
	output_cmd[2] = '\0';
	if (c != 0)
		ft_putendl_fd(output_cmd, 1);
}

void	exec_rr(t_stack *a_stack, t_stack *b_stack, int *cnt)
{
	exec_r(a_stack, cnt, 0);
	exec_r(b_stack, cnt, 0);
}