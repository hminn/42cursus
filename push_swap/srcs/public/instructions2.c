/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:40:32 by hyeokim           #+#    #+#             */
/*   Updated: 2021/03/31 01:28:20 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "push_swap.h"

void	exec_reverse_r(t_stack *stack, const char c)
{
	t_node	*temp_node;
	char	output_cmd[4];
	int		temp;

	if (stack->size >= 2)
	{
		temp = stack->bottom->value;
		temp_node = stack->bottom->prev;
		while (temp_node != stack->bottom)
		{
			temp_node->next->value = temp_node->value;
			temp_node = temp_node->prev;
		}
		stack->top->value = temp;
	}
	output_cmd[0] = 'r';
	output_cmd[1] = 'r';
	output_cmd[2] = c;
	output_cmd[3] = '\0';
	if (c != 0)
		ft_putendl_fd(output_cmd, 1);
}

void	exec_reverse_rr(t_stack *a_stack, t_stack *b_stack)
{
	exec_reverse_r(a_stack, 0);
	exec_reverse_r(b_stack, 0);
}

void	exec_rrp(t_stack *a_stack, t_stack *b_stack, int *cnt)
{
	exec_reverse_r(a_stack, 'a');
	exec_p(b_stack, a_stack, cnt, 'b');
}