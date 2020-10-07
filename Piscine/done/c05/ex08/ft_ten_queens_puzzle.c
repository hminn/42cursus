/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 13:42:16 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/04 11:01:24 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		g_cnt = 0;

void	ft_print_solution(int *tuple)
{
	int		i;
	char	temp;

	i = 0;
	while (i < 10)
	{
		temp = tuple[i] + '0';
		write(1, &temp, 1);
		i++;
	}
	g_cnt += 1;
	write(1, "\n", 1);
}

int		ft_promise(int value, int index, int *tuple)
{
	int loop;

	loop = 0;
	while (loop != index)
	{
		if (value == tuple[loop] ||
			((value - tuple[loop]) == (index - loop)) ||
			((value - tuple[loop]) == (index - loop) * -1))
			return (0);
		loop++;
	}
	return (1);
}

void	ft_solver(int *tuple, int index)
{
	int		value;

	value = 0;
	while (value < 10)
	{
		if (ft_promise(value, index, tuple))
		{
			tuple[index] = value;
			if (index != 9)
				ft_solver(tuple, index + 1);
			else
				ft_print_solution(tuple);
		}
		value++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int		tuple[10];

	ft_solver(tuple, 0);
	return (g_cnt);
}
