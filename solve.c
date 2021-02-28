/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unarasim <unarasim@student.42kl.edu>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 16:45:12 by unarasim          #+#    #+#             */
/*   Updated: 2021/02/28 20:31:59 by unarasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	check(int **numarr, int i, int x, int y, int max)
{
	int row;
	int column;

	row = 1;
	column = 1;
	while (row <= max)
	{
		if (i == numarr[row][y])
			return (1);
		row++;
	}
	while (column <= max)
	{
		if (i == numarr[x][column])
			return (1);
		column++;
	}
	return (0);
}

int	solve(int **numarr, int max, int x, int y)
{
	int i;

	i = 1;
	while (1)
	{
		while (i <= max && check(numarr, i, x, y, max))
			i++;
		if (i <= max)
			numarr[x][y] = i;
		else
		{
			numarr[x][y] = 0;
			return (1);
		}
		if (x == max && y == max)
		{
			if (check_point(numarr, max))
			{
				if (i >= max)
				{
					numarr[x][y] = 0;
					return (1);
				}
				else
					continue;
			}
			else
				return (0);
		}
		if (x == max)
		{
			if (solve(numarr, max, 1, y + 1))
				continue;
			return (0);
		}
		else
		{
			if (solve(numarr, max, x + 1, y))
				continue;
			return (0);
		}
	}
}
