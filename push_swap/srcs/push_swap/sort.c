/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:15:40 by hyeokim           #+#    #+#             */
/*   Updated: 2021/04/01 13:10:13 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_counter(t_cnt *cnt)
{
	cnt->r_count = 0;
	cnt->p_count = 0;
	cnt->idx = 0;
}

void	sort_atob(t_stack *a_stack, t_stack *b_stack, int len)
{
	int			mid_point;
	t_cnt		cnt;

	if (sort_check(a_stack))
		return ;
	if (optimize_base_two(a_stack, len))
		return ;
	init_counter(&cnt);
	mid_point = get_midpoint(a_stack, len);
	while (len-- > 0)
		if (a_stack->top->value < mid_point)
			exec_p(b_stack, a_stack, &(cnt.p_count), 'b');
		else
			exec_r(a_stack, &(cnt.r_count), 'a');
	while (cnt.idx++ < cnt.r_count)
		exec_reverse_r(a_stack, 'a');
	sort_atob(a_stack, b_stack, cnt.r_count);
	sort_btoa(a_stack, b_stack, cnt.p_count);
}

void	sort_btoa(t_stack *a_stack, t_stack *b_stack, int len)
{
	int			mid_point;
	t_cnt		cnt;

	if (len <= 2)
	{
		if (len == 2)
		{
			check_two_of_top(b_stack, 'd');
			exec_p(a_stack, b_stack, &(cnt.p_count), 'a');
		}
		exec_p(a_stack, b_stack, &(cnt.p_count), 'a');
		return ;
	}
	init_counter(&cnt);
	mid_point = get_midpoint(b_stack, len);
	while (len-- > 0)
		if (b_stack->top->value > mid_point)
			exec_p(a_stack, b_stack, &(cnt.p_count), 'a');
		else
			exec_r(b_stack, &(cnt.r_count), 'b');
	while (cnt.idx++ < cnt.r_count)
		exec_reverse_r(b_stack, 'b');
	sort_atob(a_stack, b_stack, cnt.p_count);
	sort_btoa(a_stack, b_stack, cnt.r_count);
}
