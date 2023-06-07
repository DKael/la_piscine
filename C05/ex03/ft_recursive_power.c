/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:56:40 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/10 14:56:42 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_recursive_power(int nb, int power);

int	ft_recursive_power(int nb, int power)
{
	if (nb != 0 && power > 0)
		return (nb * ft_recursive_power(nb, power - 1));
	else if (nb != 0 && power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else if (nb == 0 && power == 0)
		return (1);
	else
		return (0);
}
