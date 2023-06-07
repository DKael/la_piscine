/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:53:22 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/13 19:53:23 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_stock_str.h"

void	ft_show_tab(struct s_stock_str *par);
void	ft_putnbr(int nb);
void	write_positive(int f_nb, int f_digit);
void	write_negative(int f_nb, int f_digit);
void	ft_putstr(char *str);

void	ft_show_tab(struct s_stock_str *par)
{
	int	index;

	index = 0;
	while (par[index].str != 0)
	{
		ft_putstr(par[index].str);
		write(1, "\n", 1);
		ft_putnbr(par[index].size);
		write(1, "\n", 1);
		ft_putstr(par[index].copy);
		write(1, "\n", 1);
		index++;
	}
}

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
		buffer[f_digit - count] = (f_nb % 10) + '0';
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
		buffer[f_digit - count] = (f_nb % 10) * (-1) + '0';
		count++;
		f_nb /= 10;
	}
	write(1, buffer, f_digit + 1);
	return ;
}

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
