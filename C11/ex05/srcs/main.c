/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:51:30 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/15 20:51:31 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_operator.h"
#include "ft_atoi.h"
#include "ft_putnbr.h"

void	init_func_pointer(int (**func)(int, int));
void	print(int (**func)(int, int), int num1, int num2, char *operator);

int	main(int argc, char **argv)
{
	int	(*operator[5])(int, int);
	int	num1;
	int	num2;

	if (argc == 4)
	{
		init_func_pointer(operator);
		num1 = ft_atoi(argv[1]);
		num2 = ft_atoi(argv[3]);
		print(operator, num1, num2, argv[2]);
		write(1, "\n", 1);
	}
	return (0);
}

void	init_func_pointer(int (**func)(int, int))
{
	func[0] = addition;
	func[1] = subtraction;
	func[2] = multiplication;
	func[3] = division;
	func[4] = modulo;
}

void	print(int (**func)(int, int), int num1, int num2, char *operator)
{
	if (operator[0] == '+' && operator[1] == '\0')
		ft_putnbr(func[0](num1, num2));
	else if (operator[0] == '-' && operator[1] == '\0')
		ft_putnbr(func[1](num1, num2));
	else if (operator[0] == '*' && operator[1] == '\0')
		ft_putnbr(func[2](num1, num2));
	else if (operator[0] == '/' && operator[1] == '\0')
	{
		if (num2 == 0)
			write(1, "Stop : division by zero", 23);
		else
			ft_putnbr(func[3](num1, num2));
	}
	else if (operator[0] == '%' && operator[1] == '\0')
	{
		if (num2 == 0)
			write(1, "Stop : modulo by zero", 21);
		else
			ft_putnbr(func[4](num1, num2));
	}
	else
		write(1, "0", 1);
}
