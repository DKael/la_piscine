/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:23:57 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/10 21:23:59 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int		ft_find_next_prime(int nb);
int		ft_is_prime1(int nb);
double	ft_sqrtl1(double input);

int	ft_find_next_prime(int nb)
{
	int	count;

	if (nb > 1)
	{
		count = nb;
		while (ft_is_prime1(count) == 0)
			count++;
		return (count);
	}
	else
	{
		return (2);
	}
}

int	ft_is_prime1(int nb)
{
	int	count;
	int	limit;

	if (nb > 1)
	{
		count = 2;
		limit = (int)ft_sqrtl1((double)nb);
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

double	ft_sqrtl1(double n)
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
