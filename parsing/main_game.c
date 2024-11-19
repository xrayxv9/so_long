/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:56:32 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/19 14:46:41 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include <stdio.h>

void	show(t_game *game, char **txt, int w, int h, t_floor *floor)
{
	t_image img;
	t_image	bonus;

	bonus.image = NULL;
	img.image = floor->floor.image;
	if (txt[w][h] == 1)
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
void main_game(t_game *game)
{
	t_floor floor;
	int		w;
	int		h;

	w = 0;
	init_floor(game, &floor);
	while (game->map[w])
	{
		h = 0;
		while (game->map[w][h])
		{
			show(game, game->map, w, h, &floor);
			printf("%d\n", h);

			h++;
		
		}
		printf("_______________________________________________\n");
		printf("%d\n", w);

		w++;
	}
		printf("%d\n", w);

}
