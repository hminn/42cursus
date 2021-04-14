/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:06:57 by hyeokim           #+#    #+#             */
/*   Updated: 2021/04/14 17:56:51 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		main(int argc, char *argv[])
{
	t_table		table;
	t_philo		*philos;

	if (!(argc == 5 || argc == 6))
		return (put_error("Error: Invalid arguments\n"));
	if (parsing(&table, argc, argv))
		return (put_error("Error: Invalid arguments\n"));
	if (!(philos = (t_philo *)malloc(sizeof(t_philo) * table.nbr_philos)))
		return (put_error("Error: Allocation failed\n"));
	init_table(&table, philos);
	clean_table(&table, philos);
}
