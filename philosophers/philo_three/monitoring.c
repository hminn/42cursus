/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 00:19:37 by hyeokim           #+#    #+#             */
/*   Updated: 2021/04/14 17:57:43 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int			kill_process(t_philo *philos)
{
	int		i;

	i = 0;
	while (i < philos->table->nbr_philos)
	{
		kill(philos[i].pid, SIGKILL);
		i++;
	}
	return (1);
}

void		process_monitor(t_philo *philos)
{
	int		i;
	int		status;
	int		eat;

	eat = 0;
	while (1)
	{
		i = -1;
		while (++i < philos->table->nbr_philos)
		{
			status = -1;
			waitpid(philos[i].pid, &status, WNOHANG);
			if (status == 256 || status == 0)
			{
				if (status == 0)
					if (++eat != philos->table->nbr_philos)
						continue;
				break ;
			}
		}
		if (status == 256 || eat == philos->table->nbr_philos)
			if (kill_process(philos))
				break ;
	}
}
