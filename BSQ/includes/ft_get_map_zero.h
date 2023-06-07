/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_zero.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 01:17:16 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/20 01:17:17 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_GET_MAP_ZERO_H
# define FT_GET_MAP_ZERO_H

# include <stdlib.h>
# include <fcntl.h>
# include "ft_data.h"
# include "ft_string.h"
# include "ft_get_map.h"
# include "ft_get_map1.h"

char	**ft_get_map_zero(t_loc_data *loc, t_map_c *figure);
char	**ft_make_map_zero(t_loc_data *loc, t_map_c *figure);
char	**ft_make_map1_zero(t_loc_data *loc, t_map_c *figure, char **result);
char	**ft_map_tail_chk_zero(t_loc_data *loc, char **result, int r_i);

#endif