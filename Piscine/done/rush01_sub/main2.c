/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:11:53 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/02 12:13:28 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.c"
#include "ft_input.c"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		g_board[6][6];
int		g_arr[] = {1, 2, 3, 4};
int		g_perm_array[24][4];

void swap(int *a, int *b )
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
void	permutation(int n, int r)
{
	int j;
	int i;
	int k;

	j = 0;
	i = n - 1;
	if (r == 0)
	{
		k = 0;
		while (k < 4)
		{
			g_perm_array[j][k] = g_arr[k];
			k++;
		}
		for(int k = 0; k < 4; k++)
			printf("%d ", g_perm_array[j][k]);
		printf("\n");
		j++;
		return ;
	}

	while (i >= 0)
	{
		swap(&g_arr[i], &g_arr[n - 1]);
		permutation(n - 1, r - 1);
		swap(&g_arr[i], &g_arr[n - 1]);
		i--;
	}
}

int		main(int argc, char *argv[])
{
	if (argc != 2)
		write(1, "Error\n", 6);
	else if (ft_str_check(argv[1]))
	{
		ft_full_board(g_board, argv[1]);
		permutation(4, 4);
	}
	printf("\n-------------------\n");
	for(int j = 0; j < 24; j++)
	{
		for(int k = 0; k < 4; k++)
			printf("%d ", g_perm_array[j][k]);
		printf("\n");
	}
	return (0);
}
