/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 22:14:39 by hyungdki          #+#    #+#             */
/*   Updated: 2022/09/28 22:14:42 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_comb(void)
{
	char	output[3];

	output[0] = '0';
	output[1] = '1';
	output[2] = '2';
	while (output[0] <= '7')
	{
		while (output[1] <= '8')
		{
			while (output[2] <= '9')
			{
				write(1, output, 3);
				if (!(output[0] == '7' && output[1] == '8' && output[2] == '9'))
					write(1, ", ", 2);
				output[2]++;
			}
			output[1]++;
			output[2] = output[1] + 1;
		}
		output[0]++;
		output[1] = output[0] + 1;
		output[2] = output[1] + 1;
	}
	return ;
}
