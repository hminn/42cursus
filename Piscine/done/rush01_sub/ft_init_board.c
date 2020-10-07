/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 16:08:51 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/01 18:22:07 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_init_up(int (*board)[6])
{
	int	index;
	int init;

	index = 1;
	init = 1;
	while (index < 5)
	{
		if (board[0][index] == 4)
		{
			while (init < 5)
			{
				board[init][index] = init;
				init++;
			}
		}
		else if (board[0][index] == 1)
			board[1][index] = 4;
		index++;
	}
}

void	ft_init_down(int (*board)[6])
{
	int	index;
	int init;

	index = 1;
	init = 1;
	while (index < 5)
	{
		if (board[5][index] == 4)
		{
			while (init < 5)
			{
				board[init][index] = (5 - init);
				init++;
			}
		}
		else if (board[5][index] == 1)
			board[4][index] = 4;
		index++;
	}
}

void	ft_init_left(int (*board)[6])
{
	int	index;
	int init;

	index = 1;
	init = 1;
	while (index < 5)
	{
		if (board[index][0] == 4)
		{
			while (init < 5)
			{
				board[index][init] = init;
				init++;
			}
		}
		else if (board[index][0] == 1)
			board[index][1] = 4;
		index++;
	}
}

void	ft_init_right(int (*board)[6])
{
	int	index;
	int init;

	index = 1;
	init = 1;
	while (index < 5)
	{
		if (board[index][5] == 4)
		{
			while (init < 5)
			{
				board[index][init] = (5 - init);
				init++;
			}
		}
		else if (board[index][5] == 1)
			board[index][4] = 4;
		index++;
	}
}

void	ft_init_board(int (*board)[6])
{
	ft_init_up(board);
	ft_init_down(board);
	ft_init_left(board);
	ft_init_right(board);
}
