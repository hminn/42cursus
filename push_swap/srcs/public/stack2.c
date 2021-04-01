/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:47:11 by hyeokim           #+#    #+#             */
/*   Updated: 2021/04/01 16:35:35 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/push_swap.h"

int		create_stack(t_stack **stack)
{
	if (!((*stack) = (t_stack *)malloc(sizeof(t_stack))))
		return (0);
	(*stack)->top = NULL;
	(*stack)->bottom = NULL;
	(*stack)->size = 0;
	return (SUCCESS);
}

int		is_it_dup(int argc, char *argv[])
{
	int		i;
	int		j;

	i = 1;
	while (i < (argc - 1))
	{
		j = (i + 1);
		while (j <= (argc - 1))
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	init_stack(t_stack **stack, int argc, char *argv[])
{
	int			i;
	int			temp;
	long long	num;
	t_node		*temp_node;

	if (!(i = create_stack(stack)))
		ft_puterror_fd("Error", 2, *stack);
	if ((i = is_it_dup(argc, argv)))
		ft_puterror_fd("Error", 2, *stack);
	i = (argc - 1);
	while (i >= 1)
	{
		num = ft_atoi(argv[i]);
		if (!(temp = int_range_check(num)))
			ft_puterror_fd("Error", 2, *stack);
		if (!(temp_node = create_node(num)))
			ft_puterror_fd("Error", 2, *stack);
		push((*stack), temp_node);
		i--;
	}
}
