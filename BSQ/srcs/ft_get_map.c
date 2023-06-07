/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:16:03 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/19 12:16:04 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_get_map.h"

char	**ft_get_map(char *file_name, t_loc_data *loc, t_map_c *figure)
{
	int		fd;
	int		r_count;
	int		index;
	char	buf[20];

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (0);
	index = 0;
	r_count = read(fd, buf, 1);
	while (index < 20 && r_count != 0 && buf[index] != '\n')
		r_count = read(fd, &buf[++index], 1);
	if (index >= 20 || index <= 3 || r_count == 0)
		return (0);
	if (ft_figure_make(figure, buf[index - 1]
			, buf[index - 2], buf[index - 3]) == 0)
		return (0);
	buf[index - 3] = '\0';
	loc->row = ft_atoi(buf);
	if (loc->row <= 0)
		return (0);
	return (ft_make_map(fd, loc, figure));
}

char	**ft_make_map(int fd, t_loc_data *loc, t_map_c *figure)
{
	char	**result;
	char	buffer[B_SIZE];
	int		index;
	int		r_count;

	r_count = read(fd, buffer, 1);
	index = 0;
	while (r_count != 0 && buffer[index] != '\n')
		r_count = read(fd, &buffer[++index], 1);
	if (r_count != 0 && buffer[index] == '\n')
		loc->col = index;
	else if (r_count == 0 && loc->row == 1)
		loc->col = index;
	else
		return (0);
	if (ft_check_line(buffer, loc->col, figure) == 0)
		return (0);
	result = ft_make_first_line(loc);
	if (result == 0)
		return (0);
	ft_strncpy(result[0], buffer, loc->col);
	if (loc->row > 1)
		return (ft_make_map1(fd, loc, figure, result));
	return (result);
}	

char	**ft_make_map1(int fd, t_loc_data *loc, t_map_c *figure, char **result)
{
	char	buffer[B_SIZE];
	int		r_count;
	int		r_index;

	r_index = 0;
	while (++r_index < loc->row)
	{
		r_count = read(fd, buffer, loc->col + 1);
		if (r_count < loc->col + 1 || buffer[r_count - 1] != '\n')
			return (ft_free1(r_index, result, loc));
		else
		{
			if (ft_check_line(buffer, loc->col, figure) == 0)
				return (ft_free1(r_index, result, loc));
			result[r_index] = (char *)malloc(sizeof(char) * loc->col);
			if (result[r_index] == 0)
				return (ft_free1(r_index, result, loc));
			ft_strncpy(result[r_index], buffer, loc->col);
		}
	}
	return (ft_map_tail_check(fd, loc, result));
}

int	ft_check_line(char l[], int size, t_map_c *figure)
{
	int	index;

	index = 0;
	while (index < size)
	{
		if (l[index] != figure->empty && l[index] != figure->obstacle)
			return (0);
		index++;
	}
	return (1);
}

char	**ft_free(char **result, t_loc_data *loc)
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
