/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:33:02 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/16 13:33:03 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>

void	ft_print(int fd);

int	main(int argc, char **argv)
{
	int	fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			write(1, "Cannot read file.\n", 18);
			return (0);
		}
		ft_print(fd);
		close(fd);
	}
	else if (argc == 1)
		write(1, "File name missing.\n", 19);
	else
		write(1, "Too many arguments.\n", 20);
	return (0);
}

void	ft_print(int fd)
{
	char	buffer[100];
	int		read_count;

	read_count = read(fd, buffer, 100);
	while (read_count != 0)
	{
		write(1, buffer, read_count);
		read_count = read(fd, buffer, 100);
	}
}
