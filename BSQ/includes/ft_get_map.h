/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:16:12 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/19 12:16:12 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_GET_MAP_H
# define FT_GET_MAP_H

# include <stdlib.h>
# include <fcntl.h>
# include "ft_data.h"
# include "ft_string.h"
# include "ft_get_map1.h"

char	**ft_get_map(char *file_name, t_loc_data *loc, t_map_c *figure);
char	**ft_make_map(int fd, t_loc_data *loc, t_map_c *figure);
char	**ft_make_map1(int fd, t_loc_data *loc, t_map_c *figure, char **result);
int		ft_check_line(char l[], int size, t_map_c *figure);
char	**ft_free(char **result, t_loc_data *loc);

#endif
