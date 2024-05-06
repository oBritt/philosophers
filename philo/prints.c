/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:51:41 by obrittne          #+#    #+#             */
/*   Updated: 2024/05/05 18:53:15 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

void	put_nbr_h(long long stamp)
{
	char	t;

	if (stamp)
	{
		t = stamp % 10 + '0';
		put_nbr_h(stamp / 10);
		write(1, &t, 1);
	}
}

void	put_nbr(long long stamp)
{
	if (stamp <= 0)
		write(1, "0", 1);
	else
		put_nbr_h(stamp);
}

void	print(long long stamp, int id, int action, int dead)
{
	static int			first = 1;
	static long long	start = 0;

	if (first == 1)
	{
		first = 0;
		start = get_time();
	}
	if (dead == 1)
		return ;
	put_nbr(stamp - start);
	write(1, " ", 1);
	put_nbr((long long) id + 1);
	if (action == 1)
		write(1, " has taken a fork\n", 18);
	if (action == 2)
		write(1, " is eating\n", 11);
	if (action == 3)
		write(1, " is sleeping\n", 13);
	if (action == 4)
		write(1, " is thinking\n", 13);
	if (action == 5)
		write(1, " died\n", 6);
}
