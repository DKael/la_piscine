/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:02:33 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/19 20:02:34 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_get_map1.h"

int	**ft_free_int(int **result, t_loc_data *loc)
{
	int	index;

	index = 0;
	while (index < loc->row)
	{
		free(result[index]);
		index++;
	}
	free(result);
	return (0);
}

int	ft_figure_make(t_map_c *figure, char full, char obs, char empty)
{
	if (!(32 <= obs && obs <= 126))
		return (0);
	if (!(32 <= empty && empty <= 126))
		return (0);
	if (!(32 <= full && full <= 126))
		return (0);
	if (full == obs || full == empty || obs == empty)
		return (0);
	figure->full = full;
	figure->obstacle = obs;
	figure->empty = empty;
	return (1);
}

char	**ft_map_tail_check(int fd, t_loc_data *loc, char **result)
{
	int		r_count;
	char	buffer[B_SIZE];

	r_count = read(fd, buffer, loc->col + 1);
	if (r_count == 0)
		return (result);
	else
		return (ft_free(result, loc));
}

char	**ft_make_first_line(t_loc_data *loc)
{
	char	**temp;

	temp = (char **)malloc(sizeof(char *) * loc->row);
	if (temp == 0)
		return (0);
	temp[0] = (char *)malloc(sizeof(char) * loc->col);
	if (temp[0] == 0)
	{
		free(temp);
		return (0);
	}
	return (temp);
}

char	**ft_free1(int r_index, char **result, t_loc_data *loc)
{
	loc->row = r_index + 1;
	return (ft_free(result, loc));
}
