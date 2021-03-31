/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 23:47:27 by hyeokim           #+#    #+#             */
/*   Updated: 2021/03/30 16:42:15 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

void	swap(int *arr1, int *arr2);
int		partition(int arr[], int l, int r);
void	quicksort(int arr[], int l, int r);
void	arr_sort(int *arr_nums, int len);

#endif