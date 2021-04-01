/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:55:31 by hyeokim           #+#    #+#             */
/*   Updated: 2021/04/01 11:09:12 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_puterror_fd(char *s, int fd, t_stack *stack)
{
	ft_putendl_fd(s, fd);
	delete_stack(stack);
	exit(1);
}

int		sort_check(t_stack *stack)
{
	int		temp;
	t_node	*temp_node;

	temp = stack->top->value;
	temp_node = stack->top;
	while (temp_node != stack->bottom)
	{
		if (temp > temp_node->next->value)
			return (0);
		temp_node = temp_node->next;
		temp = temp_node->value;
	}
	return (1);
}

int		get_midpoint(t_stack *stack, int len)
{
	int		i;
	int		mid_index;
	int		mid_num;
	int		*arr_nums;
	t_node	*temp_node;

	arr_nums = (int *)malloc(sizeof(int) * len);
	i = 0;
	temp_node = stack->top;
	while (i <= (len - 1))
	{
		arr_nums[i] = temp_node->value;
		temp_node = temp_node->next;
		i++;
	}
	arr_sort(arr_nums, len);
	mid_index = ((len - 1) / 2);
	if (len % 2 == 0)
		mid_index++;
	mid_num = arr_nums[mid_index];
	free(arr_nums);
	return (mid_num);
}

void	print_stack(t_stack *stack)
{
	t_node	*temp_node;

	if (stack->size == 0)
	{
		write(1, "\n", 1);
		return ;
	}
	temp_node = stack->top;
	while (42)
	{
		ft_putnbr_fd(temp_node->value, 1);
		write(1, " ", 1);
		if (temp_node == stack->bottom)
			break ;
		temp_node = temp_node->next;
	}
	write(1, "\n", 1);
}
