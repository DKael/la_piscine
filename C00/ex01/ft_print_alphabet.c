/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 22:12:56 by hyungdki          #+#    #+#             */
/*   Updated: 2022/09/28 22:13:44 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	*cptr;
	char	output;

	output = 'a';
	cptr = &output;
	while (output <= 'z')
	{
		write(1, cptr, 1);
		output++;
	}
	return ;
}
