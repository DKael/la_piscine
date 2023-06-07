/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungdki <hyungdki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:10:46 by hyungdki          #+#    #+#             */
/*   Updated: 2022/10/18 09:10:47 by hyungdki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_STRING_H
# define FT_STRING_H

# include <unistd.h>
# include "ft_data.h"

void	ft_putstr(char *str);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_strlen(char *str);
int		ft_atoi(char *str);

#endif