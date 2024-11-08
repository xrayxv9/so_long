/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:00:35 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/08 18:51:40 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

void	get_len(int *x, int *y, char **txt)
{
	*y = ft_strlen(txt[0]);
	while (txt[*x])
		(*x)++;
}

char **cpy_map(char **txt, t_point *max)
{
	char	**cpy;
	int		i;
	int		x;
	int		y;

	x = 0;
	y = 0;
	get_len(&x, &y, txt);
	cpy = malloc(sizeof(char *) * (x + 1));
	max->x = x;
	max->y = y;
	i = -1;
	while (txt[++i])
		cpy[i] = ft_strdup(txt[i]);
	cpy[i] = NULL;
	return (cpy);
}

int	ft_fill(char **cpy, int x, int y, t_point max)
{
	int	up;
	int	down;
	int	right;
	int	left;

	if (x < 0 || y < 0 || y >= max.y|| x >= max.x || cpy[x][y] == 1)
		return (0);
	if (cpy[x][y] == 'E')
		return (1);
	cpy[x][y] = '1';
	up = ft_fill(cpy, x - 1, y, max);
	right = ft_fill(cpy, x, y + 1, max);
	left = ft_fill(cpy, x, y - 1, max);
	down = ft_fill(cpy, x + 1, y, max);

	if (up || down || left || right)
		return (1);
	return (0);
}

int flood(char **txt,int x,int y)
{
	t_point	*c;
	t_point	*max;
	char	**cpy;
	int		code;

	c = malloc(sizeof(t_point));
	max = malloc(sizeof(t_point));
	cpy = cpy_map(txt, max);
	code = -5;
	if (ft_fill(cpy, x, y, *max))
	{
		ft_printf("Congratulation, you even have a path from the start to the exit ! ✅");
		code = 1;
	}
	free_all(cpy);
	free(max);
	free(c);
	return (code);
}
