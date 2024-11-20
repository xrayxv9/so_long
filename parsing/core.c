/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:15:56 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/20 13:47:23 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "graphics.h"
#include <stdio.h>



t_game	init_game(t_game *game, char **map)
{
	t_image	images;
	int			i;
	 
	i = 0;
	while (map[i])
		i++;
	game->fps = 0;
	game->refresh = 0;
	game->game = &images;
	game->h = i * 64;
	game->w = ft_strlen(map[0]) * 64;
	game->game = mlx_init();
	game->win = mlx_new_window(game->game, game->w, game->h, "so_long");
	game->map = map;
	return (*game);
}

int	update(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	main_game(game);
	
	game->fps++;
	if (game->fps > 80)
		game->fps = 0;
	printf("_________________________\n");
	printf("fps : %d\n", game->fps);
	mlx_on_event(game->game, game->win, MLX_KEYDOWN, key_hook, game);

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
	game.floor = &floor;
	init_game(&game, map);
	mlx_set_fps_goal(game.game, 60);
	mlx_on_event(game.game, game.win, MLX_WINDOW_EVENT, window_hook, &game);
	mlx_loop_hook(game.game, update, &game);
	mlx_loop(game.game);
	player_destroy(&game);
	mlx_destroy_image(game.game, game.p1.img.image);
	mlx_destroy_window(game.game, game.win);
	mlx_destroy_display(game.game);
}
