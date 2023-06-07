/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:26:46 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/04 12:26:49 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_unprintable_char(unsigned char input);

void	ft_putstr_non_printable(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (32 <= str[index] && str[index] <= 126)
			write(1, &str[index], 1);
		else
			print_unprintable_char(str[index]);
		index++;
	}
}

void	print_unprintable_char(unsigned char input)
{
	char	*base_16;
	char	output_16[3];

	base_16 = "0123456789abcdef";
	output_16[0] = '\\';
	output_16[1] = base_16[input / 16];
	output_16[2] = base_16[input % 16];
	write(1, output_16, 3);
}
