/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 22:43:01 by hyeokim           #+#    #+#             */
/*   Updated: 2020/04/13 12:57:35 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_result_arr(char *dest, const char *src,
						size_t size, int *result)
{
	if (size <= ft_strlen(dest))
	{
		result[1] = 0;
		result[0] = ft_strlen(src) + size;
	}
	else
	{
		result[1] = (size - ft_strlen(dest) - 1);
		result[0] = ft_strlen(src) + ft_strlen(dest);
	}
}

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	int	result[2];

	ft_result_arr(dest, src, size, result);
	while (dest)
	{
		if (*dest == 0)
		{
			while ((*src != 0) && (result[1]-- != 0))
			{
				*dest++ = *src++;
			}
			*dest = 0;
			break ;
		}
		dest++;
	}
	return (result[0]);
}
