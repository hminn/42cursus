/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 20:17:06 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/02 18:08:12 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Converts the entered string to a number and places it in the 6x6 matrix.
*/

void	ft_input_board(int (*board)[6], char *str)
{
	int index;
	int loop;

	loop = 1;
	index = 0;
	while (loop < 5)
	{
		if (index <= 6)
			board[0][loop] = str[index] - 48;
		else if (8 <= index && index <= 14)
			board[5][loop] = str[index] - 48;
		else if (16 <= index && index <= 22)
			board[loop][0] = str[index] - 48;
		else if (24 <= index)
			board[loop][5] = str[index] - 48;
		loop++;
		if (index == 6 || index == 14 || index == 22)
			loop = 1;
		index += 2;
	}
}
