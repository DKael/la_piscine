/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <sokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:11:59 by sokwon            #+#    #+#             */
/*   Updated: 2022/10/02 21:51:53 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define INT_MAX 2147483647
#define INT_MIN -2147483648

extern void	ft_putchar(char c);
extern void	rush(int x, int y);

void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
}

int	ft_is_digit(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			if (str[i] == ' ')
				break ;
			return (0);
		}
		i++;
	}
	while (str[i] != '\0')
		if (str[i++] != ' ')
			return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	base;
	int	i;

	sign = 1;
	base = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = 1 - 2 * (str[i++] == '-');
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7))
		{
			if (sign == 1)
				return (INT_MAX);
			else
				return (INT_MIN);
		}
		base = base * 10 + (str[i++] - '0');
	}
	return (sign * base);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (!ft_is_digit(argv[1]) || !ft_is_digit(argv[2]))
			ft_putstr("You can only enter int type as arguments!\n");
		else if (ft_atoi(argv[1]) < 0 || ft_atoi(argv[2]) < 0)
			ft_putstr("You can only enter positive numbers as arguments!\n");
		else
			rush(ft_atoi(argv[1]), ft_atoi(argv[2]));
	}
	else
		ft_putstr("You need 2 arguments!\n");
	return (0);
}
