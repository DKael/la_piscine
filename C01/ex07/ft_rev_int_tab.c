/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:34:05 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/02 20:34:07 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_swap1(int *a, int *b);

void	ft_rev_int_tab(int *tab, int size)
{
	int	half_size;
	int	index;

	half_size = size / 2;
	index = 0;
	while (index < half_size)
	{
		ft_swap1(&tab[index], &tab[size - index - 1]);
		index++;
	}
}

void	ft_swap1(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
