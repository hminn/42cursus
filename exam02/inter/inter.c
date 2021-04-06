/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:46:10 by hyeokim           #+#    #+#             */
/*   Updated: 2021/04/02 11:59:57 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_dup(char *str, int i)
{
	int		j;

	if (i < 1)
		return (0);
	j = 0;
	while (j < i)
	{
		if (str[j] == str[i])
			return (1);
		j++;
	}
	return (0);
}

int		check_in_string(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
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
			if (check_in_string(argv[2], argv[1][i]) &&
				!check_dup(argv[1], i))
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}