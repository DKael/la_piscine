/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 12:04:27 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/16 12:04:29 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_operator.h"

int	addition(int num1, int num2)
{
	return (num1 + num2);
}

int	subtraction(int num1, int num2)
{
	return (num1 - num2);
}

int	multiplication(int num1, int num2)
{
	return (num1 * num2);
}

int	division(int num1, int num2)
{
	return (num1 / num2);
}

int	modulo(int num1, int num2)
{
	return (num1 % num2);
}
