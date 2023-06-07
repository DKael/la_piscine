/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:31:38 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/15 17:31:40 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int));

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	index;
	int	*result;

	index = 0;
	result = (int *)malloc(sizeof(int) * length);
	if (result == 0)
		return (0);
	while (index < length)
	{
		result[index] = f(tab[index]);
		index++;
	}
	return (result);
}
