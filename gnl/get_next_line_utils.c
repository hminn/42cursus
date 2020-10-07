/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:49:20 by hyeokim           #+#    #+#             */
/*   Updated: 2020/04/15 12:24:59 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int		cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

int		ft_strdel(char **s)
{
	if (s)
	{
		free(*s);
		*s = NULL;
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (c == '\0')
		return ((char*)s);
	return (0);
}

char	*ft_strdup(const char *src)
{
	char	*pointer;
	int		index;

	if (!(pointer = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	index = 0;
	while (src[index])
	{
		pointer[index] = src[index];
		index++;
	}
	pointer[ft_strlen(src)] = 0;
	return (pointer);
}

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
