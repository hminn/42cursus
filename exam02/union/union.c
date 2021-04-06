/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 12:02:18 by hyeokim           #+#    #+#             */
/*   Updated: 2021/04/02 12:23:21 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_dup(char *str1, char *str2, int i, char c)
{
	int		j;

	j = 0;
	while (j < i)
		if (str1[j++] == str1[i])
			return (1);
	if (c != 0)
	{
		while (*str2)
		{
			if (*str2 == c)
				return (1);
			str2++;
		}
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	int		i;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (!check_dup(argv[1], argv[2], i, 0))
				write(1, &argv[1][i], 1);
			i++;
		}
		i = 0;
		while (argv[2][i])
		{
			if (!check_dup(argv[2], argv[1], i, argv[2][i]))
				write(1, &argv[2][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}