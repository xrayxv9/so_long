#include "graphics.h"
#include <cmath>

void	init_floor(t_game *game, t_floor *floor)
{
	floor->bot->image = mlx_png_file_to_image(game->game,
			"asset/floor/bot.png",
			&floor->bot->w, &floor->bot->h);
	floor->top->image = mlx_png_file_to_image(game->game,
			"asset/floor/top.png",
			&floor->top->w, &floor->top->h);
	floor->left->image = mlx_png_file_to_image(game->game,
			"asset/floor/left.png",
			&floor->left->w, &floor->left->h);
	floor->right->image = mlx_png_file_to_image(game->game,
			"asset/floor/right.png",
			&floor->right->w, &floor->right->h);
	floor->corner_left_bot->image = mlx_png_file_to_image(game->game,
			"asset/floor/corner_left_bot.png", 
			&floor->corner_left_bot->w, &floor->corner_left_bot->h);
	floor->corner_left_top->image = mlx_png_file_to_image(game->game,
			"asset/floor/corner_left_top.png",
			&floor->corner_left_top->w, &floor->corner_left_top->h);
	floor->corner_right_bot->image = mlx_png_file_to_image(game->game,
			"asset/floor/corner_right_bot.png",
			&floor->corner_right_bot->w, &floor->corner_right_bot->h);
	floor->corner_right_top->image = mlx_png_file_to_image(game->game,
			"asset/floor/corner_rigt_top.png",
			&floor->corner_right_top->w, &floor->corner_right_top->h);
}

void wall(t_game *game, char **txt, int w, int h, t_floor *floor)
{
	if (!txt[w][h + 2])
	{
		if (txt[w + 1][h] == '1')
			mlx_put_image_to_window(game->game, game->win,
					floor->corner_right_bot->image, w * 16, h * 16);
		else if (txt[w - 1][h] == '1')
			mlx_put_image_to_window(game->game, game->win,
					floor->corner_right_top->image, w * 16, h * 16);
		else
			mlx_put_image_to_window(game->game, game->win,
					floor->right->image, w * 16, h * 16);
	}
	else if (!txt)
	{

	}
}

void print_map(t_game *game, char **txt)
{
	t_floor floor;
	
	init_floor(game, &floor);
	while()
}

void main_game(t_game *game, char **txt)
{
	print_map(game, txt);
}
