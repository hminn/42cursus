/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:49:35 by hyeokim           #+#    #+#             */
/*   Updated: 2020/04/15 12:25:38 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_BONUS_H
#	define GET_NEXT_LINE_BONUS_H
#	define FD_SIZE 255
#include <stdlib.h>
#include <unistd.h>

size_t		ft_strlen(const char *str);
int			ft_strdel(char **s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *src);
char		*ft_substr(const char *s, unsigned int start, size_t len);
int			get_next_line(int fd, char **line);
#	endif
