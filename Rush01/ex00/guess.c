/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guess.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanghlee <kanghlee@student.42.seoul>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:38:35 by kanghlee          #+#    #+#             */
/*   Updated: 2022/10/09 21:38:37 by kanghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "rush01.h"

int	guess(t_sky *square, int size, int *clue, int index)
{
	int	input;

	if (index == size * size)
		return (1);
	if (square[index].ko == 0)
	{
		if (guess(square, size, clue, index + 1) == 1)
			return (1);
		return (0);
	}
	else
	{
		input = 0;
		while (++input <= size)
		{
			square[index].ok = input;
			if (validation(square, size, clue, index) == 0)
				continue ;
			if (guess(square, size, clue, index + 1) == 1)
				return (1);
		}
	}
	square[index].ok = 0;
	return (0);
}

int	validation(t_sky *square, int size, int *clue, int index)
{
	if (row_check(square, size, index) == 0)
		return (0);
	if (col_check(square, size, index) == 0)
		return (0);
	if (row_clue_check(square, size, clue, index) == 0)
		return (0);
	if (col_clue_check(square, size, clue, index) == 0)
		return (0);
	return (1);
}
