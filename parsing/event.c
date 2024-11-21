/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:57:43 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/21 22:00:50 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "graphics.h"

static void	check_c(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				return ;
			j++;
		}
		i++;
	}
	game->end = 1;
	game->refresh = 0;
}

void collide(t_game *game)
{
	if (game->map[game->p1.pos_y][game->p1.pos_x] == 'C')
	{
		game->map[game->p1.pos_y][game->p1.pos_x] = '0';
		check_c(game);
	}
	else if (game->map[game->p1.pos_y][game->p1.pos_x] == 'E' && game->end)
		mlx_loop_end(game->game);
}
