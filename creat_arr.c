/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unarasim <unarasim@student.42kl.edu>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:37:17 by unarasim          #+#    #+#             */
/*   Updated: 2021/02/28 21:28:21 by unarasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		total(char *str)
{
	int i;
	int sum;

	i = 0;
	sum = 0;
	while (str[i])
	{
		if (!check_digit(str[i]))
			sum++;
		i++;
	}
	return (sum);
}

int		find_max(char *str)
{
	return (total(str) / 4);
}


void	fill_arr(int **numarr, int max, char *inputs)
{
	int	i;

	i = 0;
	while (++i <= max)
		numarr[0][i] = inputs[i - 1] - '0';
	i = 0;
	while (++i <= max)
		numarr[max + 1][i] = inputs[i + 3] - '0';
	i = 0;
	while (++i <= max)
		numarr[i][0] = inputs[i + 7] - '0';
	i = 0;
	while (++i <= max)
		numarr[i][max + 1] = inputs[i + 11] - '0';
}

int		**create_arr(int max, char *inputs)
{
	int	i;
	int	j;
	int	**numarr;

	if (!(numarr = (int **)malloc(sizeof(int *) * max + 2)))
		return (0);
	i = 0;
	while (i < max + 2)
	{
		if (!(numarr[i] = (int *)malloc(sizeof(int) * max + 2)))
			return (0);
		i++;
	}
	i = 0;
	while (i < max + 2)
	{
		j = -1;
		while (++j < max + 2)
			numarr[i][j] = 0;
		i++;
	}
	fill_arr(numarr, max, inputs);
	return (numarr);
}
