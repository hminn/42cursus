/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 23:33:17 by hyeokim           #+#    #+#             */
/*   Updated: 2021/03/30 16:42:03 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sort.h"

void	swap(int *arr1, int *arr2)
{
	int temp;

	temp = *arr2;
	*arr2 = *arr1;
	*arr1 = temp;

	return ;
}

int		partition(int arr[], int l, int r)
{
	int pivot;
	int	i;
	int j;

	pivot = arr[r];
	i = (l - 1);
	j = l;
	while (j <= r - 1)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[r]);
	return (i + 1);
}

void	quicksort(int arr[], int l, int r)
{
	int p;

	if (l < r)
	{
		p = partition(arr, l, r);
		quicksort(arr, l, p - 1);
		quicksort(arr, p + 1, r);
	}
	else
		return ;
}

void	arr_sort(int *arr_nums, int len)
{
	quicksort(arr_nums, 0, (len - 1));
}