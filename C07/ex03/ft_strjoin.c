/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:29:53 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/12 10:29:54 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);
int		ft_strlen(char *str);
char	*ft_strcat(char *dest, char *src);
int		calc_total_length(int size, char **strs, char *sep);
char	*case_of_zero(void);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		index;
	int		total_length;

	if (size == 0)
		return (case_of_zero());
	else
	{
		total_length = calc_total_length(size, strs, sep);
		result = (char *)malloc(sizeof(char) * (total_length + 1));
		if (result == 0)
			return (0);
		result[0] = '\0';
		index = 0;
		while (index < size - 1)
		{
			ft_strcat(result, strs[index]);
			ft_strcat(result, sep);
			index++;
		}
		ft_strcat(result, strs[index]);
		return (result);
	}
}

int	ft_strlen(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

char	*ft_strcat(char *dest, char *src)
{
	int	dest_index;
	int	src_index;

	dest_index = 0;
	src_index = 0;
	while (dest[dest_index] != '\0')
		dest_index++;
	while (src[src_index] != '\0')
	{
		dest[dest_index] = src[src_index];
		dest_index++;
		src_index++;
	}
	dest[dest_index] = '\0';
	return (dest);
}

int	calc_total_length(int size, char **strs, char *sep)
{
	int	str_length;
	int	sep_length;
	int	index;

	str_length = 0;
	sep_length = 0;
	index = 0;
	while (index < size)
	{
		str_length += ft_strlen(strs[index]);
		index++;
	}
	str_length = str_length + (ft_strlen(sep) * (size - 1));
	return (str_length);
}

char	*case_of_zero(void)
{
	char	*result;

	result = (char *)malloc(sizeof(char));
	if (result == 0)
		return (0);
	result[0] = '\0';
	return (result);
}
