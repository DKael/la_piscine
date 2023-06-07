/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 00:07:09 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/11 00:07:10 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int		ft_ten_queens_puzzle(void);
void	place_queen(char *arrangement, int index, int *result);
int		arrangement_is_valid(char *arrangement, int index);
int		check_gradient(char *arrangement, int idx1, int idx2);

int	ft_ten_queens_puzzle(void)
{
	char	arrangement[11];
	int		result;
	int		index;

	index = 0;
	result = 0;
	while (index < 10)
	{
		arrangement[index] = '/';
		index++;
	}
	arrangement[10] = '\n';
	place_queen(arrangement, 0, &result);
	return (result);
}

void	place_queen(char *arrangement, int index, int *result)
{
	int	input;

	if (index < 10)
	{
		input = 0;
		while (input < 10)
		{
			arrangement[index] = input + '0';
			if (arrangement_is_valid(arrangement, index) == 0)
			{
				input++;
				continue ;
			}
			place_queen(arrangement, index + 1, result);
			input++;
		}
		arrangement[index] = '/';
	}
	else
	{
		write(1, arrangement, 11);
		(*result)++;
	}
}

int	arrangement_is_valid(char *arrangement, int index)
{
	int	check_idx;

	check_idx = 0;
	while (check_idx < index)
	{
		if (arrangement[check_idx] == arrangement[index])
			return (0);
		if (check_gradient(arrangement, check_idx, index) == 0)
			return (0);
		check_idx++;
	}
	return (1);
}

int	check_gradient(char *arrangement, int idx1, int idx2)
{
	int	dx;
	int	dy;

	dx = idx2 - idx1;
	dy = (arrangement[idx2] - '0') - (arrangement[idx1] - '0');
	if (dy < 0)
		dy *= (-1);
	if (dx == dy)
		return (0);
	else
		return (1);
}
