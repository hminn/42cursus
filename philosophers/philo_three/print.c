/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:50:54 by hyeokim           #+#    #+#             */
/*   Updated: 2021/04/14 17:57:55 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int		msg(t_philo *philo, int msg, unsigned long current_time)
{
	t_table		*table;

	table = philo->table;
	sem_wait(table->write_msg);
	if (table->is_dead)
	{
		sem_post(table->write_msg);
		return (1);
	}
	printf("%lums %d", current_time - table->base_time, philo->nbr);
	if (msg == DEAD)
	{
		printf(" has died\n");
		return (1);
	}
	if (msg == EATING)
	{
		printf(" is eating\n");
		philo->last_meal = current_time;
	}
	msg == TAKEN_FORK ? printf(" has taken a fork\n") : 0;
	msg == SLEEPING ? printf(" is sleeping\n") : 0;
	msg == THINKING ? printf(" is thinking\n") : 0;
	sem_post(table->write_msg);
	return (0);
}

int		put_error(char *str)
{
	printf("%s", str);
	return (1);
}
