/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dict_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:35:11 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/12 02:03:54 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

extern char		*g_convert[101];
extern char		*g_llion[13];

char	*ft_read_dict(const char *file)
{
	int			fd;
	static	char	contents_ptr[1000000];

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_putchar("Dict Error\n");
		return (0);
	}
	read(fd, &contents_ptr, 1000000);
	return (contents_ptr);
}

char	*ft_putcvt(char *contents)
{
	int		temp;
	int		cnt;
	int		index;

	temp = 0;
	cnt = 0;
	index = 0;
	if ('0' <= *contents && *contents <= '9')
		while ('0' <= *contents && *contents <= '9')
			temp = (temp * 10) + (*contents++ - 48);
	else
	{
		ft_putchar("Dict Error\n");
		return (0);
	}
	while (*contents == ' ' || *contents == ':')
		contents++;
	while (33 <= contents[cnt] && contents[cnt] <= 126)
		cnt++;
	g_convert[temp] = (char *)malloc(sizeof(char) * (cnt + 1));
	while (33 <= *contents && *contents <= 126)
		g_convert[temp][index++] = *contents++;
	g_convert[temp][index] = 0;
	return (++contents);
}

char	*ft_check_non_llion(char *contents)
{
	int		index;
	int		flag;

	index = 0;
	flag = 0;
	while ('0' <= contents[index] && contents[index] <= '9')
	{
		if (contents[index] != '0' && contents[index] != '1')
			flag = 1;
		index++;
	}
	if (flag == 1)
	{
		while (*contents != '\n')
			contents++;
		contents += 1;
	}
	return (contents);
}

char	*ft_putllion(char *contents)
{
	int zeros;
	int	index;
	int	cnt;

	zeros = 0;
	index = 0;
	cnt = 0;
	contents = ft_check_non_llion(contents);
	if (*contents == '1')
	{
		contents++;
		while (*contents++ == '0')
			zeros++;
		zeros /= 3;
		while (*contents == ' ' || *contents == ':')
			contents++;
		while (33 <= contents[cnt] && contents[cnt] <= 126)
			cnt++;
		g_llion[zeros] = (char *)malloc(sizeof(char) * (cnt + 1));
		while (33 <= *contents && *contents <= 126)
			g_llion[zeros][index++] = *contents++;
		g_llion[zeros][index] = 0;
	}
	contents += (*contents == '\0' ? 0 : 1);
	return (contents);
}

void	ft_parse_dict(char *contents)
{
	while (*contents)
	{
		if (g_convert[100] == 0)
			contents = ft_putcvt(contents);
		else
			contents = ft_putllion(contents);
	}
	g_llion[0] = "\0";
}
