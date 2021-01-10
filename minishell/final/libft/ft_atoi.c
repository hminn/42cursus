/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 22:37:11 by hyeokim           #+#    #+#             */
/*   Updated: 2020/03/03 16:56:55 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_result(const char *str)
{
	int result;

	result = 0;
	if ('0' <= *str && *str <= '9')
	{
		while ('0' <= *str && *str <= '9')
			result = ((result * 10) + (*str++ - 48));
		return (result);
	}
	return (0);
}

int		ft_atoi(const char *str)
{
	int		result;
	int		sign;

	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		sign *= (*str++ == '-' ? -1 : 1);
	result = ft_result(str);
	return (result * sign);
}
