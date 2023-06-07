/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:26:06 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/15 17:26:07 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_foreach(int *tab, int length, void (*f)(int));

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	index;

	index = 0;
	while (index < length)
	{
		f(tab[index]);
		index++;
	}
}
