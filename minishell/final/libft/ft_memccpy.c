/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 22:57:18 by hyeokim           #+#    #+#             */
/*   Updated: 2020/03/01 22:58:51 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	ptr_dest = (unsigned char*)dest;
	ptr_src = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		if (ptr_dest[i] == (unsigned char)c)
			return ((void*)(dest + i + 1));
		++i;
	}
	return (NULL);
}
