/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:50:46 by hyeokim           #+#    #+#             */
/*   Updated: 2021/04/01 12:44:18 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "stack.h"
#include "sort.h"
#include "../libft/libft.h"

typedef struct	s_cnt
{
	int			r_count;
	int			p_count;
	int			idx;
}				t_cnt;

void	exec_s(t_stack *stack, const char c);
void	exec_ss(t_stack *a_stack, t_stack *b_stack);
void	exec_p(t_stack *dst_stack, t_stack *src_stack, int *cnt, const char c);
void	exec_r(t_stack *stack, int *count, const char c);
void	exec_rr(t_stack *a_stack, t_stack *b_stack, int *count);
void	exec_reverse_r(t_stack *stack, const char c);
void	exec_reverse_rr(t_stack *a_stack, t_stack *b_stack);
void	exec_rrp(t_stack *a_stack, t_stack *b_stack, int *cnt);
void	ft_puterror_fd(char *s, int fd, t_stack *stack);
void	print_stack(t_stack *stack);
void	init_counter(t_cnt *cnt);
void	check_two_of_top(t_stack *stack, const char c);
void	check_three_of_top(t_stack *a_stack);
void	check_five_of_top(t_stack *a_stack, t_stack *b_stack, int len);
int		get_midpoint(t_stack *stack, int len);
int		optimize_base(t_stack *a_stack, t_stack *b_stack, int len);
int		optimize_base_two(t_stack *stack, int len);
int		sort_check(t_stack *stack);
void	sort_atob(t_stack *a_stack, t_stack *b_stack, int len);
void	sort_btoa(t_stack *a_stack, t_stack *b_stack, int len);

#endif