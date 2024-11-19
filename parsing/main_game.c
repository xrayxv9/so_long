/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:56:32 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/19 15:56:09 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include <stdio.h>

void	show(t_game *game, char **txt, int w, int h, t_floor *floor)
{
	t_image img;
	t_image	bonus;
	int		player;
	bonus.image = NULL;
	img.image = floor->floor.image;
	if (w == game->p1.pos_x && h == game->p1.pos_y)
		player = 1;
	if (txt[w][h] == '1')
		img.image = floor->wall.image;
	else if (txt[w][h] == 'C')
		bonus.image = floor->coin.image;	
	else if (txt[w][h] == 'E')
		bonus.image = floor->trap.image;
	mlx_put_image_to_window(game->game, game->win,img.image, h * 64, w * 64);
	if (bonus.image)
		mlx_put_image_to_window(game->game, game->win,
						  bonus.image, h * 64, w * 64);
	
}

void	init_floor(t_game *game, t_floor *floor)
{
	floor->floor.image = mlx_png_file_to_image(game->game,
										"asset/floor/middle.png",
										&floor->floor.w, &floor->floor.h);	
	floor->wall.image = mlx_png_file_to_image(game->game,
										"asset/floor/Water_Middle.png",
										&floor->wall.w, &floor->wall.h);
	floor->coin.image = mlx_png_file_to_image(game->game,
										   "asset/floor/coin.png",
										   &floor->coin.w, &floor->coin.h);
	floor->trap.image = mlx_png_file_to_image(game->game,
										   "asset/floor/portal.png",
										   &floor->trap.w, &floor->trap.h);
}
void main_game(t_game *game, t_floor *floor)
{
	int		w;
	int		h;

	w = 0;
	init_floor(game, floor);
	while (game->map[w] && !game->refresh)
	{
		h = 0;
		while (game->map[w][h])
		{
			show(game, game->map, w, h, floor);
			h++;
		}
		w++;
	}
	mlx_on_event(game->game, game->win, MLX_KEYDOWN, key_hook, game);
	game->refresh = 1;
}
