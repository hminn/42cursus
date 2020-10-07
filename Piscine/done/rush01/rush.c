/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semoon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 15:50:11 by semoon            #+#    #+#             */
/*   Updated: 2020/02/02 18:15:40 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <ft_promise_row>
** If a row is filled with a value, check if it meets the given conditions.
*/

int		ft_promise_row(int (*board)[6], int row)
{
	int index;
	int count;
	int max;

	index = 1;
	count = 1;
	max = board[row][1];
	while (index < 4)
		if (max < board[row][++index])
		{
			max = board[row][index];
			count++;
		}
	if (board[row][0] != count)
		return (0);
	max = board[row][4];
	count = 1;
	while (index > 1)
		if (max < board[row][--index])
		{
			max = board[row][index];
			count++;
		}
	return (board[row][5] != count ? 0 : 1);
}

/*
** <ft_promise_col>
** If a col is filled with a value, check if it meets the given conditions.
*/

int		ft_promise_col(int (*board)[6], int col)
{
	int index;
	int count;
	int max;

	index = 0;
	count = 1;
	max = board[1][col];
	while (index < 4)
		if (max < board[++index][col])
		{
			max = board[index][col];
			count++;
		}
	if (board[0][col] != count)
		return (0);
	count = 1;
	max = board[4][col];
	while (index > 1)
		if (max < board[--index][col])
		{
			max = board[index][col];
			count++;
		}
	return (board[5][col] != count ? 0 : 1);
}

/*
** <ft_promise>
** Only values 1 to 4 in a row, column, can be entered.
** At this time, the same value should not be added.
** When entering a value, check the values of the row and column of
**	its coordinates to prevent the same value from entering.
*/

int		ft_promise(int (*board)[6], int row, int col, int value)
{
	int index;

	index = 1;
	while (index < col)
	{
		if (board[row][index] == value)
			return (0);
		index++;
	}
	index = 1;
	while (index < row)
	{
		if (board[index][col] == value)
			return (0);
		index++;
	}
	return (1);
}

/*
** <puzzle>
** The function will proceed as follows:
** 1. The function starts at (1, 1).
** 2. Each row and column has unique numbers of 1, 2, 3, and 4.
** 3. When one line with another value is completed using the ft_promise func,
**		verify that it meets the conditions entered through ft_promise_row.
** 4. If not, return to the previous recursive function and repeat until a value
**		that matches the condition is entered.
** 5. When one column is complete, check if the conditions entered
**		through ft_promise_row are correct.
** 6. If not, repeat the above process.
** 7. When all the correct values are entered,
**		return ‘1’ to the coordinate being (5, 1)
** 8. If all cases have been found but no value, return ‘0’.
*/

int		puzzle(int (*board)[6], int row, int col, int flag)
{
	int value;

	value = 1;
	if (row == 5 && col == 1)
		return (1);
	while (value < 5)
	{
		if (ft_promise(board, row, col, value))
		{
			board[row][col] = value;
			if (row == 4 && !(ft_promise_col(board, col)))
				return (0);
			if (col != 4)
				flag = puzzle(board, row, col + 1, flag);
			else if (col == 4 && ft_promise_row(board, row))
				flag = puzzle(board, row + 1, 1, flag);
			else
				return (0);
		}
		if (flag)
			return (1);
		value++;
	}
	return (0);
}
