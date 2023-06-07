/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map1.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:02:42 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/19 20:02:45 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_GET_MAP1_H
# define FT_GET_MAP1_H

# include "ft_data.h"
# include "ft_get_map.h"

int		**ft_free_int(int **result, t_loc_data *loc);
int		ft_figure_make(t_map_c *figure, char full, char obs, char empty);
char	**ft_map_tail_check(int fd, t_loc_data *loc, char **result);
char	**ft_make_first_line(t_loc_data *loc);
char	**ft_free1(int r_index, char **result, t_loc_data *loc);

#endif
