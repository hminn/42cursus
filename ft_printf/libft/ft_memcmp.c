/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 00:14:26 by hyeokim           #+#    #+#             */
/*   Updated: 2020/09/18 19:48:39 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_memcmp(const void *src1, const void *src2, size_t size)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = src1;
	ptr2 = src2;
	if (size == 0)
		return (0);
	while (*ptr1 == *ptr2 && size--)
	{
		ptr1++;
		ptr2++;
		if (size == 0)
			return (0);
	}
	return (*ptr1 - *ptr2);
}
