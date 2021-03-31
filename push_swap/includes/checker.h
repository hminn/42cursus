/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 22:31:41 by hyeokim           #+#    #+#             */
/*   Updated: 2021/03/30 23:16:30 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
#include "stack.h"
#include "sort.h"
#include "push_swap.h"
#include "../libft/libft.h"

int		check_cmd(char *cmd);
void	exec_cmd(t_stack *a_stack, t_stack *b_stack, char *cmd);
void	output_result(int i);

#endif