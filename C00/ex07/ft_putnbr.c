/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:23:49 by hyungdki          #+#    #+#             */
/*   Updated: 2022/09/29 19:24:03 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_positive(int f_nb, int f_digit);
void	write_negative(int f_nb, int f_digit);

void	ft_putnbr(int nb)
{
	int	digit;
	int	nb_temp;

	digit = 0;
	nb_temp = nb;
	while (nb_temp != 0)
	{
		nb_temp /= 10;
		digit++;
	}
	if (nb > 0)
		write_positive(nb, digit);
	else if (nb < 0)
		write_negative(nb, digit);
	else
		write(1, "0", 1);
	return ;
}

void	write_positive(int f_nb, int f_digit)
{
	char	buffer[30];
	int		count;

	count = 1;
	while (f_nb != 0)
	{
		buffer[f_digit - count] = (f_nb % 10) + 48;
		count++;
		f_nb /= 10;
	}
	write(1, buffer, f_digit);
	return ;
}

void	write_negative(int f_nb, int f_digit)
{
	char	buffer[30];
	int		count;

	buffer[0] = '-';
	count = 0;
	while (f_nb != 0)
	{
		buffer[f_digit - count] = (f_nb % 10) * (-1) + 48;
		count++;
		f_nb /= 10;
	}
	write(1, buffer, f_digit + 1);
	return ;
}
