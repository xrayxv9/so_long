#include "graphics.h"

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
	else if (txt[w][h - 1] == '1')
	{
		if (txt[w - 1][h] == '1')
			mlx_put_image_to_window(game->game, game->win,
					floor->corner_left_top->image, w * 16, h * 16);
		else if (txt[w + 1][h] == '1')
			mlx_put_image_to_window(game->game, game->win,
				floor->corner_left_bot->image, w * 16, h * 16);
		else 
			mlx_put_image_to_window(game->game, game->win,
					floor->left->image, w * 16, h * 16);
	}
}

void print_map(t_game *game, char **txt, int modifier)
{
	t_floor floor;
	int		w;
	int		h;

	w = 0;
	h = 0;
	init_floor(game, &floor);
	floor.middle->image = mlx_png_file_to_image(game->game,
			"asset/floor/middle.png", &floor.middle->w, &floor.middle->h);
	// remains to to the while loop that will print the whole map
	// Next I have to add the new files to my Makefile
	// Plus I still have to put my functions in the .h file (not sure it's already done)
	// GL HF
}

void main_game(t_game *game, char **txt)
{
	print_map(game, txt);
}
