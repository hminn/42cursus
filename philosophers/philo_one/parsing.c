/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:44:18 by hyeokim           #+#    #+#             */
/*   Updated: 2021/04/12 16:44:43 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		parsing(t_table *table, int argc, char *argv[])
{
	int		i;

	i = 1;
	table->nbr_eat = -1;
	while (i < argc)
	{
		if (i == 1 && (table->nbr_philos = ft_atoi(argv[i])) == -1)
			return (1);
		if (i == 2 && (table->time_to_die = ft_atoi(argv[i])) == -1)
			return (1);
		if (i == 3 && (table->time_to_eat = ft_atoi(argv[i])) == -1)
			return (1);
		if (i == 4 && (table->time_to_sleep = ft_atoi(argv[i])) == -1)
			return (1);
		if (i == 5 && (table->nbr_eat = ft_atoi(argv[i])) == -1)
			return (1);
		i++;
	}
	return (0);
}