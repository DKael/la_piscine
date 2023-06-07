/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:36:19 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/15 13:36:21 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	**ft_split(char *str, char *charset);
int		check_sep(char c, char *charset);
char	**do_split(char *str, char *charset, char **result, int *flag);
char	*ft_strndup(char *src, int size);
void	init_value(int *index, int *flag, int *count);

char	**ft_split(char *str, char *charset)
{
	int		index;
	int		flag;
	int		split_count;
	char	**result;

	init_value(&index, &flag, &split_count);
	while (str[++index] != '\0')
	{
		if (check_sep(str[index], charset) == 1)
		{
			if (flag == 1)
			{
				split_count++;
				flag = 0;
			}
		}	
		else
			flag = 1;
	}
	if (index != 0 && check_sep(str[index - 1], charset) == 0)
		split_count++;
	result = (char **)malloc(sizeof(char *) * (split_count + 1));
	if (result == 0)
		return (0);
	return ((do_split(str, charset, result, &flag)) - split_count);
}

int	check_sep(char c, char *charset)
{
	int	index;

	index = 0;
	while (charset[index] != '\0')
	{
		if (c == charset[index])
			return (1);
		index++;
	}
	return (0);
}

char	**do_split(char *str, char *charset, char **result, int *flag)
{
	int	index;
	int	count;

	init_value(&index, flag, &count);
	while (str[++index] != '\0')
	{
		if (check_sep(str[index], charset) == 1)
		{
			if (*flag == 1)
			{
				*result++ = ft_strndup(&str[index - count], count);
				*flag = 0;
				count = 0;
			}
		}
		else
		{
			*flag = 1;
			count++;
		}
	}
	if (index != 0 && check_sep(str[index - 1], charset) == 0)
		*result++ = ft_strndup(&str[index - count], count);
	*result = 0;
	return (result);
}

char	*ft_strndup(char *src, int size)
{
	int		src_length;
	char	*replica;
	int		index;

	src_length = 0;
	while (src[src_length] != '\0')
	{
		src_length++;
	}
	if (src_length >= size)
		replica = (char *)malloc(sizeof(char) * (size + 1));
	else
		replica = (char *)malloc(sizeof(char) * (src_length + 1));
	if (replica == 0)
		return (0);
	index = 0;
	while (src[index] != '\0' && index < size)
	{
		replica[index] = src[index];
		index++;
	}
	replica[index] = '\0';
	return (replica);
}

void	init_value(int *index, int *flag, int *count)
{
	*index = -1;
	*flag = 0;
	*count = 0;
}
