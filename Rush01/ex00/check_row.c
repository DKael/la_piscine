/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanghlee <kanghlee@student.42.seoul>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:38:19 by kanghlee          #+#    #+#             */
/*   Updated: 2022/10/09 21:38:21 by kanghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "rush01.h"

int	row_clue_check(t_sky *square, int size, int *clue, int index)
{
	int	row;
	int	row_index;

	row = index / size;
	row_index = row * size;
	while (row_index < (row + 1) * size)
	{
		if (square[row_index].ok == 0)
			return (2);
		row_index++;
	}
	if (row_clue_check_left(square, size, clue, row) == 0
		|| row_clue_check_right(square, size, clue, row) == 0)
		return (0);
	return (1);
}

int	row_clue_check_left(t_sky *square, int size, int *clue, int row)
{
	int	highest_value;
	int	visible;
	int	row_index;

	highest_value = 0;
	visible = 0;
	row_index = row * size;
	while (row_index < (row + 1) * size)
	{
		if (square[row_index].ok > highest_value)
		{
			highest_value = square[row_index].ok;
			visible++;
		}
		row_index++;
	}
	if (visible != clue[size * 2 + row])
		return (0);
	return (1);
}

int	row_clue_check_right(t_sky *square, int size, int *clue, int row)
{
	int	highest_value;
	int	visible;
	int	row_index;

	highest_value = 0;
	visible = 0;
	row_index = (row + 1) * size - 1;
	while (row_index > row * size)
	{
		if (square[row_index].ok > highest_value)
		{
			highest_value = square[row_index].ok;
			visible++;
		}
		row_index--;
	}
	if (visible != clue[size * 3 + row])
		return (0);
	return (1);
}
