/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:21:24 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/20 12:35:05 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_print_map.h"

void	ft_print_map(int **map_data, char **map, t_loc_data size, t_map_c info)
{
	int	length;
	int	ri;
	int	ci;
	int	start_row;
	int	start_col;

	if (ft_find_largest(map_data, &size) == 0)
	{
		write(2, "map error\n", 10);
		return ;
	}
	length = map_data[size.c_row][size.c_col];
	start_row = size.c_row - length + 1;
	start_col = size.c_col - length + 1;
	ri = -1;
	while (++ri < length)
	{
		ci = -1;
		while (++ci < length)
			map[start_row + ri][start_col + ci] = info.full;
	}
	ft_print(map, size);
}

int	ft_find_largest(int **map_data, t_loc_data *map_size)
{
	int	ri;
	int	ci;
	int	size;
	int	temp_size;

	size = 0;
	ri = 0;
	while (ri < (*map_size).row)
	{
		ci = 0;
		while (ci < (*map_size).col)
		{	
			temp_size = map_data[ri][ci];
			if (size < temp_size)
			{
				size = temp_size;
				(*map_size).c_row = ri;
				(*map_size).c_col = ci;
			}
			ci++;
		}
		ri++;
	}
	return (size);
}

void	ft_print(char **map, t_loc_data size)
{
	int	index;

	index = 0;
	while (index < size.row)
	{
		write(1, map[index], size.col);
		write(1, "\n", 1);
		index++;
	}
	write(1, "\n", 1);
}
