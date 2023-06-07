/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:16:56 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/06 22:16:58 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_atoi.h"

int	ft_atoi(char *str)
{
	int	index;
	int	sign;
	int	number;

	index = 0;
	sign = 0;
	number = 0;
	while ((9 <= str[index] && str[index] <= 13) || str[index] == ' ')
		index++;
	while (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign++;
		index++;
	}
	while ('0' <= str[index] && str[index] <= '9')
	{
		number = number * 10 + (str[index] - '0');
		index++;
	}
	if (sign % 2 == 0)
		return (number);
	else
		return (number * -1);
}
