/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 00:19:37 by hyeokim           #+#    #+#             */
/*   Updated: 2021/04/14 15:43:15 by hyeokim          ###   ########.fr       */
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
	// sem_post(philos->table->write_msg);
	// sem_wait(philos->table->write_msg);
	// printf("All process killed\n");
	// sem_post(philos->table->write_msg);
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