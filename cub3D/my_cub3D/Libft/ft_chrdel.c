/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:54:28 by hyeokim           #+#    #+#             */
/*   Updated: 2020/11/10 14:54:40 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chrdel(char const *s, char c)
{
	unsigned int	idx_s;
	unsigned int	idx_buf;
	char			*buf;

	if (!s || !(buf = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	idx_s = 0;
	idx_buf = 0;
	while (s[idx_s])
	{
		if (s[idx_s] == c)
		{
			idx_s++;
			continue ;
		}
		buf[idx_buf++] = s[idx_s++];
	}
	buf[idx_buf] = '\0';
	return (buf);
}
