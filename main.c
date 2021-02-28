/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unarasim <unarasim@student.42kl.edu>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:23:34 by unarasim          #+#    #+#             */
/*   Updated: 2021/02/28 21:50:35 by unarasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	print_arr(int **numarr, int max)
{
	int	x;
	int	y;
	char c;

	x = 1;
	while (x <= max)
	{
		y = 1;
		while (y <= max)
		{			
			c = (numarr[x][y] + '0');
			write(1, &c, 1);
			if (y != max)
				write(1, " ", 1);
			y++;
		}
		write(1, "\n", 1);
		x++;
	}	
}

int	main(int argc, char **argv)
{
	int	**numarr;
	int	max;
/*-
	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
*/	
	max = find_max(argv[1]);
	if (check_inputs(argv[1], max))
	{
		write(1, "Error\n", 6);
		return (1);
	}

	if(!(numarr = create_arr(max, argv[1])))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (solve(numarr, max, 1, 1))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	print_arr(numarr, max);
	return (0);
}
