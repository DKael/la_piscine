/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:33:17 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/04 11:33:18 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	index1;

	index = 0;
	index1 = 0;
	while (src[index] != '\0')
		index++;
	if (index >= size)
	{
		while (index1 + 1 < size)
		{
			dest[index1] = src[index1];
			index1++;
		}
	}
	else
	{
		while (src[index1] != '\0')
		{
			dest[index1] = src[index1];
			index1++;
		}
	}
	dest[index1] = '\0';
	return (index);
}
