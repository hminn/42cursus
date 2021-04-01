/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:59:02 by hyeokim           #+#    #+#             */
/*   Updated: 2021/04/01 17:00:40 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		main(int argc, char *argv[])
{
	t_stack		*a_stack;
	t_stack		*b_stack;

	if (argc < 2)
		return (0);
	init_stack(&a_stack, argc, argv);
	init_stack(&b_stack, 0, NULL);
	if (!sort_check(a_stack))
	{
		if (a_stack->size <= 3 || a_stack->size == 5)
			optimize_base(a_stack, b_stack, a_stack->size);
		else
			sort_atob(a_stack, b_stack, a_stack->size);
	}
	delete_stack(a_stack);
	delete_stack(b_stack);
	return (0);
}
