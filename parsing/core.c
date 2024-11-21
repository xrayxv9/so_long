/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:15:56 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/21 21:59:10 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "graphics.h"
#include "parsing.h"
#include <stdio.h>

int	update(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	main_game(game);
	game->fps++;
	if (game->fps > 80)
		game->fps = 0;
	mlx_on_event(game->game, game->win, MLX_KEYDOWN, key_hook, game);
	collide(game);
	idle_player(game);
	return (0);
}

int	window_hook(int event, void *param)
{
	if (!event)
	{
		mlx_loop_end(((t_game *)param)->game);
	}
	return (1);
}

void	core(char **map)
{
	t_game	game;
	t_floor floor;

	floor.coin.image = NULL;
	floor.trap.image = NULL;
	floor.wall.image = NULL;
	floor.floor.image = NULL;
	floor.closed.image= NULL;
	game.floor = &floor;
	init_game(&game, map);
	mlx_set_font_scale(game.game, game.win, "asset/font/bc.ttf", 50);
	mlx_set_fps_goal(game.game, 60);
	mlx_on_event(game.game, game.win, MLX_WINDOW_EVENT, window_hook, &game);
	mlx_loop_hook(game.game, update, &game);
	mlx_loop(game.game);
	player_destroy(&game);
	floor_destroy(&game);
 	mlx_destroy_window(game.game, game.win);
	mlx_destroy_display(game.game);
}
