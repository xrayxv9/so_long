/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:56:32 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/21 16:00:37 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include <stdio.h>

void	show(t_game *game, char **txt, int w, int h)
{
	void	*img;
	t_image	bonus;

	bonus.image = NULL;
	img = game->floor->floor.image;
	if (txt[w][h] == '1')
		img= game->floor->wall.image;
	else if (txt[w][h] == 'C')
		bonus.image = game->floor->coin.image;	
	else if (txt[w][h] == 'E')
		bonus.image = game->floor->trap.image;
	mlx_put_image_to_window(game->game, game->win,img, h * 64, w * 64);
	if (bonus.image)
		mlx_put_image_to_window(game->game, game->win,
						  bonus.image, h * 64, w * 64);
	
}

void main_game(t_game *game)
{
	int		w;
	int		h;

	w = 0;
	if (!game->floor->coin.image)
	{
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
	game->refresh = 1;
}
