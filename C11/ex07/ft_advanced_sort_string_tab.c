/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:29:30 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/16 11:29:31 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *));
void	bubble_sort(int count, char **argv, int (*cmp)(char *, char *));
void	ft_swap3(char **a, char **b);

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		count;

	count = 0;
	while (tab[count] != 0)
		count++;
	bubble_sort(count, tab, cmp);
}

void	bubble_sort(int count, char **argv, int (*cmp)(char *, char *))
{
	int	index1;
	int	index2;

	index1 = 0;
	while (index1 < count)
	{
		index2 = 0;
		while (index2 < count - 1 - index1)
		{
			if (cmp(argv[index2], argv[index2 + 1]) > 0)
				ft_swap3(&argv[index2], &argv[index2 + 1]);
			index2++;
		}
		index1++;
	}
}

void	ft_swap3(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
