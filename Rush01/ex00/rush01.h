/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanghlee <kanghlee@student.42.seoul>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:38:56 by kanghlee          #+#    #+#             */
/*   Updated: 2022/10/09 21:38:57 by kanghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef RUSH01_H
# define RUSH01_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_skyscraper
{
	int	ok;
	int	ko;
}	t_sky;

int		*ft_arg_split(char *pri_clue, int *size);
int		get_size(char *pri_clue);
void	init_square(t_sky *square, int size);
void	apply_clue(t_sky *square, int size, int *clue);
void	apply_colup_clue(t_sky *square, int size, int *clue);
void	apply_coldown_clue(t_sky *square, int size, int *clue);
void	apply_rowleft_clue(t_sky *square, int size, int *clue);
void	apply_rowright_clue(t_sky *square, int size, int *clue);
int		guess(t_sky *square, int size, int *clue, int index);
int		validation(t_sky *square, int size, int *clue, int index);
int		row_check(t_sky *square, int size, int index);
int		col_check(t_sky *square, int size, int index);
int		row_clue_check(t_sky *square, int size, int *clue, int index);
int		row_clue_check_left(t_sky *square, int size, int *clue, int row);
int		row_clue_check_right(t_sky *square, int size, int *clue, int row);
int		col_clue_check(t_sky *square, int size, int *clue, int index);
int		col_clue_check_up(t_sky *square, int size, int *clue, int col);
int		col_clue_check_down(t_sky *square, int size, int *clue, int col);
void	print_square(t_sky *square, int size);
void	free_all(t_sky *square, int *clue);

#endif