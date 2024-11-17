/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:16:49 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/14 19:17:04 by xray             ###   ########.fr       */
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
	int		pos_w;
	int		pos_h;
	void	*image;
}	t_image;

typedef struct s_mouse
{
	int w;
	int h;
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

int		mouse_hook(int button, void *param);

#endif
