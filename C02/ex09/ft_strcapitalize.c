/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:08:59 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/04 11:09:01 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strcapitalize(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if ('A' <= str[index] && str[index] <= 'Z')
			str[index] += 32;
		index++;
	}
	if ('a' <= str[0] && str[0] <= 'z')
		str[0] -= 32;
	index = 1;
	while (str[index] != '\0')
	{
		if ('a' <= str[index] && str[index] <= 'z'
			&& !(('A' <= str[index - 1] && str[index - 1] <= 'Z')
				|| ('a' <= str[index - 1] && str[index - 1] <= 'z')
				|| ('0' <= str[index - 1] && str[index - 1] <= '9')))
			str[index] -= 32;
		index++;
	}
	return (str);
}
