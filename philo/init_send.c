/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_send.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 10:36:55 by obrittne          #+#    #+#             */
/*   Updated: 2024/05/05 10:40:21 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

void	init_send(t_send *send, t_philo *philo, t_supervisor *super, \
pthread_mutex_t *mutexes)
{
	send->mutexes = mutexes;
	send->philo = philo;
	send->super = super;
}
