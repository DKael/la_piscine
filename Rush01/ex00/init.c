/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanghlee <kanghlee@student.42.seoul>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:38:43 by kanghlee          #+#    #+#             */
/*   Updated: 2022/10/09 21:38:44 by kanghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "rush01.h"

int	*ft_arg_split(char *pri_clue, int *size)
{
	int	index;
	int	*clue;

	*size = get_size(pri_clue);
	if (*size == 0)
		return (0);
	clue = (int *)malloc(sizeof(int) * (*size) * (*size));
	index = 0;
	while (pri_clue[index] != '\0')
	{
		if (index % 2 == 0 && ('0' <= pri_clue[index] && pri_clue[index] < '9'))
		{
			clue[index / 2] = pri_clue[index] - '0';
			index++;
		}
		else if (index % 2 == 1 && pri_clue[index] == ' ')
			index++;
		else
		{
			*size = 0;
			return (0);
		}
	}
	return (clue);
}

int	get_size(char *pri_clue)
{
	int	index;

	index = 0;
	while (pri_clue[index] != '\0')
		index++;
	if (((index + 1) / 2) % 4 != 0)
		return (0);
	return (((index + 1) / 2) / 4);
}

void	init_square(t_sky *square, int size)
{
	int	iter;
	int	total_size;

	total_size = size * size;
	iter = 0;
	while (iter < total_size)
	{
		square[iter].ko = 1;
		iter++;
	}
}
