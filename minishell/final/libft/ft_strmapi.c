/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:47:37 by hyeokim           #+#    #+#             */
/*   Updated: 2020/03/05 00:55:54 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int					alloc_len;
	unsigned int		idx;
	char				*new;

	alloc_len = ft_strlen(s) + 1;
	if (!(new = (char *)malloc(alloc_len * sizeof(char))))
		return (NULL);
	idx = 0;
	while (s[idx])
	{
		new[idx] = f(idx, s[idx]);
		idx++;
	}
	new[idx] = 0;
	return (new);
}
