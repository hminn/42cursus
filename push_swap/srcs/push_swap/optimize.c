/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:09:06 by hyeokim           #+#    #+#             */
/*   Updated: 2021/04/01 16:15:24 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"
#include "../../includes/push_swap.h"

int		optimize_base_two(t_stack *stack, int len)
{
	if (len <= 2)
	{
		if (len == 2)
			check_two_of_top(stack, 'a');
		return (1);
	}
	return (0);
}

int		optimize_base(t_stack *a_stack, t_stack *b_stack, int len)
{
	if (len == 5)
		check_five_of_top(a_stack, b_stack, 5);
	else if (len <= 3)
	{
		if (len == 2)
			check_two_of_top(a_stack, 'a');
		else if (len == 3)
			check_three_of_top(a_stack);
		return (1);
	}
	return (0);
}

void	check_two_of_top(t_stack *stack, const char c)
{
	if (c == 'a')
	{
		if (stack->top->value > stack->top->next->value)
			exec_s(stack, 'a');
	}
	else if (c == 'd')
	{
		if (stack->top->value < stack->top->next->value)
			exec_s(stack, 'b');
	}
	return ;
}

void	check_three_of_top(t_stack *a_stack)
{
	int		nodes[4];

	nodes[0] = a_stack->top->value;
	nodes[1] = a_stack->top->next->value;
	nodes[2] = a_stack->bottom->value;
	nodes[3] = 0;
	if (nodes[0] < nodes[2] && nodes[1] > nodes[2])
	{
		exec_r(a_stack, &nodes[3], 'a');
		exec_s(a_stack, 'a');
		exec_reverse_r(a_stack, 'a');
	}
	else if (nodes[0] > nodes[1] && nodes[0] < nodes[2])
		exec_s(a_stack, 'a');
	else if (nodes[0] < nodes[1] && nodes[0] > nodes[2])
		exec_reverse_r(a_stack, 'a');
	else if (nodes[0] > nodes[1] && nodes[1] > nodes[2])
	{
		exec_s(a_stack, 'a');
		exec_reverse_r(a_stack, 'a');
	}
	else if (nodes[0] > nodes[2] && nodes[1] < nodes[2])
		exec_r(a_stack, &nodes[3], 'a');
}

void	check_five_of_top(t_stack *a_stack, t_stack *b_stack, int len)
{
	int		temp;
	int		mid_point;

	temp = 0;
	mid_point = get_midpoint(a_stack, len);
	while (len-- > 0)
		if (a_stack->top->value < mid_point)
			exec_p(b_stack, a_stack, &temp, 'b');
		else
			exec_r(a_stack, &temp, 'a');
	check_three_of_top(a_stack);
	check_two_of_top(b_stack, 'd');
	exec_p(a_stack, b_stack, &temp, 'a');
	exec_p(a_stack, b_stack, &temp, 'a');
}
