/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 21:56:16 by hyeokim           #+#    #+#             */
/*   Updated: 2020/01/29 11:00:12 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	ft_return_hex(unsigned char str)
{
	char buf;

	if (str >= 10)
		buf = (str - 10) + 97;
	else
		buf = str + 48;
	return (buf);
}

void	ft_write(unsigned char buf)
{
	char	buf1;
	char	buf2;

	buf1 = ft_return_hex(buf / 16);
	buf2 = ft_return_hex(buf % 16);
	write(1, "\\", 1);
	write(1, &buf1, 1);
	write(1, &buf2, 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	buf;

	while (*str != '\0')
	{
		if (*str >= 32 && *str <= 126)
		{
			write(1, str, 1);
		}
		else
		{
			if (*str < 0)
			{
				buf = *str;
				ft_write(buf);
			}
			else
				ft_write(*str);
		}
		str++;
	}
}
