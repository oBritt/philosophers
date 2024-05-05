/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_super.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 10:21:59 by obrittne          #+#    #+#             */
/*   Updated: 2024/05/05 12:48:13 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

void	init_super(t_supervisor *super, int *data)
{
	super->data = data;
	super->mode = data[0] % 2 + 2;
	super->cycle = 0;
	super->initialized = 0;
	super->dead = 0;
	super->amount = 0;
	super->counter = 0;
}
