/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 23:04:17 by hyeokim           #+#    #+#             */
/*   Updated: 2020/03/08 18:23:38 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	result;

	result = ft_strlen(src);
	while (size--)
	{
		if ((*dest = *src) != 0)
		{
			if ((size == 0) && (*dest != 0))
				*dest = 0;
		}
		else
			break ;
		dest++;
		src++;
	}
	return (result);
}
