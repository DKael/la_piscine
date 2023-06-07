/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:16:57 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/10 18:16:58 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_sqrt(int nb);

int	ft_sqrt(int nb)
{
	double	index;
	double	l_nb;

	l_nb = (double)nb;
	if (l_nb > 0.0)
	{
		index = 1.0;
		while (index <= l_nb / index)
		{
			if ((l_nb / index) - index <= 0.00000000001)
				return ((int)index);
			index = index + 1.0;
		}
	}
	return (0);
}
