/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 09:08:35 by obrittne          #+#    #+#             */
/*   Updated: 2024/05/05 10:20:09 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

int	destroy_all_mutexes(pthread_mutex_t *mutexes, int i)
{
	int	e;

	e = 0;
	if (i == -1)
		i = NUMBER_OF_MUTEX;
	while (e < i)
	{
		pthread_mutex_destroy(&mutexes[e]);
		e++;
	}
	return (0);
}

int	init_mutexes(pthread_mutex_t *mutexes)
{
	int	i;

	i = 0;
	while (i < NUMBER_OF_MUTEX)
	{
		if (pthread_mutex_init(&mutexes[i], NULL))
		{
			destroy_all_mutexes(mutexes, i);
			return (0);
		}
		i++;
	}
	return (1);
}
