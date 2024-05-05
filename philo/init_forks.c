/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 10:46:53 by obrittne          #+#    #+#             */
/*   Updated: 2024/05/05 11:03:51 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

int	destroy_forks(t_philo *philo, int e)
{
	int	i;

	if (e == -1)
		e = philo[0].data[0];
	i = 0;
	while (i < e)
	{
		pthread_mutex_destroy(&(philo[i].fork_mutex));
		i++;
	}
	return (0);
}

int	init_forks(t_philo *philo, int *data, int *i)
{
	int	e;

	e = 0;
	*i = 0;
	while (e < data[0])
	{
		if (pthread_mutex_init(&(philo[e].fork_mutex), NULL))
		{
			destroy_forks(philo, e);
			return (0);
		}
		philo[e].data = data;
		philo[e].initialized = 0;
		e++;
	}
	return (1);
}
