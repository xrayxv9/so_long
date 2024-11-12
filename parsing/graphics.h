/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:16:49 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/12 15:49:42 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "../lib/MacroLibX/includes/mlx.h"

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	char	*path;
} t_player;

typedef struct s_ennemie
{
	int		pos_x;
	int		pos_y;
	char	*path;
}	t_ennemie;

typedef struct s_image
{
	int		w;
	int		h;
	int		pos_x;
	int		pos_y;
	void	*image;
}	t_image;

typedef struct s_mouse
{
	int co_x;
	int co_y;
} t_mouse;

typedef struct s_images
{
	t_image	*screen_title;
	t_image	*start_b;
	t_image	*button_param;
}			t_images;

typedef struct s_game
{
	void		*game;
	void		*win;
	char		**map;
	t_player	p1;
	t_ennemie	*en;
	int			w;
	int			h;
	int			scene;
	t_images	*images;
} t_game;

void	core(char **txt);

int		mouse_hook(t_game *game);

#endif
