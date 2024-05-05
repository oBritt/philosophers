/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:07:22 by obrittne          #+#    #+#             */
/*   Updated: 2024/05/05 14:20:24 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

int	take_forks(t_philo *philo, int ind, pthread_mutex_t *mutexes, \
t_supervisor *super)
{
	if (check_if_dead(philo, mutexes, super))
		return (1);
	pthread_mutex_lock(&philo[ind].fork_mutex);
	pthread_mutex_lock(&mutexes[1]);
	print(get_time(), ind, 1);
	pthread_mutex_unlock(&mutexes[1]);
	pthread_mutex_lock(&philo[get_ind(ind, philo[0].data[0])].fork_mutex);
	pthread_mutex_lock(&mutexes[1]);
	print(get_time(), ind, 1);
	pthread_mutex_unlock(&mutexes[1]);
	return (0);
}

int	grab_fork(t_philo *philo, int ind, pthread_mutex_t *mutexes, \
t_supervisor *super)
{
	while (1)
	{
		if (check_if_dead(philo, mutexes, super))
			return (1);
		pthread_mutex_lock(&mutexes[0]);
		if (super->data[0] % 2 && ind == super->data[0] - 1)
		{
			if (super->cycle == 2)
				break ;
		}
		else if (ind % 2 == 1)
		{
			if (super->cycle == 1)
				break ;
		}
		else
		{
			if (super->cycle == 0)
				break ;
		}
		pthread_mutex_unlock(&mutexes[0]);
		usleep(10);
	}
	pthread_mutex_unlock(&mutexes[0]);
	return (take_forks(philo, ind, mutexes, super));
}
