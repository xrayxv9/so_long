
#include "graphics.h"

int	ft_itoa(unsigned int n, char *ptr, int l)
{
	int	len;

	len = 1;
	if (ptr)
		ptr[l--] = '\0';
	while (n >= 10)
	{
		if (ptr)
			ptr[l--] = (char)((n % 10) + '0');
		n /= 10;
		len++;
	}
	if (ptr)
		ptr[l] = (char)((n % 10) + '0');
	return (len);
}

void	show_dep(t_game *game)
{
	char	*s2;
	char	*final;
	int		len;
	int		i;

	i = -1;
	len = ft_itoa(game->p1.depla, NULL, 0);
	printf("len : %d\n", len);
	s2 = malloc(sizeof(int) * len);
	if (!s2)
		return ;
	ft_itoa(game->p1.depla, s2, len);
	final = ft_strjoin("move : ", s2);
	while (++i < 10)
		show(game, game->map, 0, i);
	mlx_string_put(game->game, game->win, 0, 32, 0xFFFFFFFF, final);
	free(final);
}
