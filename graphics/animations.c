/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:52:23 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/25 10:30:17 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "graphics.h"

void	idle_player(t_game *game)
{
	t_anim		a;

	a = game->p1.idle;
	show(game, game->map, game->p1.pos_y, game->p1.pos_x);
	if (game->fps >= 0 && game->fps < 20)
		game->p1.img.image = a.frame1.image;
	else if (game->fps >= 20 && game->fps < 40)
		game->p1.img.image = a.frame2.image;
	else if (game->fps >= 40 && game->fps < 60)
		game->p1.img.image = a.frame3.image;
	else if (game->fps >= 60 && game->fps <= 80)
		game->p1.img.image = a.frame4.image;
	mlx_put_image_to_window(game->game, game->win, game->p1.img.image,
		game->p1.pos_x * 64, game->p1.pos_y * 64);
}
