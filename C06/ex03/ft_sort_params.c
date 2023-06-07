/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:53:54 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/11 18:53:55 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr(char *str);
void	selection_sort(int argc, char **argv);
int		ft_strcmp(char *s1, char *s2);

int	main(int argc, char **argv)
{
	int	index;

	selection_sort(argc, argv);
	index = 1;
	while (index < argc)
	{
		ft_putstr(argv[index]);
		write(1, "\n", 1);
		index++;
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

void	selection_sort(int argc, char **argv)
{
	int		index1;
	int		index2;
	int		smallest;
	char	*temp;

	index1 = 1;
	while (index1 < argc)
	{
		smallest = index1;
		index2 = index1 + 1;
		while (index2 < argc)
		{
			if (ft_strcmp(argv[smallest], argv[index2]) > 0)
				smallest = index2;
			index2++;
		}
		temp = argv[index1];
		argv[index1] = argv[smallest];
		argv[smallest] = temp;
		index1++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	index;
	unsigned char	*p1;
	unsigned char	*p2;

	index = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (p1[index] != '\0' && p2[index] != '\0')
	{
		if (p1[index] > p2[index])
			return ((int)(p1[index] - p2[index]));
		else if (p1[index] < p2[index])
			return (-1 * (int)(p2[index] - p1[index]));
		index++;
	}
	if (p1[index] > p2[index])
		return ((int)(p1[index] - p2[index]));
	else if (p1[index] < p2[index])
		return ((-1 * (int)(p2[index] - p1[index])));
	else
		return (0);
}
