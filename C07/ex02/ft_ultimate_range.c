/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:52:54 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/12 09:52:56 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max);

int	ft_ultimate_range(int **range, int min, int max)
{
	int			index;
	long long	size;

	size = (long long)max - (long long)min;
	if (size <= 0)
	{
		range = 0;
		return (0);
	}
	(*range) = (int *)malloc(sizeof(int) * size);
	if (range == 0)
		return (-1);
	index = 0;
	while (min < max)
	{
		(*range)[index] = min;
		min++;
		index++;
	}
	return (size);
}
