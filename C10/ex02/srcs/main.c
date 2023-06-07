/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:33:30 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/18 09:33:31 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>
#include <string.h>
#include <errno.h>
#include "ft_string.h"

#define BUFFER_SIZE 102400

void	ft_tail(int argc, char **files, char *buffer, int *t_read);
void	ft_print_err(char *name, char *file);

int	main(int argc, char **argv)
{
	int		r_count;
	int		nl_count;
	int		char_count;
	int		t_read;
	int		byte_count;
	int		index;
	int		b_index;
	int		fd;
	char	buffer[BUFFER_SIZE];

	if (argc >= 2 && argv[1][0] == '-' && argv[1][1] == 'c' && argv[1][2] == '\0')
	{
		if(argc == 2)
		{
			ft_puterr(basename(argv[0]));
			ft_puterr(": option requires an argument -- c\n");
			return (0);
		}
		else if (argc == 3 && ft_str_is_numeric(argv[2]) == 1)
		{
			byte_count = ft_atoi(argv[2]);
			r_count = read(0, buffer, BUFFER_SIZE);
			while (r_count != 0)
			{
				t_read = t_read + r_count;
				r_count = read(0, buffer + t_read, BUFFER_SIZE - t_read);
			}
			if (t_read < byte_count)
				write(1, buffer, t_read);
			else
				write(1, &buffer[t_read - byte_count], byte_count);
		}
		else if (argc == 3 && ft_str_is_numeric(argv[2]) == 0)
		{
			ft_puterr(basename(argv[0]));
			ft_puterr(": illegal offset -- ");
			ft_puterr(argv[2]);
			write(2, "\n", 1);
			return (0);
		}
		else if (argc > 3 && ft_str_is_numeric(argv[2]) == 1)
		{				
			byte_count = ft_atoi(argv[2]);
			index = 2;
			while (++index < argc)
			{
				fd = open(argv[index], O_RDONLY);
				if (fd < 0)
				{
					ft_print_err(argv[0], argv[index]);
					continue ;
				}
				r_count = read(fd, buffer, BUFFER_SIZE);
				if (argc != 4)
				{
					if (index != 3)
						write(1, "\n", 1);
					write(1, "==> ", 4);
					ft_putstr(basename(argv[index]));
					write(1, " <==\n", 5);
				}
				if (r_count < byte_count)
					write(1, buffer, r_count);
				else
					write(1, &buffer[r_count - byte_count], byte_count);
			}
		}
		else
		{
			ft_puterr(basename(argv[0]));
			ft_puterr(": illegal offset -- ");
			ft_puterr(argv[2]);
			write(2, "\n", 1);
			return (0);
		}
	}
	else
	{
		if(argc == 1)
		{
			r_count = read(0, buffer, BUFFER_SIZE);
			while (r_count != 0)
			{
				t_read = t_read + r_count;
				r_count = read(0, buffer + t_read, BUFFER_SIZE - t_read);
			}
			nl_count = 0;
			char_count = 0;
			b_index = 0;
			while (nl_count < 10 && (t_read - 1 - b_index) != 0)
			{
				if (buffer[t_read - 1 - b_index] == '\n')
					nl_count++;
				b_index++;
			}
			write(1, &buffer[t_read - 1 - b_index], b_index + 1);
		}
		else
		{				
			index = 0;
			while (++index < argc)
			{
				fd = open(argv[index], O_RDONLY);
				if (fd < 0)
				{
					ft_print_err(argv[0], argv[index]);
					continue ;
				}
				r_count = read(fd, buffer, BUFFER_SIZE);
				if (argc != 2)
				{
					if (index != 1)
						write(1, "\n", 1);
					write(1, "==> ", 4);
					ft_putstr(basename(argv[index]));
					write(1, " <==\n", 5);
				}
				nl_count = 0;
				char_count = 0;
				b_index = 0;
				while (nl_count < 10 && (r_count - 1 - b_index) != 0)
				{
					if (buffer[r_count - 1 - b_index] == '\n')
						nl_count++;
					b_index++;
				}
				write(1, &buffer[r_count - 1 - b_index], b_index + 1);
			}
		}
	}	
}

void	ft_tail(int argc, char **files, char *buffer, int *t_read)
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

void	ft_tail_c(int argc, char **files, char *buffer, int *t_read)
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