/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:15:56 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/19 14:24:33 by cmorel           ###   ########.fr       */
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

	game = ((t_game *) param);
	(void)game;
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

	init_game(&game, map);
	mlx_set_fps_goal(game.game, 60);
	main_game(&game);
	mlx_on_event(game.game, game.win, MLX_WINDOW_EVENT, window_hook, &game);
	mlx_loop_hook(game.game, update, &game);
	mlx_loop(game.game);
	mlx_destroy_window(game.game, game.win);
	mlx_destroy_display(game.game);
}
