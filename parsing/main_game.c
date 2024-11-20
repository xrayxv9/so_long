/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:56:32 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/20 12:03:27 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include <stdio.h>

void	show(t_game *game, char **txt, int w, int h)
{
	t_image img;
	t_image	bonus;
	int		player;
	bonus.image = NULL;
	img.image = game->floor->floor.image;
	if (w == game->p1.pos_x && h == game->p1.pos_y)
		player = 1;
	if (txt[w][h] == '1')
		img.image = game->floor->wall.image;
	else if (txt[w][h] == 'C')
		bonus.image = game->floor->coin.image;	
	else if (txt[w][h] == 'E')
		bonus.image = game->floor->trap.image;
	mlx_put_image_to_window(game->game, game->win,img.image, h * 64, w * 64);
	if (bonus.image)
		mlx_put_image_to_window(game->game, game->win,
						  bonus.image, h * 64, w * 64);
	
}

void	init_floor(t_game *game)
{

	game->floor->floor.image = mlx_png_file_to_image(game->game,
										"asset/floor/middle.png",
										&game->floor->floor.w,
										&game->floor->floor.h);	
	game->floor->wall.image = mlx_png_file_to_image(game->game,
										"asset/floor/Water_Middle.png",
										&game->floor->wall.w,
										&game->floor->wall.h);
	game->floor->coin.image = mlx_png_file_to_image(game->game,
									   "asset/floor/coin.png",
										&game->floor->coin.w,
										&game->floor->coin.h);
	game->floor->trap.image = mlx_png_file_to_image(game->game,
										"asset/floor/portal.png",
										&game->floor->trap.w,
										&game->floor->trap.h);
}
void main_game(t_game *game)
{
	int		w;
	int		h;

	w = 0;
	//floor->coin.image = NULL;
	//printf("la\n%p", floor->coin.image);
	if (!game->floor->coin.image)
	{
		printf("ici\n");
		player_init(game);
		init_floor(game);
	}
	while (game->map[w] && !game->refresh)
	{
		h = 0;
		while (game->map[w][h])
		{
			show(game, game->map, w, h);
			h++;
		}
		w++;
	}
	mlx_on_event(game->game, game->win, MLX_KEYDOWN, key_hook, game);
	game->refresh = 1;
}
