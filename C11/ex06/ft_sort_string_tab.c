/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 00:41:49 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/16 00:41:51 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_sort_string_tab(char **tab);
void	quick_sort(char **part, int left, int right);
int		make_partition(char **part, int start, int end);
int		ft_strcmp(char *s1, char *s2);
void	ft_swap2(char **a, char **b);

void	ft_sort_string_tab(char **tab)
{
	int		index;

	index = 0;
	while (tab[index] != 0)
		index++;
	quick_sort(tab, 0, index - 1);
}

void	quick_sort(char **part, int left, int right)
{
	int	pivot;

	if (left < right)
	{
		pivot = make_partition(part, left, right);
		quick_sort(part, left, pivot - 1);
		quick_sort(part, pivot + 1, right);
	}
}

int	make_partition(char **part, int start, int end)
{
	char	*pivot;
	int		head;
	int		tail;

	pivot = part[start];
	head = start;
	tail = end + 1;
	while (1)
	{
		while (++head < end && ft_strcmp(pivot, part[head]) > 0)
			;
		while (--tail > start && ft_strcmp(pivot, part[tail]) < 0)
			;
		if (head < tail)
			ft_swap2(&part[head], &part[tail]);
		if (head >= tail)
			break ;
	}
	ft_swap2(&part[start], &part[tail]);
	return (tail);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	index;
	unsigned char	*p1;
	unsigned char	*p2;

	index = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (p1[index] != '\0' && p2[index] != '\0')
	{
		if (p1[index] > p2[index])
			return ((int)(p1[index] - p2[index]));
		else if (p1[index] < p2[index])
			return (-1 * (int)(p2[index] - p1[index]));
		index++;
	}
	if (p1[index] > p2[index])
		return ((int)(p1[index] - p2[index]));
	else if (p1[index] < p2[index])
		return ((-1 * (int)(p2[index] - p1[index])));
	else
		return (0);
}

void	ft_swap2(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
