/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:32:39 by hyungdki          #+#    #+#             */
/*   Updated: 2022/09/29 19:32:41 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	recur_combn(char *buffer, int f_digit, int index);
int		find_last(char *buffer, int f_digit);

void	ft_print_combn(int n)
{
	char	output[10];
	int		iter;

	iter = 1;
	output[0] = '0';
	while (iter < n)
	{
		output[iter] = output[iter - 1] + 1;
		iter++;
	}
	recur_combn(output, n, 0);
	return ;
}

void	recur_combn(char *buffer, int f_digit, int index)
{
	int	temp_index;

	temp_index = index;
	while (buffer[index] <= (10 - f_digit + index + 48))
	{
		if (index + 1 == f_digit)
		{
			write(1, buffer, f_digit);
			if (find_last(buffer, f_digit) != f_digit)
				write(1, ", ", 2);
			buffer[index]++;
		}
		else
			recur_combn(buffer, f_digit, index + 1);
	}
	buffer[index - 1]++;
	while (temp_index < f_digit)
	{
		buffer[temp_index] = buffer[temp_index - 1] + 1;
		temp_index++;
	}
	return ;
}

int	find_last(char *buffer, int f_digit)
{
	int		flag;
	int		index;

	flag = 0;
	index = 0;
	while (index < f_digit)
	{
		if (buffer[index] == 10 - f_digit + index + 48)
			flag++;
		index++;
	}
	return (flag);
}
