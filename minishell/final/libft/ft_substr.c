/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:43:13 by hyeokim           #+#    #+#             */
/*   Updated: 2020/04/08 12:33:31 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char				*new;
	unsigned int		idx;

	if ((int)ft_strlen(s) < (int)start)
	{
		if (!(new = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	if (!(new = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		new[idx] = s[start + idx];
		idx++;
	}
	new[idx] = 0;
	return (new);
}
