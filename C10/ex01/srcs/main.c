/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:34:21 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/16 17:34:22 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>
#include <string.h>
#include <errno.h>
#include "ft_string.h"

#define BUFFER_SIZE 30000

void	ft_cat(int argc, char **files, char *buffer, int *t_read);
void	ft_print_err(char *name, char *file);

int	main(int argc, char **argv)
{
	int		r_count;
	int		t_read;
	char	buffer[BUFFER_SIZE];

	if (argc == 1)
	{
		r_count = read(0, buffer, BUFFER_SIZE);
		while (r_count != 0)
		{
			write(1, buffer, r_count);
			r_count = read(0, buffer, BUFFER_SIZE);
		}
	}
	else
	{
		t_read = 0;
		ft_cat(argc, argv, buffer, &t_read);
		write(1, buffer, t_read);
	}
}

void	ft_cat(int argc, char **files, char *buffer, int *t_read)
{
	int	fd;
	int	r_count;
	int	index;

	index = 0;
	while (++index < argc)
	{
		fd = open(files[index], O_RDONLY);
		if (fd < 0)
		{
			ft_print_err(files[0], files[index]);
			continue ;
		}
		r_count = read(fd, buffer + *t_read, BUFFER_SIZE - *t_read);
		while (r_count != 0)
		{
			*t_read = *t_read + r_count;
			if (*t_read >= BUFFER_SIZE)
			{
				write(1, buffer, BUFFER_SIZE);
				*t_read = 0;
			}
			r_count = read(fd, buffer + *t_read, BUFFER_SIZE - *t_read);
		}
	}
}

void	ft_print_err(char *name, char *file)
{
	ft_puterr(basename(name));
	ft_puterr(": ");
	ft_puterr(file);
	ft_puterr(": ");
	ft_puterr(strerror(errno));
	write(2, "\n", 1);
}
