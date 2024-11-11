/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:16:49 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/11 15:04:03 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "../lib/MacroLibX/includes/mlx.h"

typedef struct s_player
{
	int pos_x;
	int pos_y;
	char *path;
} t_player;

typedef struct s_ennemie
{
	int pos_x;
	int pos_y;
	char *path;
}	t_ennemie;

typedef struct s_game
{
	void *game;
	void *win;
	char **map;
	t_player p1;
	t_ennemie *en;
} t_game;

void	core(char **txt);

#endif
