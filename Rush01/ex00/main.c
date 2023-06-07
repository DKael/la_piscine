/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 12:35:18 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/09 21:56:31 by kanghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

#include "rush01.h"

int	main(int argc, char **argv)
{
	int		size;
	int		*clue;
	t_sky	*square;

	if (argc == 2)
	{
		clue = ft_arg_split(argv[1], &size);
		if (size == 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		square = (t_sky *)malloc((size * size) * sizeof(t_sky));
		init_square(square, size);
		apply_clue(square, size, clue);
		if (guess(square, size, clue, 0) == 1)
			print_square(square, size);
		else
			write(1, "Error\n", 6);
		free_all(square, clue);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
