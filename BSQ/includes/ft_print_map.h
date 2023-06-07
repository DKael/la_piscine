/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:22:24 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/19 11:22:25 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINT_MAP_H
# define FT_PRINT_MAP_H

# include <unistd.h>
# include "ft_data.h"

void	ft_print_map(int **map_data, char **map, t_loc_data size, t_map_c info);
int		ft_find_largest(int **map_data, t_loc_data *map_size);
void	ft_print(char **map, t_loc_data size);

#endif
