/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 20:17:06 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/02 14:05:04 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_init_board.h"

void	ft_input_board(int (*board)[6], char *str)
{
	int index;
	int j;

	j = 1;
	index = 0;
	while (j < 5)
	{
		if (index <= 6)
			board[0][j] = str[index] - 48;
		else if (8 <= index && index <= 14)
			board[5][j] = str[index] - 48;
		else if (16 <= index && index <= 22)
			board[j][0] = str[index] - 48;
		else if (24 <= index)
			board[j][5] = str[index] - 48;
		j++;
		if (index == 6 || index == 14 || index == 22)
			j = 1;
		index += 2;
	}
}

void	ft_input_map(int (*board)[6])
{
	int i;
	int j;

	i = 1;
	while (i < 5)
	{
		j = 1;
		while (j < 5)
		{
			if (board[i][j] != 0)
				board[i][j] = -1;
			j++;
		}
		i++;
	}
}

void	ft_full_board(int (*board)[6], char *str)
{
	ft_input_board(board, str);
	ft_init_board(board);
}

void	ft_full_map(int (*board_map)[6], char *str)
{
	ft_input_board(board_map, str);
	ft_init_board(board_map);
	ft_input_map(board_map);
}
