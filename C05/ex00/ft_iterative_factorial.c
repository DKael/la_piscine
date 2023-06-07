/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:20:20 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/10 11:20:22 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_iterative_factorial(int nb);

int	ft_iterative_factorial(int nb)
{
	int	result;
	int	count;

	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	result = 1;
	count = 1;
	while (count <= nb)
	{
		result = result * count;
		count++;
	}
	return (result);
}
