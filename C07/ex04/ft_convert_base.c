/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:04:04 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/12 12:04:05 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char		*ft_convert_base(char *nbr, char *base_from, char *base_to);
char		*ft_putnbr_base(int nbr, char *base);
int			check_base(char *base);
char		*write_positive(int f_nb, char *base, int dividor);
char		*write_negative(int f_nb, char *base, int dividor);
extern int	ft_atoi_base(char *str, char *base);
extern int	check_base1(char *base);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		mid_result;
	char	*result;

	if (check_base1(base_from) == 0 || check_base(base_to) == 0)
		return (0);
	mid_result = ft_atoi_base(nbr, base_from);
	result = ft_putnbr_base(mid_result, base_to);
	return (result);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	int		dividor;
	char	*result;

	dividor = check_base(base);
	if (dividor == 0)
		return (0);
	if (nbr < 0)
		result = write_negative(nbr, base, dividor);
	else if (nbr > 0)
		result = write_positive(nbr, base, dividor);
	else
	{
		result = (char *)malloc(sizeof(char));
		if (result == 0)
			return (0);
		result[0] = base[0];
	}
	return (result);
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

char	*write_positive(int f_nb, char *base, int dividor)
{
	int		count;
	int		b_digit;
	int		temp_nb;
	char	*result;

	b_digit = 0;
	temp_nb = f_nb;
	while (temp_nb != 0)
	{
		temp_nb /= dividor;
		b_digit++;
	}
	result = (char *)malloc(sizeof(char) * (b_digit + 1));
	if (result == 0)
		return (0);
	count = 1;
	while (f_nb != 0)
	{
		result[b_digit - count] = base[f_nb % dividor];
		count++;
		f_nb /= dividor;
	}
	result[b_digit] = '\0';
	return (result);
}

char	*write_negative(int f_nb, char *base, int dividor)
{
	int		count;
	int		b_digit;
	int		temp_nb;
	char	*result;

	b_digit = 0;
	temp_nb = f_nb;
	while (temp_nb != 0)
	{
		temp_nb /= dividor;
		b_digit++;
	}
	result = (char *)malloc(sizeof(char) * (b_digit + 2));
	if (result == 0)
		return (0);
	result[0] = '-';
	count = 0;
	while (f_nb != 0)
	{
		result[b_digit - count] = base[(f_nb % dividor) * -1];
		count++;
		f_nb /= dividor;
	}
	result[b_digit + 1] = '\0';
	return (result);
}
