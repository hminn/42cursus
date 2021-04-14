/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:50:54 by hyeokim           #+#    #+#             */
/*   Updated: 2021/04/14 17:58:27 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		msg(t_philo *philo, int msg, unsigned long current_time)
{
	t_table		*table;

	table = philo->table;
	sem_wait(table->write_msg);
	if ((msg != DEAD && someone_dead(philo, current_time)) ||
		fully_eat(philo))
	{
		sem_post(table->write_msg);
		return (1);
	}
	printf("%lums %d", current_time - table->base_time, philo->nbr);
	if (msg == TAKEN_FORK)
		printf(" has taken a fork\n");
	if (msg == EATING)
	{
		printf(" is eating\n");
		philo->last_meal = current_time;
	}
	msg == SLEEPING ? printf(" is sleeping\n") : 0;
	msg == THINKING ? printf(" is thinking\n") : 0;
	msg == DEAD ? printf(" has died\n") : 0;
	sem_post(table->write_msg);
	return (0);
}

int		put_error(char *str)
{
	printf("%s", str);
	return (1);
}
