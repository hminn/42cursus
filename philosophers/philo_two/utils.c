/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:19:05 by hyeokim           #+#    #+#             */
/*   Updated: 2021/04/13 18:51:45 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int				ft_result(const char *str)
{
	int				result;

	result = 0;
	if ('0' <= *str && *str <= '9')
	{
		while ('0' <= *str && *str <= '9')
			result = ((result * 10) + (*str++ - 48));
		return (result);
	}
	return (-1);
}

int				ft_atoi(const char *str)
{
	int				result;
	int				sign;

	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		sign *= (*str++ == '-' ? -1 : 1);
	result = ft_result(str);
	if (result == -1 || sign == -1)
		return (-1);
	return (result);
}

unsigned long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void			vsleep(unsigned long itime)
{
	unsigned long	stime;
	unsigned long	ctime;

	stime = get_time();
	while (1)
	{
		ctime = get_time();
		if (ctime - stime > itime)
			return ;
		usleep(100);
	}
}
