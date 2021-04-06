/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 12:29:02 by hyeokim           #+#    #+#             */
/*   Updated: 2021/04/02 20:10:53 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*new_s;

	if (!s)
		return (0);
	i = 0;
	new_s = (char *)malloc(ft_strlen(s) + 1);
	while (s[i])
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*new_s;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_s = (char *)malloc(len1 + len2 + 1);
	i = 0;
	while (s1 && *s1)
	{
		new_s[i++] = *s1;
		s1++;
	}
	while (s2 && *s2)
	{
		new_s[i++] = *s2;
		s2++;
	}
	new_s[i] = '\0';
	return (new_s);
}

int		get_next_line(char **line)
{
	int			ret;
	char		buf[2];
	char		*tmp;
	static char *stack = 0;

	stack = stack == 0 ? ft_strdup("") : stack;
	while ((ret = read(0, buf, 1) > 0))
	{
		if (buf[0] == '\n')
		{
			*line = ft_strdup(stack);
			free(stack);
			stack = 0;
			break ;
		}
		buf[ret] = '\0';
		tmp = ft_strjoin(stack, buf);
		free(stack);
		stack = tmp;
	}
	if (ret == 0)
	{
		*line = ft_strdup(stack);
		free(stack);
		stack = 0;
	}
	return (ret);
}
