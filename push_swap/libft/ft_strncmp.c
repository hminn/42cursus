/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 23:00:59 by hyeokim           #+#    #+#             */
/*   Updated: 2020/04/06 15:30:29 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int 	ft_strcmp(const char *s1, const char *s2)
{
    size_t	i;

    i = 0;
    while (*(s1 + i) == *(s2 + i))
    {
        if (*(s1 + i) == 0)
            return (0);
        i++;
    }
    return (*(s1 + i) - *(s2 + i));
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && (n-- != 0))
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}
