/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:00:44 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/10 10:00:46 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int		ft_atoi_base(char *str, char *base);
int		check_base1(char *base);
int		check_blank(char *str, int index);
int		check_sign(char *str, int index, int *sign);
char	in_base(char check, char *base, int *result);

int	ft_atoi_base(char *str, char *base)
{
	int	dividor;
	int	index;
	int	sign;
	int	number;
	int	result;

	dividor = check_base1(base);
	if (dividor == 0)
		return (0);
	index = 0;
	sign = 0;
	number = 0;
	result = 0;
	index = check_blank(str, index);
	index = check_sign(str, index, &sign);
	while (in_base(str[index], base, &result) != 0)
	{
		number = number * dividor + result;
		index++;
	}
	if (sign % 2 == 0)
		return (number);
	else
		return (number * -1);
}

int	check_base1(char *base)
{
	int	index;
	int	index1;

	index = 0;
	while (base[index] != '\0')
	{
		if (base[index] == '+' || base[index] == '-' || base[index] == ' '
			|| (9 <= base[index] && base[index] <= 13))
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

int	check_blank(char *str, int index)
{
	while ((9 <= str[index] && str[index] <= 13) || str[index] == ' ')
		index++;
	return (index);
}

int	check_sign(char *str, int index, int *sign)
{
	while (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			(*sign)++;
		index++;
	}
	return (index);
}

char	in_base(char check, char *base, int *result)
{
	*result = 0;
	while (base[*result] != '\0')
	{
		if (check == base[*result])
			return (1);
		(*result)++;
	}
	return (0);
}
