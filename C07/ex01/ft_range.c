/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:22:40 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/12 09:22:41 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max);

int	*ft_range(int min, int max)
{
	int			*range;
	int			index;
	long long	size;

	size = (long long)max - (long long)min;
	if (size <= 0)
		return (0);
	range = (int *)malloc(sizeof(int) * size);
	if (range == 0)
		return (0);
	index = 0;
	while (min < max)
	{
		range[index] = min;
		min++;
		index++;
	}
	return (range);
}
