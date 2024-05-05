/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:15:46 by obrittne          #+#    #+#             */
/*   Updated: 2024/05/05 11:01:02 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

void	*stuff(void *arg)
{
	t_philo			*philo;
	int				ind;
	pthread_mutex_t	*mutexes;
	t_supervisor	*super;

	philo = ((t_send *)arg)->philo;
	ind = ((t_send *)arg)->ind;
	mutexes = ((t_send *)arg)->mutexes;
	super = ((t_send *) arg)->super;
	free(arg);
	wait_for_all_threads(philo, ind, mutexes, super);
	loop(philo, ind, mutexes, super);
	return (NULL);
}

int	wait_to_finish(t_philo *philo, int *data, int error)
{
	int	amount;
	int	i;
	int	ans;

	i = 0;
	ans = 1;
	amount = data[0];
	if (error != -1)
	{
		amount = error;
		ans = 0;
	}
	while (i < amount)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	destroy_forks(philo, -1);
	return (ans);
}

int	init_philosophers(t_philo *philo, pthread_mutex_t *mutexes, \
t_supervisor *super, int *data)
{
	int		i;
	t_send	*send;
	int		error;

	error = -1;
	if (!init_forks(philo, data, &i))
		return (0);
	while (i < data[0])
	{
		send = malloc(sizeof(t_send));
		if (!send)
		{
			error = i;
			break ;
		}
		send->ind = i;
		init_send(send, philo, super, mutexes);
		if (pthread_create(&philo[i].thread, NULL, stuff, send))
		{
			error = i;
			break ;
		}
		i++;
	}
	return (wait_to_finish(philo, data, error));
}

// mutex 1 - output  2 - dead 3 - taken untaken fork
int	filo(int *data)
{
	t_philo			*philosophers;
	pthread_mutex_t	mutexes[NUMBER_OF_MUTEX];
	t_supervisor	super;

	if (data[0] == 1)
		return (philo_solo_warrior(data));
	init_super(&super, data);
	philosophers = malloc((data[0]) * sizeof(t_philo));
	if (!philosophers)
		return (0);
	if (!init_mutexes(mutexes))
	{
		free(philosophers);
		return (0);
	}
	if (!init_philosophers(philosophers, mutexes, &super, data))
	{
		destroy_all_mutexes(mutexes, -1);
		free(philosophers);
		return (0);
	}
	free(philosophers);
	destroy_all_mutexes(mutexes, -1);
	return (1);
}
