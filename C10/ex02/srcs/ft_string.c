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
#include <unistd.h>
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

void	ft_puterr(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	write(2, str, index);
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

int	ft_str_is_numeric(char *str)
{
	int	flag;
	int	index;

	flag = 1;
	index = 0;
	while (str[index] != '\0')
	{
		if (!('0' <= str[index] && str[index] <= '9'))
		{
			flag = 0;
			break ;
		}
		index++;
	}
	return (flag);
}
