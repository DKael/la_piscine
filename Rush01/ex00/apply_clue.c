/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_clue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanghlee <kanghlee@student.42.seoul>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:37:45 by kanghlee          #+#    #+#             */
/*   Updated: 2022/10/09 21:37:46 by kanghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "rush01.h"

void	apply_clue(t_sky *square, int size, int *clue)
{
	apply_colup_clue(square, size, clue);
	apply_coldown_clue(square, size, clue);
	apply_rowleft_clue(square, size, clue);
	apply_rowright_clue(square, size, clue);
}

void	apply_colup_clue(t_sky *square, int size, int *clue)
{
	int	index;
	int	row;

	index = 0;
	while (index < size)
	{
		if (clue[index] == 1)
		{
			square[index].ok = size;
			square[index].ko = 0;
		}
		else if (clue[index] == size)
		{
			row = 0;
			while (row < size)
			{
				square[index + (row * size)].ok = row + 1;
				square[index + (row * size)].ko = 0;
				row++;
			}
		}
		index++;
	}
}

void	apply_coldown_clue(t_sky *square, int size, int *clue)
{
	int	index;
	int	row;

	index = size;
	while (index < size * 2)
	{
		if (clue[index] == 1)
		{
			row = size - 2;
			square[row * size + index].ok = size;
			square[row * size + index].ko = 0;
		}
		else if (clue[index] == size)
		{
			row = 0;
			while (row < size)
			{
				square[(index - size) + (row * size)].ok = size - row;
				square[(index - size) + (row * size)].ko = 0;
				row++;
			}
		}
		index++;
	}
}

void	apply_rowleft_clue(t_sky *square, int size, int *clue)
{
	int	index;
	int	col;

	index = size * 2;
	while (index < size * 3)
	{
		if (clue[index] == 1)
		{
			square[(index - (size * 2)) * size].ok = size;
			square[(index - (size * 2)) * size].ko = 0;
		}
		else if (clue[index] == size)
		{
			col = 0;
			while (col < size)
			{
				square[(index - (size * 2)) * size + col].ok = col + 1;
				square[(index - (size * 2)) * size + col].ko = 0;
				col++;
			}
		}
		index++;
	}
}

void	apply_rowright_clue(t_sky *square, int size, int *clue)
{
	int	index;
	int	col;

	index = size * 3;
	while (index < size * 4)
	{
		if (clue[index] == 1)
		{
			square[(index - (size * 3)) * size + size - 1].ok = size;
			square[(index - (size * 3)) * size + size - 1].ko = 0;
		}
		else if (clue[index] == size)
		{
			col = 0;
			while (col < size)
			{
				square[(index - (size * 3)) * size + col].ok = size - col;
				square[(index - (size * 3)) * size + col].ko = 0;
				col++;
			}
		}
		index++;
	}
}
