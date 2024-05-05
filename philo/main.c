/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obrittne <obrittne@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:23:30 by obrittne          #+#    #+#             */
/*   Updated: 2024/04/30 15:43:59 by obrittne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "filo.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	data[5];

	if (!(argc == 5 || argc == 6))
	{
		write(2, "Error Wrong amount of Arguments\n", 32);
		return (1);
	}
	if (!validate(argc, argv, data))
	{
		write(2, "Error wrong input\n", 18);
		return (1);
	}
	if (data[4] == 0)
		return (0);
	if (!filo(data))
	{
		write(2, "Error filosophers\n", 18);
		return (1);
	}
}
