/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 10:50:38 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/02 18:17:17 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** rules of input string
** 1. number : ‘1’ ~ ‘4’
** 2. After input numbers, Must have space
** 3. number string length : number (16) + space (15)
** -> An even number of indexes should have numbers
**		and an odd number of indexes should have spaces.
** -> If input string is not, that string is invalid
*/

int		ft_str_check(char *str)
{
	int index;
	int len_cnt;

	index = 0;
	len_cnt = 0;
	while (str[index] != 0)
	{
		if ((index % 2 == 0) && (str[index] > '0' && str[index] < '5'))
			len_cnt++;
		else if ((index % 2 == 1) && (str[index] == ' '))
			len_cnt++;
		else
			return (0);
		index++;
	}
	if (len_cnt == 31)
		return (1);
	return (0);
}
