/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeokim <hyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 10:47:49 by hyeokim           #+#    #+#             */
/*   Updated: 2021/04/14 17:57:30 by hyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H
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
# include <semaphore.h>
# include <signal.h>

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
	sem_t			*enter;
	sem_t			*fork;
	sem_t			*write_msg;
	sem_t			*m_eat;
	sem_t			*m_dead;
}					t_table;

typedef struct		s_philo
{
	int				nbr;
	int				fork_r;
	int				fork_l;
	int				cnt_eat;
	unsigned long	last_meal;
	pid_t			pid;
	t_table			*table;
}					t_philo;

int					parsing(t_table *table, int argc, char *argv[]);
int					put_error(char *str);
int					msg(t_philo *philo, int msg, unsigned long current_time);
int					ft_result(const char *str);
int					ft_atoi(const char *str);
unsigned long		get_time(void);
void				vsleep(unsigned long itime);
void				close_sem(t_table *table);
void				*philo_act(void *p);
void				*philo_monitor(void *p);
int					eat(t_philo *philo);
void				init_philo(t_philo *philos);
void				clear_sem(void);
void				init_sem(t_table *table);
int					init_table(t_table *table, t_philo *philos);
int					kill_process(t_philo *philos);
void				process_monitor(t_philo *philos);
#endif
