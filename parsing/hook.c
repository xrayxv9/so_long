/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:24:50 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/21 20:55:47 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "graphics.h"
#include "parsing.h"

void key_hook_next(int key, t_game *game)
{
	if (key == S_KEY)
	{
		if (game->map[game->p1.pos_y + 1][game->p1.pos_x] != '1')
			game->p1.pos_y += 1;
	}
	else if (key == D_KEY)
	{
		if (game->map[game->p1.pos_y][game->p1.pos_x + 1] != '1')
			game->p1.pos_x += 1;
	}
}

int	first_keys(int key, t_game *game)
{
	if (key == W_KEY)
	{
		if (game->map[game->p1.pos_y - 1][game->p1.pos_x] != '1')
			game->p1.pos_y -= 1;
	}
	else if (key == A_KEY)
	{
		if (game->map[game->p1.pos_y][game->p1.pos_x - 1] != '1')
			game->p1.pos_x -= 1;
	}
	key_hook_next(key, game);
	return (0);
}

int	key_hook(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key == A_KEY || key == W_KEY || key == S_KEY || key == D_KEY)
	{
		show(game, game->map, game->p1.pos_y, game->p1.pos_x);
		game->p1.depla++;
		first_keys(key, game);
		show_dep(game);
	}
	else if (key == ESC_KEY)
		mlx_loop_end(game->game);
	return (0);
} 
