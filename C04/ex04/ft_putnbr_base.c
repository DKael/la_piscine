/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:01:25 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/06 16:01:27 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);
int		check_base(char *base);
void	recur_pos_print(int nbr, char *base, int dividor);
void	recur_neg_print(int nbr, char *base, int dividor);

void	ft_putnbr_base(int nbr, char *base)
{
	int	dividor;

	dividor = check_base(base);
	if (dividor == 0)
		return ;
	if (nbr == 0)
		write(1, &base[0], 1);
	else if (nbr < 0)
	{
		write(1, "-", 1);
		recur_neg_print(nbr, base, dividor);
	}
	else
		recur_pos_print(nbr, base, dividor);
}

int	check_base(char *base)
{
	int	index;
	int	index1;

	index = 0;
	while (base[index] != '\0')
	{
		if (base[index] == '+' || base[index] == '-')
			return (0);
		index1 = index + 1;
		while (base[index1] != '\0')
		{
			if (base[index] == base[index1])
				return (0);
			index1++;
		}
		index++;
	}
	if (index <= 1)
		return (0);
	else
		return (index);
}

void	recur_pos_print(int nbr, char *base, int dividor)
{
	if (nbr == 0)
		return ;
	else
	{
		recur_pos_print(nbr / dividor, base, dividor);
		write(1, &base[nbr % dividor], 1);
	}
}

void	recur_neg_print(int nbr, char *base, int dividor)
{
	if (nbr == 0)
		return ;
	else
	{
		recur_neg_print(nbr / dividor, base, dividor);
		write(1, &base[(nbr % dividor) * -1], 1);
	}
}
