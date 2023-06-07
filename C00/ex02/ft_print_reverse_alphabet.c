/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 22:13:57 by hyungdki          #+#    #+#             */
/*   Updated: 2022/09/28 22:14:02 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	*cptr;
	char	output;

	output = 'z';
	cptr = &output;
	while (output >= 'a')
	{
		write(1, cptr, 1);
		output--;
	}
	return ;
}
