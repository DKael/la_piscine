/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:12:21 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/06 09:12:23 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
int				ft_strlen(char *str);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	dest_lenght;
	int	src_length;
	int	src_index;
	int	remain_size;
	int	signed_size;

	signed_size = (int)size;
	dest_lenght = ft_strlen(dest);
	src_length = ft_strlen(src);
	if (signed_size < 0)
		signed_size = dest_lenght + src_length + 1;
	remain_size = signed_size - dest_lenght - 1;
	src_index = 0;
	while (src_index < remain_size && src_index < src_length)
	{
		dest[dest_lenght + src_index] = src[src_index];
		src_index++;
	}
	dest[dest_lenght + src_index] = '\0';
	if (src_length + signed_size < src_length + dest_lenght)
		return (src_length + signed_size);
	else
		return (dest_lenght + src_length);
}

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}
