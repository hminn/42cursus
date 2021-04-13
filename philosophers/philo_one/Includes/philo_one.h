/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:11:02 by hyeokim           #+#    #+#             */
/*   Updated: 2021/04/13 14:05:40 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H
# define TAKEN_FORK	0
# define EATING		1
# define SLEEPING	2
# define THINKING	3
# define DEAD		4

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct		s_table
{
	int				nbr_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_eat;
	int				total_eat;
	int				is_dead;
	unsigned long	base_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	write_msg;
	pthread_mutex_t	m_eat;
	pthread_mutex_t	m_dead;
}					t_table;

typedef struct		s_philo
{
	int				nbr;
	int				fork_r;
	int				fork_l;
	int				cnt_eat;
	unsigned long	last_meal;
	pthread_t		tid;
	t_table			*table;
}					t_philo;

int					ft_result(const char *str);
int					ft_atoi(const char *str);
int					put_error(char *str);
int					parsing(t_table *table, int argc, char *argv[]);
int					msg(t_philo *philo, int msg, unsigned long current_time);
int					someone_dead(t_philo *philo, unsigned long current_time);
int					fully_eat(t_philo *philo);
unsigned long		get_time(void);
void				*philo_act(void *p);
void				*philo_monitor(void *p);
int					eat(t_philo *philo);
void				vsleep(unsigned long itime);
void				clean_table(t_table *table, t_philo *philos);
void				init_philo(t_philo *philos);
int					init_table(t_table *table, t_philo *philos);
void				assign_fork(t_philo *philo, int idx);
# endif
