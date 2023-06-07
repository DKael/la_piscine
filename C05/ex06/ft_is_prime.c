/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:42:37 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/10 19:42:38 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int		ft_is_prime(int nb);
double	ft_sqrtl(double input);

int	ft_is_prime(int nb)
{
	int	count;
	int	limit;

	if (nb > 1)
	{
		count = 2;
		limit = (int)ft_sqrtl((double)nb);
		while (count <= limit)
		{
			if (nb % count == 0)
				return (0);
			count++;
		}
		return (1);
	}
	else
		return (0);
}

double	ft_sqrtl(double n)
{
	double	s;
	double	t;

	s = n / 2;
	t = 0;
	while (s != t)
	{
		t = s;
		s = ((n / t) + t) / 2;
	}
	return (s);
}
