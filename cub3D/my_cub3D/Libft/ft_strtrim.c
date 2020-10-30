/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:03:59 by hyeokim           #+#    #+#             */
/*   Updated: 2020/04/06 15:29:17 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_in_set(char c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

int		ft_back_check(char const *s, char const *set)
{
	while (*s)
		if (!(ft_is_in_set(*s++, set)))
			return (1);
	return (0);
}

int		ft_alloc_len(char const *s, char const *set)
{
	int		idx;
	int		len;

	len = 0;
	idx = 0;
	while (*(s + idx))
	{
		if (!(ft_is_in_set(*(s + idx), set)))
			len++;
		else
		{
			if (ft_back_check(s + idx, set) && len != 0)
				len++;
		}
		idx++;
	}
	return (len);
}

void	ft_fill_new(char *new, char const *s, char const *set)
{
	int		idx;

	idx = 0;
	while (*s)
	{
		if (!(ft_is_in_set(*s, set)))
			new[idx++] = *s;
		else
		{
			if (ft_back_check(s, set) && idx != 0)
				new[idx++] = *s;
		}
		s++;
	}
	new[idx] = 0;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		alloc_len;

	alloc_len = ft_alloc_len(s1, set) + 1;
	if (!(new = (char *)malloc(alloc_len * sizeof(char))))
		return (NULL);
	ft_fill_new(new, s1, set);
	return (new);
}
