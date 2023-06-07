/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 22:14:23 by hyungdki          #+#    #+#             */
/*   Updated: 2022/09/28 22:14:25 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_is_negative(int n)
{
	char	answer[1];

	if (n >= 0)
	{
		answer[0] = 'P';
		write(1, answer, 1);
	}
	else
	{
		answer[0] = 'N';
		write(1, answer, 1);
	}
	return ;
}
