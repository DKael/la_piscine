/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanghlee <kanghlee@student.42.seoul>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:37:57 by kanghlee          #+#    #+#             */
/*   Updated: 2022/10/09 21:37:59 by kanghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "rush01.h"

int	row_check(t_sky *square, int size, int index)
{
	int	row;
	int	row_index;

	row = index / size;
	row_index = row * size;
	while (row_index < (row + 1) * size)
	{
		if (row_index == index)
		{
			row_index++;
			continue ;
		}	
		else
			if (square[row_index].ok == square[index].ok)
				return (0);
		row_index++;
	}
	return (1);
}

int	col_check(t_sky *square, int size, int index)
{
	int	col;
	int	row_index;

	col = index % size;
	row_index = 0;
	while (row_index < size)
	{
		if (row_index * size + col == index)
		{
			row_index++;
			continue ;
		}
		else
			if (square[row_index * size + col].ok == square[index].ok)
				return (0);
		row_index++;
	}
	return (1);
}
