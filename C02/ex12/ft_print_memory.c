/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:02:28 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/04 13:02:30 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	*ft_print_memory(void *addr, unsigned int size);
void	print_address(char *start);
void	print_value_hex(char *start, int size);
void	print_value_str(char *start, int size);

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	line;
	unsigned int	remain;
	unsigned int	line_index;
	char			*line_ptr;

	line = size / 16;
	remain = size % 16;
	line_index = 0;
	while (line_index < line)
	{
		line_ptr = ((char *)addr) + (line_index * 16);
		print_address(line_ptr);
		print_value_hex(line_ptr, 16);
		print_value_str(line_ptr, 16);
		line_index++;
	}
	if (remain != 0)
	{
		line_ptr = ((char *)addr) + (line_index * 16);
		print_address(line_ptr);
		print_value_hex(line_ptr, remain);
		print_value_str(line_ptr, remain);
	}
	return (addr);
}

void	print_address(char *start)
{
	int					count;
	unsigned long long	address_value;
	char				output[16];

	address_value = (unsigned long long)start;
	count = 0;
	while (count < 16)
	{
		output[15 - count] = "0123456789abcdef"[address_value % 16];
		address_value /= 16;
		count++;
	}
	write(1, output, 16);
	write(1, ": ", 2);
}

void	print_value_hex(char *start, int size)
{
	int		index;
	char	*base_16;
	char	temp[2];

	index = 0;
	base_16 = "0123456789abcdef";
	while (index < size)
	{
		temp[0] = base_16[(unsigned char)start[index] / 16];
		temp[1] = base_16[(unsigned char)start[index] % 16];
		write(1, temp, 2);
		index++;
		if (index % 2 == 0)
			write(1, " ", 1);
	}
	while (index < 16)
	{
		write(1, "  ", 2);
		index++;
		if (index % 2 == 0)
			write(1, " ", 1);
	}
}

void	print_value_str(char *start, int size)
{
	int		index;
	char	output[16];

	index = 0;
	while (index < size)
	{
		if (!(32 <= start[index] && start[index] <= 126))
		{
			output[index] = '.';
		}
		else
			output[index] = start[index];
		index++;
	}
	write(1, output, size);
	write(1, "\n", 1);
}
