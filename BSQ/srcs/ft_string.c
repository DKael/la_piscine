/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:10:35 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/18 09:10:36 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_string.h"

void	ft_putstr(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	write(1, str, index);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while (index < n && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	if (index < n)
	{
		while (index < n)
		{
			dest[index] = '\0';
			index++;
		}
	}
	return (dest);
}

int	ft_strlen(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

int	ft_atoi(char *str)
{
	int	index;
	int	sign;
	int	number;

	index = 0;
	sign = 1;
	number = 0;
	while ((9 <= str[index] && str[index] <= 13) || str[index] == ' ')
		index++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while ('0' <= str[index] && str[index] <= '9')
	{
		number = number * 10 + (str[index] - '0');
		index++;
	}
	return (number * sign);
}
