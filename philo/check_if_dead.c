/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:14:07 by obrittne          #+#    #+#             */
/*   Updated: 2024/05/05 20:56:09 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

void	output_dead(int ind, pthread_mutex_t *mutexes, long long current_time)
{
	pthread_mutex_lock(&mutexes[1]);
	print(current_time, ind, 5, 0);
	pthread_mutex_unlock(&mutexes[1]);
}

int	check_if_dead(t_philo *philo, int ind, pthread_mutex_t *mutexes, \
t_supervisor *super)
{
	long long	current_time;

	current_time = get_time();
	pthread_mutex_lock(&mutexes[2]);
	if (super->dead == 1)
	{
		pthread_mutex_unlock(&mutexes[2]);
		return (1);
	}
	if (current_time > philo[ind].last_eat + super->data[1])
	{
		super->dead = 1;
		pthread_mutex_unlock(&mutexes[2]);
		output_dead(ind, mutexes, current_time);
		return (1);
	}
	pthread_mutex_unlock(&mutexes[2]);
	return (0);
}
