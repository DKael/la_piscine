/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:32:15 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/10 14:32:17 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_iterative_power(int nb, int power);

int	ft_iterative_power(int nb, int power)
{
	int	count;
	int	result;

	count = 0;
	result = 1;
	if (nb == 0)
	{
		if (power == 0)
			return (1);
		else
			return (0);
	}	
	else if (power >= 0)
	{
		while (count < power)
		{
			result = result * nb;
			count++;
		}
		return (result);
	}
	else
		return (0);
}
