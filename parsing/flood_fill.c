/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:00:35 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/08 16:27:59 by cmorel           ###   ########.fr       */
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

int	ft_fill(char **cpy, t_point c, t_point max)
{
	int	up;
	int	down;
	int	right;
	int	left;

	if (cpy[c.x][c.y] == 'E')
		return (1);
	if (c.x == 0 || c.y == 0 || c.y == max.y || c.x == max.x || cpy[c.x][c.y] == 1)
		return (0);
	cpy[c.x][c.y] = '1';
	up = ft_fill(cpy, (t_point){c.x - 1, c.y}, max);
	right = ft_fill(cpy, (t_point){c.x, c.y + 1}, max);
	left = ft_fill(cpy, (t_point){c.x - 1, c.y - 1}, max);
	down = ft_fill(cpy, (t_point){c.x + 1, c.y}, max);

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
	c->x = x;
	c->y = y;
	cpy = cpy_map(txt, max);
	code = -5;
	if (ft_fill(cpy, *c, *max))
	{
		ft_printf("Congratulation, you even have a path from the start to the exit ! ✅");
		code = 1;
	}
	free_all(cpy);
	free(max);
	free(c);
	return (code);
}
