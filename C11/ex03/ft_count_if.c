/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:28:00 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/15 18:28:02 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_count_if(char **tab, int length, int (*f)(char*));

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (index < length)
	{
		if (f(tab[index]) != 0)
			count++;
		index++;
	}
	return (count);
}
