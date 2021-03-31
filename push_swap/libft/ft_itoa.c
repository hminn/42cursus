/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:08:56 by hyeokim           #+#    #+#             */
/*   Updated: 2020/03/08 17:02:52 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_num_len(long long n)
{
	int			len;

	len = 1;
	n *= (n < 0 ? -1 : 1);
	while ((n = n / 10))
		len++;
	return (len);
}

void	ft_fill_plus_num(char *new, long long n)
{
	int		idx;

	n *= (n < 0 ? -1 : 1);
	idx = ft_num_len(n);
	new[idx] = 0;
	while (idx)
	{
		new[idx - 1] = (n % 10) + 48;
		n = n / 10;
		idx--;
	}
}

void	ft_fill_minus_num(char *new, long long n)
{
	int		idx;

	n *= (n < 0 ? -1 : 1);
	idx = ft_num_len(n);
	new[0] = '-';
	new[idx + 1] = 0;
	while (idx)
	{
		new[idx] = (n % 10) + 48;
		n = n / 10;
		idx--;
	}
}

char	*ft_itoa(int n)
{
	int		alloc_len;
	char	*new;

	alloc_len = ft_num_len(n) + (n < 0 ? 2 : 1);
	if (!(new = (char *)malloc(alloc_len * sizeof(char))))
		return (NULL);
	if (n < 0)
		ft_fill_minus_num(new, n);
	else
		ft_fill_plus_num(new, n);
	return (new);
}
