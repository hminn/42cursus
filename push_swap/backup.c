/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:15:40 by hyeokim           #+#    #+#             */
/*   Updated: 2021/03/30 11:29:45 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include "../includes/sort.h"

void	create_counter(t_cnt **cnt)
{
	if (!((*cnt) = (t_cnt *)malloc(sizeof(t_cnt))))
		return ;
	(*cnt)->r_count = 0;
	(*cnt)->p_count = 0;
	(*cnt)->idx = 0;
}

void	init_counter(t_cnt **cnt)
{
	(*cnt)->r_count = 0;
	(*cnt)->p_count = 0;
	(*cnt)->idx = 0;
}

void	sort_atob(t_stack *a_stack, t_stack *b_stack, int len, t_cnt *cnt)
{
	int		mid_point;
	int		temp;

	if (len <= 2)
	{
		if (len == 2)
			check_two_of_top(a_stack, 'a');
		return ;
	}
	init_counter(&cnt);
	mid_point = get_midpoint(a_stack, len);
	while (len-- > 0)
	{
		if (a_stack->top->value < mid_point)
			exec_p(b_stack, a_stack, &cnt->p_count);
		else
		{
			if (a_stack->bottom->value < mid_point)
			{
				exec_rr_and_p(a_stack, b_stack, &cnt->p_count);
				continue ;
			}
			exec_r(a_stack, &cnt->r_count);
		}
	}
	while (cnt->idx++ < cnt->r_count)
		exec_reverse_r(a_stack);
	ft_putstr_fd("\n\n here is atob \n", 1);
	ft_putstr_fd("a_stack is ", 1);
	print_stack(a_stack);
	ft_putstr_fd("b_stack is ", 1);
	print_stack(b_stack);
	ft_putstr_fd("cnt->r_count is ", 1);
	ft_putnbr_fd(cnt->r_count, 1);
	write(1, "\n", 1);
	ft_putstr_fd("cnt->p_count is ", 1);
	ft_putnbr_fd(cnt->p_count, 1);
	write(1, "\n", 1);
	ft_putstr_fd("==========\n", 1);
	temp = cnt->p_count;
	sort_atob(a_stack, b_stack, cnt->r_count, cnt);
	sort_btoa(a_stack, b_stack, temp, cnt);
}

void	sort_btoa(t_stack *a_stack, t_stack *b_stack, int len, t_cnt *cnt)
{
	int		mid_point;

	ft_putstr_fd("\n\n here is btoa \n", 1);
	ft_putstr_fd("len is ", 1);
	ft_putnbr_fd(len, 1);
	write(1,"\n",1);
	if (len <= 2)
	{
		if (len == 2)
		{
			check_two_of_top(b_stack, 'd');
			exec_p(a_stack, b_stack, &cnt->p_count);
		}
		exec_p(a_stack, b_stack, &cnt->p_count);
		return ;
	}
	init_counter(&cnt);
	mid_point = get_midpoint(b_stack, len);
	while (len-- > 0)
	{
		if (b_stack->top->value > mid_point)
			exec_p(a_stack, b_stack, &cnt->p_count);
		else
			exec_r(b_stack, &cnt->r_count);
	}
	while (cnt->idx < cnt->r_count)
	{
		exec_reverse_r(b_stack);
		cnt->idx++;
	}
	ft_putstr_fd("a_stack is ", 1);
	print_stack(a_stack);
	ft_putstr_fd("b_stack is ", 1);
	print_stack(b_stack);
	ft_putstr_fd("cnt->p_count is ", 1);
	ft_putnbr_fd(cnt->p_count, 1);
	write(1, "\n", 1);
	ft_putstr_fd("cnt->r_count is ", 1);
	ft_putnbr_fd(cnt->r_count, 1);
	write(1, "\n", 1);
	ft_putstr_fd("==========\n", 1);
	sort_atob(a_stack, b_stack, cnt->p_count, cnt);
	sort_btoa(a_stack, b_stack, cnt->r_count, cnt);
}