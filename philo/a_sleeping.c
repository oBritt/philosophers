/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_sleeping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:41:53 by obrittne          #+#    #+#             */
/*   Updated: 2024/05/05 20:13:21 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

int	print_sleep(t_philo *philo, int ind, pthread_mutex_t *mutexes, \
t_supervisor *super)
{
	if (check_if_dead(philo, ind, mutexes, super))
		return (1);
	pthread_mutex_lock(&mutexes[1]);
	pthread_mutex_lock(&mutexes[2]);
	print(get_time(), ind, 3, super->dead);
	pthread_mutex_unlock(&mutexes[2]);
	pthread_mutex_unlock(&mutexes[1]);
	return (0);
}

int	print_thinking(t_philo *philo, int ind, pthread_mutex_t *mutexes, \
t_supervisor *super)
{
	if (check_if_dead(philo, ind, mutexes, super))
		return (1);
	pthread_mutex_lock(&mutexes[1]);
	pthread_mutex_lock(&mutexes[2]);
	print(get_time(), ind, 4, super->dead);
	pthread_mutex_unlock(&mutexes[2]);
	pthread_mutex_unlock(&mutexes[1]);
	return (0);
}

int	sleeping(t_philo *philo, int ind, pthread_mutex_t *mutexes, \
t_supervisor *super)
{
	long long	start_time;
	int			*data;

	super += 0;
	data = philo->data;
	if (print_sleep(philo, ind, mutexes, super))
		return (1);
	start_time = get_time();
	while (start_time + data[3] > get_time())
	{
		if (check_if_dead(philo, ind, mutexes, super))
			return (1);
		usleep(250);
	}
	if (print_thinking(philo, ind, mutexes, super))
		return (1);
	return (0);
}
