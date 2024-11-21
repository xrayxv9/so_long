/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:24:50 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/21 15:48:36 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "graphics.h"
#include "parsing.h"

void key_hook_next(int key, t_game *game, int w, int h)
{
	if (key == S_KEY)
	{
		show(game, game->map, game->p1.pos_y, game->p1.pos_x);
		if (game->map[h + 1][w] != '1')
		{
			game->p1.depla++;
			game->p1.pos_y += 1;
		}
	}

	else if (key == D_KEY)
	{
		show(game, game->map, game->p1.pos_y, game->p1.pos_x);
		if (game->map[h][w + 1] != '1')
		{
			game->p1.depla++;
			game->p1.pos_x += 1;
		}
	}
	else if (key == ESC_KEY)
		mlx_loop_end(game->game);
}

int	key_hook(int key, void *param)
{
	t_game	*game;
	int		w;
	int		h;

	game = (t_game *)param;
	w = game->p1.pos_x;
	h = game->p1.pos_y;
	if (key == W_KEY)
	{
		show(game, game->map, game->p1.pos_y, game->p1.pos_x);
		if (game->map[h - 1][w] != '1')
		{
			game->p1.depla++;
			game->p1.pos_y -= 1;
		}	
	}
	else if (key == A_KEY)
	{
		show(game, game->map, game->p1.pos_y, game->p1.pos_x);
		if (game->map[h][w - 1] != '1')
		{
			game->p1.depla++;
			game->p1.pos_x -= 1;
		}
	}
	key_hook_next(key, game, w, h);
	return (0);
}
