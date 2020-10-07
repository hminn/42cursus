/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_struct_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:36:14 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/09 20:48:53 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_str_to_intarr(int *int_arr, char *input, int alloc_len)
{
	int		input_len;
	int		int_len;
	int		index;
	int		zero_space_len;

	input_len = ft_strlen(input);
	int_len = (alloc_len) * 3;
	zero_space_len = int_len - input_len;
	index = 0;
	while (index++ < zero_space_len)
		*int_arr++ = 0;
	index = 0;
	while (input[index])
	{
		int_arr[index] = (input[index] - 48);
		index++;
	}
}

void	ft_to_struct(t_numbers *n_struct, int *int_arr, int alloc_len)
{
	int		temp;
	int		jump;
	int		stct_index;

	jump = 0;
	stct_index = (alloc_len - 1);
	while (stct_index >= 0)
	{
		n_struct[stct_index].third = int_arr[jump];
		temp = (int_arr[jump + 1] * 10) + int_arr[jump + 2];
		if ((temp / 10) == 1)
		{
			n_struct[stct_index].second = temp;
			n_struct[stct_index].first = 0;
		}
		else
		{
			n_struct[stct_index].second = int_arr[jump + 1] * 10;
			n_struct[stct_index].first = int_arr[jump + 2];
		}
		jump += 3;
		stct_index--;
	}
}

void	ft_strctlz(t_numbers *number_strct, char *input, int alloc_len)
{
	int		*int_arr;

	int_arr = (int *)malloc(sizeof(int) * (alloc_len * 3));
	ft_str_to_intarr(int_arr, input, alloc_len);
	ft_to_struct(number_strct, int_arr, alloc_len);
	free(int_arr);
}
