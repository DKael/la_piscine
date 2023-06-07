/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanghlee <kanghlee@student.42.seoul>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:39:02 by kanghlee          #+#    #+#             */
/*   Updated: 2022/10/09 21:39:04 by kanghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "rush01.h"

void	print_square(t_sky *square, int size)
{
	int		index;
	int		total_size;
	char	output;

	index = 0;
	total_size = size * size;
	while (index < total_size)
	{
		output = square[index].ok + '0';
		write(1, &output, 1);
		if (index != total_size - 1 && !(index % size == size - 1))
			write(1, " ", 1);
		if (index % size == size - 1)
			write(1, "\n", 1);
		index++;
	}
}

void	free_all(t_sky *square, int *clue)
{
	free(square);
	free(clue);
}
