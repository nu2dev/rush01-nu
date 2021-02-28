/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unarasim <unarasim@student.42kl.edu>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:24:21 by unarasim          #+#    #+#             */
/*   Updated: 2021/02/28 21:45:02 by unarasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <unistd.h>
# include <stdlib.h>

int		check_inputs(char *str, int	max);
int		check_digit(char	i);
int		check_space(char	s);
int		find_max(char	*str);
void	rem_space(char *str);
int		**create_arr(int	max, char	*inputs);
int		check_cols_up(int **numarr, int x, int max);
int		check_cols_down(int **numarr, int x, int max);
int		check_row_left(int **numarr, int y, int max);
int		check_row_right(int **numarr, int y, int max);
int		check_point(int **numarr, int max);
int		check(int **numarr, int i, int x, int y, int max);
int		solve(int	**numarr, int	max, int	a, int	b);
void	print_arr(int	**numarr, int	max);
#endif
