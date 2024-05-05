/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiting_for_all_threads.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 09:42:49 by obrittne          #+#    #+#             */
/*   Updated: 2024/05/05 10:33:32 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

int	check_if_all(t_philo *philo, pthread_mutex_t *mutexes, t_supervisor *super)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&mutexes[0]);
	if (super->initialized == 1)
	{
		pthread_mutex_unlock(&mutexes[0]);
		return (1);
	}
	while (i < philo[0].data[0])
	{
		if (philo[i].initialized != 1)
		{
			pthread_mutex_unlock(&mutexes[0]);
			return (0);
		}
		i++;
	}
	pthread_mutex_unlock(&mutexes[0]);
	return (1);
}

void	set_time(t_philo *philo)
{
	long long	time;
	int			i;

	time = get_time();
	i = 0;
	while (i < philo[0].data[0])
	{
		philo[i].last_eat = time;
		i++;
	}
}

void	wait_for_all_threads(t_philo *philo, int ind, \
pthread_mutex_t *mutexes, t_supervisor *super)
{
	pthread_mutex_lock(&mutexes[0]);
	philo[ind].initialized = 1;
	pthread_mutex_unlock(&mutexes[0]);
	while (1)
	{
		if (check_if_all(philo, mutexes, super))
			break ;
		usleep(10);
	}
	pthread_mutex_lock(&mutexes[0]);
	if (super->initialized)
	{
		pthread_mutex_unlock(&mutexes[0]);
		return ;
	}
	set_time(philo);
	super->initialized = 1;
	pthread_mutex_unlock(&mutexes[0]);
}
