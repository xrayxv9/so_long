/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:15:56 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/12 15:51:31 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "graphics.h"

t_game	init_game(t_game *game, char **map)
{
	t_images	images;

	game->game = &images;
	game->scene = 1;
	game->h = 1024;
	game->w = 1024;
	game->game = mlx_init();
	game->win = mlx_new_window(game->game, game->w, game->h, "so_long");
	game->map = map;
	return (*game);
}

void	init_title_screen(t_game *game)
{
	mlx_set_font_scale(game->game, game->win, "asset/font/bc.ttf", 100);
	mlx_string_put(game->game, game->win, game->w / (2.3),
		game->h / (6), 0xFFFFFFFF, "So_long");
	game->images->start_b->image = mlx_png_file_to_image(game->game,
			"asset/title_screen/btn_click.png", &game->images->start_b->w,
			&game->images->start_b->h);
	game->images->screen_title->image = mlx_png_file_to_image(game->game,
			"asset/title_screen/preview.png", &game->images->screen_title->w,
			&game->images->screen_title->h);
	game->images->screen_title->pos_x = 0;
	game->images->screen_title->pos_y = 0;
	mlx_put_image_to_window(game->game, game->win,
		game->images->screen_title->image, 0, 0);
	game->images->start_b->pos_x = game->w / 3.1;
	game->images->start_b->pos_x = game->h / 2.1;

	mlx_put_image_to_window(game->game, game->win,
		game->images->start_b->image, game->images->start_b->pos_x,
		game->images->start_b->pos_y / 2.1);
	mlx_on_event(game->game, game->win, MLX_MOUSEDOWN, mouse_hook, game);
}

int	update(void *param)
{
	t_game	*game;

	game = ((t_game *) param);
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
	if (game.scene == 1)
		init_title_screen(&game);
	mlx_on_event(game.game, game.win, MLX_WINDOW_EVENT, window_hook, &game);
	mlx_loop_hook(game.game, update, &game);
	mlx_loop(game.game);
	mlx_destroy_window(game.game, game.win);
	mlx_destroy_image(game.game, game.images->start_b->image);
	mlx_destroy_image(game.game, game.images->screen_title->image);
	mlx_destroy_display(game.game);
}
