/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 00:40:44 by hyeokim           #+#    #+#             */
/*   Updated: 2020/03/12 17:22:53 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, void *src, size_t size)
{
	char	*dest_ptr;
	char	*src_ptr;

	dest_ptr = dest;
	src_ptr = src;
	while (size--)
		*dest_ptr++ = *src_ptr++;
	return (dest);
}