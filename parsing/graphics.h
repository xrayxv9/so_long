/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:16:49 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/22 12:30:46 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "../lib/MacroLibX/includes/mlx.h"
# include "../lib/get_next_line/get_next_line.h"
# include "parsing.h"
# include <unistd.h>
# include <stdlib.h>

# define S_KEY 22
# define D_KEY 7
# define W_KEY 26
# define A_KEY 4
# define ESC_KEY 41

typedef struct s_image
{
	int		w;
	int		h;
	int		pos_w;
	int		pos_h;
	void	*image;
}	t_image;

typedef struct s_anim
{
	t_image	frame1;
	t_image	frame2;
	t_image	frame3;
	t_image	frame4;
	t_image	frame5;
	t_image	frame6;
	t_image	frame7;
	t_image	frame8;
}	t_anim;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	int		depla;
	t_anim	idle;
	t_anim	running;
	t_image	img;
	int		end;
}			t_player;

typedef struct s_floor
{
	t_image	coin;
	t_image	floor;
	t_image	wall;
	t_image	trap;
	t_image	closed;
}			t_floor;

typedef struct s_mouse
{
	int	w;
	int	h;
}		t_mouse;

typedef struct s_game
{
	void		*game;
	void		*win;
	char		**map;
	t_player	p1;
	int			w;
	int			h;
	int			refresh;
	int			fps;
	t_floor		*floor;
	int			end;
}				t_game;

t_game	init_game(t_game *game, char **map);

void	core(char **txt);

int		mouse_hook(int button, void *param);

void	main_game(t_game *game);

int		key_hook(int key, void *param);

void	idle_player(t_game *game);

void	player_init(t_game *game);

void	player_destroy(t_game *game);

void	show(t_game *game, char **txt, int w, int h);

void	collide(t_game *game);

void	show_dep(t_game *game);

void	init_floor(t_game *game);

void	player_destroy(t_game *game);

void	floor_destroy(t_game *game);

void	player_init(t_game *game);

#endif
