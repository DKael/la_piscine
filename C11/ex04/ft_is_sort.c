/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:36:47 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/15 18:36:48 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_is_sort(int *tab, int length, int (*f)(int, int));

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	index;
	int	sort_count;
	int	rev_sort_count;

	index = 0;
	sort_count = 0;
	rev_sort_count = 0;
	while (index < length - 1)
	{
		if (f(tab[index], tab[index + 1]) < 0)
			sort_count++;
		else if (f(tab[index], tab[index + 1]) > 0)
			rev_sort_count++;
		else
		{
			sort_count++;
			rev_sort_count++;
		}
		index++;
	}
	if (sort_count == index || rev_sort_count == index)
		return (1);
	else
		return (0);
}
