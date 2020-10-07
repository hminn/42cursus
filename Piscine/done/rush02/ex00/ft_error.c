/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:17:45 by hyeokim           #+#    #+#             */
/*   Updated: 2020/02/09 22:40:35 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_non_number(char *str)
{
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
		{
			ft_putchar("Error\n");
			return (1);
		}
		str++;
	}
	return (0);
}

int		ft_error(int argc, char *argv[])
{
	if (argc > 3)
	{
		ft_putchar("Error\n");
		return (1);
	}
	else if (argc == 3 || argc == 2)
	{
		if (argc == 3)
		{
			if (ft_read_dict(argv[1]) == 0)
				return (1);
			if (ft_non_number(argv[2]))
				return (1);
		}
		else if (argc == 2)
		{
			if (ft_non_number(argv[1]))
				return (1);
			if (ft_read_dict("numbers.dict.txt") == 0)
				return (1);
		}
	}
	else
		return (1);
	return (0);
}
