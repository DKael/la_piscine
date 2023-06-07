/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:55:12 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/19 10:55:13 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fill_data.h"

int	**ft_fill_data(t_loc_data loc, char **map, t_map_c figure)
{
	int	index;
	int	**data;

	data = (int **)malloc(sizeof(int *) * loc.row);
	if (data == NULL)
		return (0);
	index = -1;
	while (++index < loc.row)
	{
		data[index] = (int *)malloc(sizeof(int) * loc.col);
		if (data[index] == NULL)
		{
			loc.row = index + 1;
			return (ft_free_int(data, &loc));
		}
	}
	loc.c_row = -1;
	while (++(loc.c_row) < loc.row)
	{
		loc.c_col = -1;
		while (++(loc.c_col) < loc.col)
			fill(loc, map, data, figure);
	}
	return (data);
}

void	fill(t_loc_data loc, char **map, int **data, t_map_c info)
{
	if (map[loc.c_row][loc.c_col] == info.obstacle)
		data[loc.c_row][loc.c_col] = 0;
	else
	{
		if (loc.c_row != 0 && loc.c_col != 0)
		{
			data[loc.c_row][loc.c_col] = ft_min(loc, data) + 1;
		}
		else if (loc.c_row == 0 || loc.c_col == 0)
			data[loc.c_row][loc.c_col] = 1;
	}
}

int	ft_min(t_loc_data loc, int **data)
{
	int	num[3];
	int	min;
	int	index;

	num[0] = data[loc.c_row][loc.c_col - 1];
	num[1] = data[loc.c_row - 1][loc.c_col];
	num[2] = data[loc.c_row - 1][loc.c_col - 1];
	index = 1;
	min = num[0];
	while (index < 3)
	{
		if (min > num[index])
			min = num[index];
		index++;
	}
	return (min);
}
