/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:24:50 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/20 15:19:54 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "graphics.h"
#include "parsing.h"

void key_hook_next(int key, t_game *game, int w, int h)
{
	if (key == S_KEY)
	{
		if (game->map[w + 1][h])
		{
			game->p1.depla++;
			game->p1.pos_x += 64;
		}
	}

	else if (key == D_KEY)
	{
		if (game->map[w][(h) + 1])
		{
			game->p1.depla++;
			game->p1.pos_y += 64;
		}
	}

}

int	key_hook(int key, void *param)
{
	t_game	*game;
	int		w;
	int		h;

	game = (t_game *)param;
	w = game->p1.pos_x / 64;
	h = game->p1.pos_y / 64;
	if (key == W_KEY)
	{
		if (game->map[w - 1][h] != '1')
		{
			game->p1.depla++;
			game->p1.pos_x -= 64;
		}	
	}
	else if (key == A_KEY)
	{
		if (game->map[w][(h) - 1] != '1')
		{
			game->p1.depla++;
			game->p1.pos_y -= 64;

		}
	}
	key_hook_next(key, game, w, h);
	return (0);
}
