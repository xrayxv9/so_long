/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   certificate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:31:07 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/08 13:06:21 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

void	find_p(char **txt, int *x, int *y)
{
	while (txt[*x])
	{
		(*y) = 0;
		while (txt[*x][*y])
		{
			if (txt[*x][*y] == 'P')
				return ;
			(*y)++;
		}
		(*x)++;
	}
}

int	certificate_map(char **txt)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!txt)
		return (0);
	find_p(txt, &x, &y);
	printf("x : %d, y : %d\n", x, y);
	flood(txt, x, y);
	return (1);

}
