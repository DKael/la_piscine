/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:06:03 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/19 20:06:05 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_data.h"
#include "ft_fill_data.h"
#include "ft_get_map_zero.h"
#include "ft_get_map.h"
#include "ft_get_map1.h"
#include "ft_print_map.h"
#include "ft_string.h"

void	ft_arg(int argc, char **argv, t_loc_data *loc, t_map_c *figure);
void	ft_arg_zero(t_loc_data *loc, t_map_c *figure);

int	main(int argc, char *argv[])
{
	t_map_c		figure;
	t_loc_data	loc;

	if (argc == 1)
		ft_arg_zero(&loc, &figure);
	else
		ft_arg(argc, argv, &loc, &figure);
	return (0);
}

void	ft_arg(int argc, char **argv, t_loc_data *loc, t_map_c *figure)
{
	int		index;
	int		**map_data;
	char	**map;

	index = 0;
	while (++index < argc)
	{
		map = ft_get_map(argv[index], loc, figure);
		if (map == 0)
		{
			write(2, "map error\n", 10);
			continue ;
		}
		map_data = ft_fill_data(*loc, map, *figure);
		if (map_data == 0)
		{
			write(2, "map error\n", 10);
			continue ;
		}
		ft_print_map(map_data, map, *loc, *figure);
		ft_free_int(map_data, loc);
		ft_free(map, loc);
	}
}

void	ft_arg_zero(t_loc_data *loc, t_map_c *figure)
{
	char	**map;
	int		**map_data;

	map = ft_get_map_zero(loc, figure);
	if (map == 0)
	{
		write(2, "map error\n", 10);
		return ;
	}
	map_data = ft_fill_data(*loc, map, *figure);
	if (map_data == 0)
	{
		write(2, "map error\n", 10);
		return ;
	}
	ft_print_map(map_data, map, *loc, *figure);
	ft_free_int(map_data, loc);
	ft_free(map, loc);
}
