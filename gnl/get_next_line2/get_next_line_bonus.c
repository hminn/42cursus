/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:48:55 by hyeokim           #+#    #+#             */
/*   Updated: 2020/04/15 12:24:52 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		alloc_len;
	int		idx;
	int		s1_len;

	alloc_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s1_len = ft_strlen(s1);
	if (!(new = (char *)malloc(alloc_len * sizeof(char))))
		return (NULL);
	idx = 0;
	while (idx < alloc_len - 1)
	{
		new[idx] = (idx < s1_len ? *s1++ : *s2++);
		idx++;
	}
	new[idx] = 0;
	return (new);
}

int		ft_put_newline(char **s_temp, char **line, int fd, int ret)
{
	char	*tmp;
	int		len;

	len = 0;
	while (s_temp[fd][len] != '\n' && s_temp[fd][len] != '\0')
		len++;
	if (s_temp[fd][len] == '\n')
	{
		*line = ft_substr(s_temp[fd], 0, len);
		tmp = ft_strdup(s_temp[fd] + len + 1);
		free(s_temp[fd]);
		s_temp[fd] = tmp;
		if (s_temp[fd][0] == '\0')
			ft_strdel(&s_temp[fd]);
	}
	else if (s_temp[fd][len] == '\0')
	{
		if (ret == BUFFER_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s_temp[fd]);
		return (ft_strdel(&s_temp[fd]));
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*s_temp[FD_SIZE];
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		s_temp[fd] = (s_temp[fd] == NULL ? ft_strdup("") : s_temp[fd]);
		tmp = ft_strjoin(s_temp[fd], buff);
		free(s_temp[fd]);
		s_temp[fd] = tmp;
		if (ft_strchr(s_temp[fd], '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (s_temp[fd] == NULL || s_temp[fd][0] == '\0'))
	{
		*line = (s_temp[fd] == NULL ? ft_strdup("") : *line);
		return (ft_strdel(&s_temp[fd]));
	}
	return (ft_put_newline(s_temp, line, fd, ret));
}
