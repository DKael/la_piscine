/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 23:37:48 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/04 23:37:49 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	index;
	unsigned char	*p1;
	unsigned char	*p2;

	index = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (p1[index] != '\0' && p2[index] != '\0' && index < n)
	{
		if (p1[index] > p2[index])
			return ((int)(p1[index] - p2[index]));
		else if (p1[index] < p2[index])
			return (-1 * (int)(p2[index] - p1[index]));
		index++;
	}
	if (index == n)
		return (0);
	if (p1[index] > p2[index])
		return ((int)(p1[index] - p2[index]));
	else if (p1[index] < p2[index])
		return (-1 * (int)(p2[index] - p1[index]));
	else
		return (0);
}
