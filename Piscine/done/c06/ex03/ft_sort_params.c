/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:53:13 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/04 15:20:12 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(char *str1[], char *str2[])
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 != 0 || *s2 != 0)
	{
		if (*s1 > *s2)
			return (1);
		else if (*s2 > *s1)
			return (0);
		s1++;
		s2++;
	}
	return (0);
}

void	ft_print_argv(int argc, char *argv[])
{
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != 0)
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		main(int argc, char *argv[])
{
	int		i;
	int		j;

	j = (argc - 1);
	while (j > 1)
	{
		i = 1;
		while (i < j)
		{
			if (ft_strcmp(argv[i], argv[j]))
				ft_swap(&argv[i], &argv[j]);
			i++;
		}
		j--;
	}
	ft_print_argv(argc, argv);
	return (0);
}
