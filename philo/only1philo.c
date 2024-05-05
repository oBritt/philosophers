/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only1philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:09:06 by obrittne          #+#    #+#             */
/*   Updated: 2024/04/30 18:41:20 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

void	*execute(void *arg)
{
	t_send			*s;
	t_philo			*phi;
	pthread_mutex_t	*output;
	int				*data;

	s = (t_send *)arg;
	phi = s->philo;
	data = phi->data;
	output = s->mutexes;
	pthread_mutex_lock(&(phi->fork_mutex));
	pthread_mutex_lock(output);
	print(get_time(), 1, 1);
	pthread_mutex_unlock(output);
	usleep(data[1] * 1000);
	pthread_mutex_lock(output);
	print(get_time(), 1, 5);
	pthread_mutex_unlock(output);
	pthread_mutex_unlock(&(phi->fork_mutex));
	return (NULL);
}

int	destroy_2_mutex(pthread_mutex_t *a, pthread_mutex_t *b)
{
	pthread_mutex_destroy(a);
	pthread_mutex_destroy(b);
	return (0);
}

int	philo_solo_warrior(int *data)
{
	t_philo			phi;
	t_send			send;
	pthread_mutex_t	output;

	if (pthread_mutex_init(&output, NULL))
		return (0);
	if (pthread_mutex_init(&phi.fork_mutex, NULL))
	{
		pthread_mutex_destroy(&output);
		return (0);
	}
	phi.data = data;
	send.mutexes = &output;
	send.philo = &phi;
	if (pthread_create(&phi.thread, NULL, &execute, &send))
		return (destroy_2_mutex(&phi.fork_mutex, &output));
	if (pthread_join(phi.thread, NULL))
		return (destroy_2_mutex(&phi.fork_mutex, &output));
	pthread_mutex_destroy(&phi.fork_mutex);
	pthread_mutex_destroy(&output);
	return (1);
}
