/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:07:21 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/22 12:14:55 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "graphics.h"

void	player_init(t_game *game)
{
	game->p1.depla = 0;
	game->p1.idle.frame1.image = mlx_png_file_to_image(game->game,
			"asset/player/idle1.png", &game->p1.idle.frame1.pos_w,
			&game->p1.idle.frame1.pos_h);
	game->p1.idle.frame2.image = mlx_png_file_to_image(game->game,
			"asset/player/idle2.png", &game->p1.idle.frame2.pos_w,
			&game->p1.idle.frame2.pos_h);
	game->p1.idle.frame3.image = mlx_png_file_to_image(game->game,
			"asset/player/idle3.png", &game->p1.idle.frame3.pos_w,
			&game->p1.idle.frame3.pos_h);
	game->p1.idle.frame4.image = mlx_png_file_to_image(game->game,
			"asset/player/idle4.png", &game->p1.idle.frame4.pos_w,
			&game->p1.idle.frame4.pos_h);
	game->p1.img.image = game->p1.idle.frame1.image;
}

void	init_floor(t_game *game)
{
	game->floor->floor.image = mlx_png_file_to_image(game->game,
			"asset/floor/middle.png",
			&game->floor->floor.w, &game->floor->floor.h);
	game->floor->wall.image = mlx_png_file_to_image(game->game,
			"asset/floor/Water_Middle.png",
			&game->floor->wall.w, &game->floor->wall.h);
	game->floor->coin.image = mlx_png_file_to_image(game->game,
			"asset/floor/coin.png",
			&game->floor->coin.w, &game->floor->coin.h);
	game->floor->trap.image = mlx_png_file_to_image(game->game,
			"asset/floor/portal.png",
			&game->floor->trap.w, &game->floor->trap.h);
	game->floor->closed.image = mlx_png_file_to_image(game->game,
			"asset/floor/closed_portal.png",
			&game->floor->closed.w, &game->floor->closed.h);
}

t_game	init_game(t_game *game, char **map)
{
	t_image		images;
	t_player	p1;
	int			i;

	i = 0;
	p1.pos_x = 0;
	p1.pos_y = 0;
	while (map[i])
		i++;
	game->end = 0;
	game->fps = 0;
	game->refresh = 0;
	game->game = &images;
	game->h = i * 64;
	game->w = ft_strlen(map[0]) * 64;
	game->game = mlx_init();
	game->win = mlx_new_window(game->game, game->w, game->h, "so_long");
	game->map = map;
	find_p(game->map, &p1.pos_y, &p1.pos_x);
	game->p1 = p1;
	return (*game);
}
