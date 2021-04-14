/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 00:19:37 by hyeokim           #+#    #+#             */
/*   Updated: 2021/04/14 10:44:14 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		someone_dead(t_philo *philo, unsigned long current_time)
{
	unsigned long	time_to_die;

	sem_wait(philo->table->m_dead);
	time_to_die = (unsigned long)philo->table->time_to_die;
	if (philo->table->is_dead > 0 ||
		current_time - philo->last_meal > time_to_die)
	{
		sem_post(philo->table->m_dead);
		return (1);
	}
	sem_post(philo->table->m_dead);
	return (0);
}

int		fully_eat(t_philo *philo)
{
	if (philo->table->nbr_eat == -1)
		return (0);
	sem_wait(philo->table->m_eat);
	if (philo->table->total_eat == philo->table->nbr_philos)
	{
		sem_post(philo->table->m_eat);
		return (1);
	}
	sem_post(philo->table->m_eat);
	return (0);
}
