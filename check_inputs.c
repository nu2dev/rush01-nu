/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unarasim <unarasim@student.42kl.edu>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 14:27:49 by unarasim          #+#    #+#             */
/*   Updated: 2021/02/28 22:05:00 by unarasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		check_digit(char i)
{
	if (i >= '0' && i <= '9')
		return (0);
	else
		return (1);
}

int		check_space(char s)
{
	if (s == ' ')
		return (0);
	else
		return (1);
}

void	rem_space(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((str[j - 1] && str[j]) || j == 0)
	{
		str[i] = str[j];
		i++;
		j += 2;
	}
	str[i] = '\0';
}

int		check_inputs(char *str, int max)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i % 2 == 0)
			if (!(str[i] >= '1' && str[i] <= (max + '0')))
				return (1);
		i++;
	}
	i = (i + 1) / 2;
	if (!(i == 12 || i == 16 || i == 20 || i == 24 || i == 28 || i == 32
			|| i == 36))
		return (1);
	rem_space(str);
	return (0);
}
