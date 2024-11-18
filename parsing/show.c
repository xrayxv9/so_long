#include "graphics.h"

int	corner(t_game *game, char **txt, int w, int h, t_floor *floor)
{
	t_image img;

	img.image = NULL;
	if (!txt[w][h + 2])
	{
		if (txt[w + 1][h] == '1')
			img.image = floor->corner_right_bot->image;
		else if (txt[w - 1][h] == '1')
			img.image = floor->corner_right_top->image;
	}
	else if (txt[w][h - 1] == '1')
	{
		if (txt[w - 1][h] == '1')
			img.image = floor->corner_left_top->image;
		else if (txt[w + 1][h] == '1')
			img.image = floor->corner_left_bot->image;
	}
	if (img.image)
	{
		mlx_put_image_to_window(game->game, game->win,
				img.image, w * 16, h * 16);
		return (1);
	}
	return (0);
}

void	wall(t_game *game, char **txt, int w, int h, t_floor *floor)
{
	t_image img;

	if (corner(game, txt, w, h, floor))
		return ;
	if (txt[w - 1][h] == 1)
		img.image = floor->top->image;
	else if (txt[w + 1][h] == 1)
		img.image = floor->bot->image;
	else if (txt[w][h + 1] == 1)
		img.image = floor->left->image;
	else if (txt[w][h - 1] == 1)
		img.image = floor->right->image;
	else
		img.image = floor->middle->image;
	mlx_put_image_to_window(game->game, game->win,img.image, w * 16, h * 16);
}
