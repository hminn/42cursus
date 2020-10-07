/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:11:53 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/02 18:12:07 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>

/*
** The main function is as follows:
** 1. Convert the string entered through the ft_input_board function
**		to an integer and insert it into the 6x6 matrix.
** 2. Check the error condition.
** 3. Use the puzzle function to find a solution that meets the conditions.
**		Returns 1 if solution exists, or 0 if not.
** 4. Print out the solution.
** 5. thanks.
*/

int		main(int argc, char *argv[])
{
	int		row;
	int		col;
	char	temp;
	int		board[6][6];

	ft_input_board(board, argv[1]);
	if (argc != 2 || !ft_str_check(argv[1]) || !puzzle(board, 1, 1, 0))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	row = 0;
	while (++row < 5)
	{
		col = 1;
		while (col < 5)
		{
			temp = board[row][col++] + 48;
			write(1, &temp, 1);
			if (col != 5)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
	return (0);
}
