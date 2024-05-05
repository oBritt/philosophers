/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:28:47 by obrittne          #+#    #+#             */
/*   Updated: 2024/04/11 15:17:11 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filo.h"

int	check_chars(char *str)
{
	int	it;

	it = 0;
	while (str[it])
	{
		if (!(str[it] >= '0' && str[it] <= '9'))
			return (0);
		it++;
	}
	return (1);
}

int	is_int(char *str, int *num)
{
	int			it;
	long long	out;

	out = 0;
	it = 0;
	while (str[it])
		it++;
	if (it > 14 || it == 0)
		return (0);
	it = 0;
	while (str[it])
	{
		out = out * 10 + str[it] - '0';
		it++;
	}
	if (out > 2147483647)
		return (0);
	*num = (int)out;
	return (1);
}

int	validate(int args, char **argv, int *data)
{
	int	it;

	data[4] = -1;
	it = 1;
	while (it < args)
	{
		if (!check_chars(argv[it]))
			return (0);
		it++;
	}
	it = 0;
	while (it < args - 1)
	{
		if (!is_int(argv[it + 1], &(data[it])))
			return (0);
		it++;
	}
	return (1);
}
