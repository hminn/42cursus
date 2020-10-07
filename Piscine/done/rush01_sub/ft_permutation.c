/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_permutation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 23:06:50 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/02 12:28:10 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int g_arr[] = {1, 2, 3, 4};

void swap(int *a, int *b )
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
#include <stdio.h>
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
			perm_array[j][k] = g_arr[k];
			k++;
		}
		for(int k = 0; k < 4; k++)
			printf("%d ", perm_array[j][k]);
		printf("\n");
		j++;
		return ;
	}

	while (i >= 0)
	{
		swap(&g_arr[i], &g_arr[n - 1]);
		permutation(perm_array, g_arr, n - 1, r - 1);
		swap(&g_arr[i], &g_arr[n - 1]);
		i--;
	}
}
