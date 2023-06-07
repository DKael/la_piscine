/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:43:49 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/15 17:43:57 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_any(char **tab, int (*f)(char*));

int	ft_any(char **tab, int (*f)(char*))
{
	int	index;

	index = 0;
	while (tab[index] != 0)
	{
		if (f(tab[index]) != 0)
			return (1);
		index++;
	}
	return (0);
}
