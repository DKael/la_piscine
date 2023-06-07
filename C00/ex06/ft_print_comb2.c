/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 22:14:55 by hyungdki          #+#    #+#             */
/*   Updated: 2022/09/29 09:22:03 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	init_array(char *buffer);

void	ft_print_comb2(void)
{
	int		count;
	char	output[5];
	int		temp;

	count = 0;
	init_array(output);
	while (count < 99)
	{
		temp = count + 1;
		output[0] = (count / 10) + '0';
		output[1] = (count % 10) + '0';
		output[3] = (temp / 10) + '0';
		output[4] = (temp % 10) + '0';
		while (temp < 100)
		{
			write(1, output, 5);
			if (!(count == 98 && temp == 99))
				write(1, ", ", 2);
			temp++;
			output[3] = (temp / 10) + '0';
			output[4] = (temp % 10) + '0';
		}
		count++;
	}
}

void	init_array(char *buffer)
{
	buffer[4] = 0;
	buffer[3] = 0;
	buffer[2] = ' ';
	buffer[1] = 0;
	buffer[0] = 0;
}
