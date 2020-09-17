/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 23:59:21 by hyeokim           #+#    #+#             */
/*   Updated: 2020/04/07 12:03:43 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int		i;

	if (*to_find == 0 || (*str == *to_find && *(to_find + 1) == 0))
		return ((char *)str);
	while (*str && len)
	{
		if (*str == *to_find)
		{
			i = 0;
			while (++i)
			{
				if (*(str + i) == *(to_find + i) && (len >= ft_strlen(to_find)))
				{
					if (*(to_find + i + 1) == 0)
						return ((char *)str);
				}
				else
					break ;
			}
		}
		len--;
		str++;
	}
	return (0);
}
