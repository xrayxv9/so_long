/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:24:50 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/12 15:49:32 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "graphics.h"
#include "parsing.h"

int	mouse_hook(t_game *game)
{
	t_mouse	mouse;
	t_image *item;

	item = game->images->start_b;
	mlx_mouse_get_pos(game->game, &mouse.co_x, &mouse.co_y);
	if (game->scene == 1)
	{
		if ((mouse.co_x <= item->w&& mouse.co_x >= item->pos_x) &&
		(mouse.co_y <= item->h && mouse.co_y >= item->pos_y))
			ft_printf("GG le zgeg");
	}
}
