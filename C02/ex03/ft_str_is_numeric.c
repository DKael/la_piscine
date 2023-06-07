/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:06:58 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/03 22:06:59 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_numeric(char *str)
{
	int	flag;
	int	index;

	flag = 1;
	index = 0;
	while (str[index] != '\0')
	{
		if (!('0' <= str[index] && str[index] <= '9'))
		{
			flag = 0;
			break ;
		}
		index++;
	}
	return (flag);
}
