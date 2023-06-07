/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanghlee <kanghlee@student.42.seoul>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:38:08 by kanghlee          #+#    #+#             */
/*   Updated: 2022/10/09 21:38:10 by kanghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "rush01.h"

int	col_clue_check(t_sky *square, int size, int *clue, int index)
{
	int	col;
	int	row_index;

	col = index % size;
	row_index = 0;
	while (row_index < size)
	{
		if (square[row_index * size + col].ok == 0)
			return (2);
		row_index++;
	}
	if (col_clue_check_up(square, size, clue, col) == 0
		|| col_clue_check_down(square, size, clue, col) == 0)
		return (0);
	return (1);
}

int	col_clue_check_up(t_sky *square, int size, int *clue, int col)
{
	int	highest_value;
	int	visible;
	int	row_index;

	highest_value = 0;
	visible = 0;
	row_index = 0;
	while (row_index < size)
	{
		if (square[row_index * size + col].ok > highest_value)
		{
			highest_value = square[row_index * size + col].ok;
			visible++;
		}
		row_index++;
	}
	if (visible != clue[col])
		return (0);
	return (1);
}

int	col_clue_check_down(t_sky *square, int size, int *clue, int col)
{
	int	highest_value;
	int	visible;
	int	row_index;

	highest_value = 0;
	visible = 0;
	row_index = size - 1;
	while (row_index >= 0)
	{
		if (square[row_index * size + col].ok > highest_value)
		{
			highest_value = square[row_index * size + col].ok;
			visible++;
		}
		row_index--;
	}
	if (visible != clue[size + col])
		return (0);
	return (1);
}
