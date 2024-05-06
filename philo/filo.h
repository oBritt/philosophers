/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:27:28 by obrittne          #+#    #+#             */
/*   Updated: 2024/05/05 19:58:48 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILO_H
# define FILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				*data;
	long long		last_eat;
	pthread_mutex_t	fork_mutex;
	int				fork_locked;
	pthread_t		thread;
	int				error;
	int				amount;
	int				initialized;
	int				died;
}	t_philo;

typedef struct s_supervisor
{
	int				*data;
	int				amount;
	int				cycle;
	int				dead;
	int				initialized;
	int				mode;
	int				counter;
}	t_supervisor;

typedef struct s_send
{
	t_philo			*philo;
	int				ind;
	pthread_mutex_t	*mutexes;
	t_supervisor	*super;
}	t_send;

# define NUMBER_OF_MUTEX 3

int			validate(int args, char **argv, int *data);
int			filo(int *data);
long long	get_time(void);
void		copy(int *dest, int *src, int additon);
int			get_ind(int ind, int amount);
void		print(long long stamp, int id, int action, int dead);
int			init_mutexes(pthread_mutex_t *mutexes);
int			destroy_all_mutexes(pthread_mutex_t *mutexes, int i);
int			philo_solo_warrior(int *data);
void		init_super(t_supervisor *super, int *data);
void		wait_for_all_threads(t_philo *philo, int ind, \
pthread_mutex_t *mutexes, t_supervisor *super);
void		init_send(t_send *send, t_philo *philo, t_supervisor *super, \
pthread_mutex_t *mutexes);
int			init_forks(t_philo *philo, int *data, int *i);
int			destroy_forks(t_philo *philo, int e);
void		loop(t_philo *philo, int ind, pthread_mutex_t *mutexes, \
t_supervisor *super);
int			grab_fork(t_philo *philo, int ind, pthread_mutex_t *mutexes, \
t_supervisor *super);
int			eat(t_philo *philo, int ind, pthread_mutex_t *mutexes, \
t_supervisor *super);
int			sleeping(t_philo *philo, int ind, pthread_mutex_t *mutexes, \
t_supervisor *super);
int			check_if_dead(t_philo *philo, int ind, pthread_mutex_t *mutexes, \
t_supervisor *super);
#endif