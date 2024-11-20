/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:24:50 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/20 09:23:01 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "graphics.h"
#include "parsing.h"

int	key_hook(int key, void *param)
{
	t_game *game;
	
	game = (t_game *)param;
	if (key == 'w')
	{
		printf("blurg");
		return (1);
	}
	return (0);
}
