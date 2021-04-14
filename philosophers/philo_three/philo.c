/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:53:42 by hyeokim           #+#    #+#             */
/*   Updated: 2021/04/14 17:57:51 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*philo_act(void *p)
{
	t_philo		*philo;
	pthread_t	tid;

	philo = (t_philo *)p;
	philo->last_meal = get_time();
	pthread_create(&tid, NULL, philo_monitor, philo);
	while (42)
	{
		if (eat(philo))
			break ;
		if (msg(philo, SLEEPING, get_time()))
			break ;
		vsleep(philo->table->time_to_sleep);
		if (msg(philo, THINKING, get_time()))
			break ;
	}
	pthread_join(tid, NULL);
	return (NULL);
}

void	*philo_monitor(void *p)
{
	t_philo			*philo;
	unsigned long	time_to_die;
	unsigned long	current_time;

	philo = (t_philo *)p;
	while (42)
	{
		current_time = get_time();
		if (philo->cnt_eat == philo->table->nbr_eat)
			break ;
		time_to_die = (unsigned long)philo->table->time_to_die;
		if (current_time - philo->last_meal > time_to_die)
		{
			sem_wait(philo->table->m_dead);
			if (philo->table->is_dead == 0)
			{
				msg(philo, DEAD, current_time);
				exit(1);
			}
			sem_post(philo->table->m_dead);
			return (NULL);
		}
		vsleep(1);
	}
	return (NULL);
}

int		eat(t_philo *philo)
{
	t_table		*table;

	table = philo->table;
	sem_wait(table->enter);
	sem_wait(table->fork);
	msg(philo, TAKEN_FORK, get_time());
	sem_wait(table->fork);
	msg(philo, TAKEN_FORK, get_time());
	msg(philo, EATING, get_time());
	vsleep(table->time_to_eat);
	sem_post(table->enter);
	sem_post(table->fork);
	sem_post(table->fork);
	philo->cnt_eat += 1;
	sem_wait(philo->table->m_eat);
	if (philo->cnt_eat == table->nbr_eat)
	{
		table->total_eat += 1;
		sem_post(philo->table->m_eat);
		return (1);
	}
	sem_post(philo->table->m_eat);
	return (0);
}
