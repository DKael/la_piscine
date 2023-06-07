/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokwon <sokwon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:46:08 by sokwon            #+#    #+#             */
/*   Updated: 2022/10/01 18:19:42 by sokwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LEFT_TOP_VERTEX 'A'
#define LEFT_BOTTOM_VERTEX 'A'
#define RIGHT_TOP_VERTEX 'C'
#define RIGHT_BOTTOM_VERTEX 'C'
#define HORIZONTAL_EDGE 'B'
#define VERTICAL_EDGE 'B'
#define INSIDE ' '

extern void	ft_putchar(char c);

void	print_leftside(const int y, const int y_pos)
{
	if (y_pos == 0)
		ft_putchar(LEFT_TOP_VERTEX);
	else if (y_pos == y - 1)
		ft_putchar(LEFT_BOTTOM_VERTEX);
	else
		ft_putchar(VERTICAL_EDGE);
}

void	print_rightside(const int y, const int y_pos)
{
	if (y_pos == 0)
		ft_putchar(RIGHT_TOP_VERTEX);
	else if (y_pos == y - 1)
		ft_putchar(RIGHT_BOTTOM_VERTEX);
	else
		ft_putchar(VERTICAL_EDGE);
}

void	print_horizontal(const int x, const int y, const int y_pos)
{
	int		x_pos;

	x_pos = 0;
	while (x_pos < x)
	{
		if (x_pos == 0)
			print_leftside(y, y_pos);
		else if (x_pos == x - 1)
			print_rightside(y, y_pos);
		else if (y_pos == 0 || y_pos == y - 1)
			ft_putchar(HORIZONTAL_EDGE);
		else
			ft_putchar(INSIDE);
		x_pos++;
	}
}

void	rush(int x, int y)
{
	int		y_pos;

	if (x < 1 || y < 1)
		return ;
	y_pos = 0;
	while (y_pos < y)
	{
		print_horizontal(x, y, y_pos);
		ft_putchar('\n');
		y_pos++;
	}
}
