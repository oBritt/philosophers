/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_eat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:46:57 by obrittne          #+#    #+#             */
/*   Updated: 2024/05/06 14:41:52 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

int	print_eat(t_philo *philo, int ind, pthread_mutex_t *mutexes, \
t_supervisor *super)
{
	long long	last_eat;

	if (check_if_dead(philo, ind, mutexes, super))
		return (1);
	pthread_mutex_lock(&mutexes[1]);
	pthread_mutex_lock(&mutexes[2]);
	last_eat = get_time();
	print(last_eat, ind, 2, super->dead);
	philo[ind].last_eat = last_eat;
	pthread_mutex_unlock(&mutexes[2]);
	pthread_mutex_unlock(&mutexes[1]);
	if (check_if_dead(philo, ind, mutexes, super))
		return (1);
	return (0);
}

void	modify_super(pthread_mutex_t *mutexes, t_supervisor *super)
{
	pthread_mutex_lock(&mutexes[0]);
	super->amount += 1;
	if (super->cycle == 2 || super->amount == super->data[0] / 2)
	{
		super->cycle += 1;
		super->cycle %= super->mode;
		super->amount = 0;
		if (super->cycle == 0)
		{
			super->counter += 1;
			if (super->counter == super->data[4])
			{
				pthread_mutex_lock(&mutexes[2]);
				super->dead = 1;
				pthread_mutex_unlock(&mutexes[2]);
			}
		}
	}
	pthread_mutex_unlock(&mutexes[0]);
}

int	eat(t_philo *philo, int ind, pthread_mutex_t *mutexes, \
t_supervisor *super)
{
	long long	start_time;
	int			*data;

	if (check_if_dead(philo, ind, mutexes, super))
		return (1);
	data = philo->data;
	if (print_eat(philo, ind, mutexes, super))
		return (1);
	start_time = philo[ind].last_eat;
	while (start_time + data[2] > get_time())
	{
		if (check_if_dead(philo, ind, mutexes, super))
			return (1);
		usleep(250);
	}
	pthread_mutex_lock(&philo[ind].fork_mutex);
	philo[ind].fork_locked = 0;
	pthread_mutex_unlock(&philo[ind].fork_mutex);
	pthread_mutex_lock(&philo[get_ind(ind, philo[0].data[0])].fork_mutex);
	philo[get_ind(ind, philo[0].data[0])].fork_locked = 0;
	pthread_mutex_unlock(&philo[get_ind(ind, philo[0].data[0])].fork_mutex);
	modify_super(mutexes, super);
	return (0);
}
