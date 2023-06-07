/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:22:58 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/03 20:23:00 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_alpha(char *str)
{
	int	flag;
	int	index;

	flag = 1;
	index = 0;
	while (str[index] != '\0')
	{
		if (!(('A' <= str[index] && str[index] <= 'Z')
				|| ('a' <= str[index] && str[index] <= 'z')))
		{
			flag = 0;
			break ;
		}
		index++;
	}
	return (flag);
}
