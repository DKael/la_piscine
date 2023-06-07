/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:56:54 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/19 10:56:57 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_DATA_H
# define FT_DATA_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define B_SIZE 51200

typedef struct s_LOCATION_DATA
{
	int	row;
	int	col;
	int	c_row;
	int	c_col;
}	t_loc_data;

typedef struct s_MAP_CHAR
{
	char	empty;
	char	obstacle;
	char	full;
}	t_map_c;

#endif