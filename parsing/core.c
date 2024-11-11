/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:15:56 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/11 17:23:47 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "graphics.h"
#include <threads.h>






int update(void *param)
{
	t_game	*game;

	game = ((t_game *) param);
	mlx_string_put(game->game, game->win, 0, 0, 0xFFFFFF, "QUOICOUBEHHH");
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


void	core(char **txt)
{
	t_game	game; 
	
	game.game = mlx_init();
	game.win = mlx_new_window(game.game, 1920, 1080, "so_long");
	game.map = txt;
	mlx_set_fps_goal(game.game, 60);
	mlx_on_event(game.game, game.win,MLX_WINDOW_EVENT, window_hook, &game);
	mlx_loop_hook(game.game, update, &game);
	mlx_loop(game.game);

	mlx_destroy_window(game.game, game.win);
	mlx_destroy_display(game.game);

}
