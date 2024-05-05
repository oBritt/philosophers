/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:47:25 by obrittne          #+#    #+#             */
/*   Updated: 2024/04/15 14:18:52 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

void	copy(int *dest, int *src, int additon)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = additon;
}

int	get_ind(int ind, int amount)
{
	return ((ind + 1) % amount);
}
