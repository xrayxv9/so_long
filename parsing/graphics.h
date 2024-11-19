/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:16:49 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/19 15:56:05 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "../lib/MacroLibX/includes/mlx.h"
# include "../lib/get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_image
{
	int		w;
	int		h;
	int		pos_w;
	int		pos_h;
	void	*image;
}	t_image;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	int		depla;
	t_image img;
} t_player;

typedef struct s_floor
{
	t_image	coin;
	t_image	floor;
	t_image wall;
	t_image	trap;
}	t_floor;

typedef struct s_mouse
{
	int w;
	int h;
} t_mouse;

typedef struct s_game
{
	void		*game;
	void		*win;
	char		**map;
	t_player	p1;
	int			w;
	int			h;
	int			refresh;
} t_game;

void	core(char **txt);

int		mouse_hook(int button, void *param);

void	wall(t_game *game, char **txt, int w, int h, t_floor *floor);

void	main_game(t_game *game, t_floor *floor);

int		key_hook(int key, void *param);

#endif
