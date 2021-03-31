/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 23:59:21 by hyeokim           #+#    #+#             */
/*   Updated: 2020/04/10 11:17:23 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	jump;

	i = 0;
	if (!*to_find)
		return ((char *)str);
	while (str[i] && len)
	{
		jump = 0;
		while (str[i + jump] == to_find[jump])
		{
			if (len < ft_strlen(to_find))
				return (0);
			if (to_find[jump + 1] == '\0')
				return ((char *)(str + i));
			jump++;
		}
		i++;
		len--;
	}
	return (0);
}
