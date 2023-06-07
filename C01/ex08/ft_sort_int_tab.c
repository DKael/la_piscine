/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:23:16 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/03 16:23:19 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	quick_sort(int *part, int left, int right);
int		make_partition(int *part, int start, int end);
void	ft_swap2(int *a, int *b);

void	ft_sort_int_tab(int *tab, int size)
{
	quick_sort(tab, 0, size - 1);
}

void	quick_sort(int *part, int left, int right)
{
	int	pivot;

	if (left < right)
	{
		pivot = make_partition(part, left, right);
		quick_sort(part, left, pivot - 1);
		quick_sort(part, pivot + 1, right);
	}
}

int	make_partition(int *part, int start, int end)
{
	int	pivot;
	int	head;
	int	tail;

	pivot = part[start];
	head = start;
	tail = end + 1;
	while (1)
	{
		while (++head < end && part[head] < pivot)
			;
		while (--tail > start && part[tail] > pivot)
			;
		if (head < tail)
			ft_swap2(&part[head], &part[tail]);
		if (head >= tail)
			break ;
	}
	ft_swap2(&part[start], &part[tail]);
	return (tail);
}

void	ft_swap2(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
