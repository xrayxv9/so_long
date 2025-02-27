/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:00:35 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/29 09:50:41 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

void	get_len(int *x, int *y, char **txt)
{
	*y = ft_strlen(txt[0]);
	while (txt[*x])
		(*x)++;
}

char	**cpy_map(char **txt)
{
	char	**cpy;
	int		i;
	int		x;
	int		y;

	x = 0;
	y = 0;
	get_len(&x, &y, txt);
	cpy = malloc(sizeof(char *) * (x + 1));
	i = -1;
	while (txt[++i])
		cpy[i] = ft_strdup(txt[i]);
	cpy[i] = NULL;
	return (cpy);
}

int	ft_fill(char **cpy, t_point coo, char c)
{
	if (cpy[coo.x][coo.y] == 'X' || cpy[coo.x][coo.y] == '1')
		return (0);
	if (cpy[coo.x][coo.y] != c)
		cpy[coo.x][coo.y] = 'X';
	ft_fill(cpy, (t_point){coo.x, coo.y + 1}, c);
	ft_fill(cpy, (t_point){coo.x - 1, coo.y}, c);
	ft_fill(cpy, (t_point){coo.x + 1, coo.y}, c);
	ft_fill(cpy, (t_point){coo.x, coo.y - 1}, c);
	if (cpy[coo.x][coo.y] == c)
	{
		cpy[coo.x][coo.y] = 'X';
		return (1);
	}
	return (0);
}

int	ft_check_c(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (-6);
			j++;
		}
		i++;
	}
	return (1);
}

int	flood(char **txt, int x, int y, char ch)
{
	t_point	*c;
	t_point	*max;
	char	**cpy;
	int		code;

	c = malloc(sizeof(t_point));
	if (!c)
		return (0);
	max = malloc(sizeof(t_point));
	if (!c)
		return (0);
	cpy = cpy_map(txt);
	if (!ft_fill(cpy, (t_point){x, y}, ch))
	{
		if (ch == 'E')
			code = -5;
		else if (ch == 'C')
			code = -6;
	}
	code = ft_check_c(cpy);
	free_all(cpy);
	free(max);
	free(c);
	return (code);
}
