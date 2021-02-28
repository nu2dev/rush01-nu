/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unarasim <unarasim@student.42kl.edu>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 16:45:12 by unarasim          #+#    #+#             */
/*   Updated: 2021/02/28 20:19:19 by unarasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	check_cols_up(int **numarr, int x, int max)
{
	int	cp;
	int y;
	int i;

	cp = 1;
	y = 1;
	i = 1;
	while (y + 1 <= max)
	{
		if (numarr[x][y] < numarr[x][y + i])
		{
			cp++;
			y += i;
			i = 1;
		}
		else
			i++;
	}
	if (cp == numarr[x][0])
		return (0);
	return (1);
}

int	check_cols_down(int **numarr, int x, int max)
{
	int	cp;
	int	y;
	int	i;

	cp = 1;
	y = max;
	i = 1;
	while (y - 1 >= 1)
	{
		if (numarr[x][y] < numarr[x][y - i])
		{
			cp++;
			y -= i;
			i = 1;
		}
		else
			i++;
	}
	if (cp == numarr[x][max + 1])
		return (0);
	return (1);
}

int	check_row_left(int **numarr, int y, int max)
{
	int	cp;
	int	x;
	int	i;

	cp = 1;
	x = 1;
	i = 1;
	while (x + 1 <= max)
	{
		if (numarr[x][y] < numarr[x + i][y])
		{
			cp++;
			x += i;
			i = 1;
		}
		else
			i++;
	}
	if (cp == numarr[0][y])
		return (0);
	return (1);
}

int	check_row_right(int **numarr, int y, int max)
{
	int	cp;
	int	x;
	int	i;

	x = max;
	cp = 1;
	i = 1;
	while (x - i >= 1)
	{
		if (numarr[x][y] < numarr[x - i][y])
		{
			cp++;
			x -= i;
			i = 1;
		}
		else
			i++;
	}
	if (cp == numarr[max + 1][y])
		return (0);
	return (1);
}

int	check_point(int **numarr, int max)
{
	int	i;

	i = 1;
	while (i <= max)
	{
		if (check_cols_up(numarr, i, max))
			return (1);
		if (check_cols_down(numarr, i, max))
			return (1);
		if (check_row_left(numarr, i, max))
			return (1);
		if (check_row_right(numarr, i, max))
			return (1);
		i++;
	}
	return (0);
}
