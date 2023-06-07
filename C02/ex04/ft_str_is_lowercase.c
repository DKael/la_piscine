/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:14:54 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/03 22:14:55 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_lowercase(char *str)
{
	int	flag;
	int	index;

	flag = 1;
	index = 0;
	while (str[index] != '\0')
	{
		if (!('a' <= str[index] && str[index] <= 'z'))
		{
			flag = 0;
			break ;
		}
		index++;
	}
	return (flag);
}
