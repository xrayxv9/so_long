/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:24:50 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/17 17:44:01 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "graphics.h"
#include "parsing.h"

int	mouse_hook(int button, void *param)
{
	t_mouse	mouse;
	t_image *item;
	t_game *game;

	game = (t_game *)param;
	item = game->images->start_b;
	mlx_mouse_get_pos(game->game, &mouse.w, &mouse.h);
	if ((mouse.w <= (item->w + item->pos_w) && mouse.w >= item->pos_w) &&
		(mouse.h <= (item->h + item->pos_h) && mouse.h >= item->pos_h) && button == 1)
	{
		//game->scene++;
		ft_printf("ca passe !\n");
	}


	return (1);
}
