/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:41:52 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/13 18:41:53 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_stock_str.h"

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av);
char				*ft_strdup(char *src);
int					ft_strlen(char *str);
char				*ft_strcpy(char *dest, char *src);

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			index;
	t_stock_str	*result;

	result = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (result == 0)
		return (0);
	index = 0;
	while (index < ac)
	{
		result[index].size = ft_strlen(av[index]);
		result[index].str = av[index];
		result[index].copy = ft_strdup(av[index]);
		index++;
	}
	result[index].str = 0;
	return (result);
}

char	*ft_strdup(char *src)
{
	int		src_length;
	char	*replica;

	src_length = ft_strlen(src);
	replica = (char *)malloc(sizeof(char) * (src_length + 1));
	if (replica == 0)
		return (0);
	ft_strcpy(replica, src);
	return (replica);
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

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
