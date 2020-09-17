/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:14:35 by hyeokim           #+#    #+#             */
/*   Updated: 2020/03/11 18:45:02 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		ret;
	long long	buf;

	buf = n;
	if (0 <= buf && buf <= 9)
	{
		ret = '0' + buf;
		write(fd, &ret, 1);
	}
	else if (10 <= buf)
	{
		ft_putnbr_fd(buf / 10, fd);
		ret = '0' + (buf % 10);
		write(fd, &ret, 1);
	}
	else
	{
		write(fd, "-", 1);
		buf = buf * -1;
		ret = '0' + (buf % 10);
		if (buf / 10 != 0)
			ft_putnbr_fd(buf / 10, fd);
		write(fd, &ret, 1);
	}
}
