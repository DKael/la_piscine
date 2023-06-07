/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:18:03 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/03 22:18:05 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_printable(char *str)
{
	int	flag;
	int	index;

	flag = 1;
	index = 0;
	while (str[index] != '\0')
	{
		if (!(32 <= str[index] && str[index] <= 126))
		{
			flag = 0;
			break ;
		}
		index++;
	}
	return (flag);
}
