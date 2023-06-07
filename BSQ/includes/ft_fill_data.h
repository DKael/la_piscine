/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:22:13 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/19 11:22:14 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_FILL_DATA_H
# define FT_FILL_DATA_H

# include <stdlib.h>
# include "ft_data.h"
# include "ft_get_map1.h"

int		**ft_fill_data(t_loc_data loc, char **map, t_map_c figure);
void	fill(t_loc_data loc, char **map, int **data, t_map_c info);
int		ft_min(t_loc_data loc, int **data);

#endif