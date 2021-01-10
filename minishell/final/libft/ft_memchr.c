/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 23:42:02 by hyeokim           #+#    #+#             */
/*   Updated: 2020/03/07 15:50:23 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *str;

	while (n-- > 0)
	{
		str = (unsigned char*)s;
		if (*str == (unsigned char)c)
			return (str);
		s++;
	}
	return (NULL);
}
