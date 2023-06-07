/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_zero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 01:17:06 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/20 01:17:08 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_get_map_zero.h"

char	**ft_get_map_zero(t_loc_data *loc, t_map_c *figure)
{
	int		r_count;
	char	buf[20];

	r_count = read(0, buf, 20);
	if (r_count >= 20 || r_count <= 3)
		return (0);
	if (ft_figure_make(figure, buf[r_count - 2]
			, buf[r_count - 3], buf[r_count - 4]) == 0)
		return (0);
	buf[r_count - 4] = '\0';
	loc->row = ft_atoi(buf);
	if (loc->row == 0)
		return (0);
	return (ft_make_map_zero(loc, figure));
}

char	**ft_make_map_zero(t_loc_data *loc, t_map_c *figure)
{
	char	**result;
	char	buf[B_SIZE];
	int		r_count;

	r_count = read(0, buf, B_SIZE);
	loc->col = r_count - 1;
	if (ft_check_line(buf, loc->col, figure) == 0)
		return (0);
	result = ft_make_first_line(loc);
	if (result == 0)
		return (0);
	ft_strncpy(result[0], buf, loc->col);
	if (loc->row > 1)
		return (ft_make_map1_zero(loc, figure, result));
	return (result);
}

char	**ft_make_map1_zero( t_loc_data *loc, t_map_c *figure, char **result)
{
	int		r_index;
	int		r_count;
	char	buf[B_SIZE];

	r_index = 0;
	while (++r_index < loc->row)
	{
		r_count = read(0, buf, B_SIZE);
		if (r_count == 0)
			break ;
		if (r_count != loc->col + 1)
			return (ft_free1(r_index, result, loc));
		else
		{
			if (ft_check_line(buf, loc->col, figure) == 0)
				return (ft_free1(r_index, result, loc));
			result[r_index] = (char *)malloc(sizeof(char) * loc->col);
			ft_strncpy(result[r_index], buf, loc->col);
		}
	}
	return (ft_map_tail_chk_zero(loc, result, r_index));
}

char	**ft_map_tail_chk_zero(t_loc_data *loc, char **result, int r_i)
{
	int		r_count;
	char	buffer[B_SIZE];

	r_count = read(0, buffer, loc->col + 1);
	if (r_count == 1 && r_i == loc->row)
		return (result);
	else
		return (ft_free(result, loc));
}
