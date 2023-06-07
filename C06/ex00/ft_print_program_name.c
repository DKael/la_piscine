/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:36:17 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/11 13:36:18 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr(char *str);

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr(argv[0]);
		write(1, "\n", 1);
	}
	else
	{
		ft_putstr(argv[0]);
		write(1, "\n", 1);
	}
	return (0);
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
