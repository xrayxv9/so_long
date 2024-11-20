/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:52:23 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/20 14:20:03 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "graphics.h"
#include <stdio.h>

void	player_init(t_game *game)
{
	t_anim		*idle;
	t_player	*p1;

	p1 = &game->p1;
	idle = &p1->idle;
	idle->frame1.image = mlx_png_file_to_image(game->game,
											"asset/player/idle1.png",
											&p1->pos_x, &p1->pos_y);
	idle->frame2.image = mlx_png_file_to_image(game->game,
											"asset/player/idle2.png",
											&p1->pos_x, &p1->pos_y);
	idle->frame3.image = mlx_png_file_to_image(game->game,
										   "asset/player/idle3.png",
											&p1->pos_x, &p1->pos_y);
	idle->frame4.image = mlx_png_file_to_image(game->game,
										   "asset/player/idle4.png",
										   &p1->pos_x, &p1->pos_y);
	p1->img.image = idle->frame1.image;
}

void	player_destroy(t_game *game)
{
	t_anim	a;

	a = game->p1.idle;
	mlx_destroy_image(game->game, a.frame1.image);
	mlx_destroy_image(game->game, a.frame2.image);
	mlx_destroy_image(game->game, a.frame3.image);
	mlx_destroy_image(game->game, a.frame4.image);
}

void	idle_player(t_game *game)
{
	t_anim		a;

	a = game->p1.idle;
	show(game, game->map, game->p1.pos_x / 64, game->p1.pos_y / 64);
	if (game->fps >= 0 && game->fps < 20)
		game->p1.img.image = a.frame1.image;
	else if (game->fps >= 20 && game->fps < 40)
		game->p1.img.image = a.frame2.image;
	else if (game->fps >= 40 && game->fps < 60)
		game->p1.img.image = a.frame3.image;
	else if (game->fps >= 60 && game->fps <= 80)
		game->p1.img.image = a.frame4.image;
	mlx_put_image_to_window(game->game, game->win, game->p1.img.image,
						 game->p1.pos_x, game->p1.pos_y);
}
