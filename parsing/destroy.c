/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:52:28 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/21 16:23:59 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "graphics.h"

void	player_destroy(t_game *game)
{
	mlx_destroy_image(game->game, game->p1.idle.frame1.image);
	mlx_destroy_image(game->game, game->p1.idle.frame2.image);
	mlx_destroy_image(game->game, game->p1.idle.frame3.image);
	mlx_destroy_image(game->game, game->p1.idle.frame4.image);
}

void	floor_destroy(t_game *game)
{
	mlx_destroy_image(game->game, game->floor->floor.image);
	mlx_destroy_image(game->game, game->floor->wall.image);
	mlx_destroy_image(game->game, game->floor->trap.image);
	mlx_destroy_image(game->game, game->floor->coin.image);

}
