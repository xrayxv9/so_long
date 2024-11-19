/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:15:56 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/19 15:56:11 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "graphics.h"
#include <math.h>

t_game	init_game(t_game *game, char **map)
{
	t_image	images;
	int			i;

	i = 0;
	while (map[i])
		i++;
	game->refresh = 0;
	game->game = &images;
	game->h = i * 64;
	game->w = ft_strlen(map[0]) * 64;
	game->game = mlx_init();
	game->win = mlx_new_window(game->game, game->w, game->h, "so_long");
	game->map = map;
	game->p1.img.image = mlx_png_file_to_image(game->game, "asset/",
											&game->p1.img.w,
											&game->p1.img.h);
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
	t_floor floor;

	init_game(&game, map);
	mlx_set_fps_goal(game.game, 60);
	main_game(&game, &floor);
	mlx_on_event(game.game, game.win, MLX_WINDOW_EVENT, window_hook, &game);
	mlx_loop_hook(game.game, update, &game);
	mlx_loop(game.game);
	mlx_destroy_image(game.game, floor.floor.image);
	mlx_destroy_image(game.game, floor.coin.image);
	mlx_destroy_image(game.game, floor.trap.image);
	mlx_destroy_image(game.game, floor.wall.image);
	mlx_destroy_image(game.game, game.p1.img.image);
	mlx_destroy_window(game.game, game.win);
	mlx_destroy_display(game.game);
}
