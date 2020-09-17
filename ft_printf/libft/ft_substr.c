/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:43:13 by hyeokim           #+#    #+#             */
/*   Updated: 2020/03/08 16:25:34 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(const char *s, unsigned int start, size_t len)
{
	char				*new;
	unsigned int		idx;

	if ((int)len - (int)start < 0)
	 	return (ft_strdup(""));
	if (!(new = (char *)malloc((len - start + 1) * sizeof(char))))
		return (NULL);
	idx = 0;
	while (idx < len)
		new[idx++] = s[start++];
	new[idx] = 0;
	return (new);
}
