/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 10:55:57 by obrittne          #+#    #+#             */
/*   Updated: 2024/05/06 14:43:38 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

void	loop(t_philo *philo, int ind, pthread_mutex_t *mutexes, \
t_supervisor *super)
{
	while (1)
	{
		if (check_if_dead(philo, ind, mutexes, super))
			return ;
		if (grab_fork(philo, ind, mutexes, super))
			return ;
		if (eat(philo, ind, mutexes, super))
			return ;
		if (sleeping(philo, ind, mutexes, super))
			return ;
		if (check_if_dead(philo, ind, mutexes, super))
			return ;
	}
}
