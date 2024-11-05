#include "parsing.h"
#include "get_next_line.h"

void	remove_n(char **txt)
{
	int i;
	int	j;

	i = 0;
	while (txt[i])
	{
		j = 0;
		while (txt[i][j] && txt[i][j] != '\n')
			j++;
		if (txt[i][j] == '\n')
			txt[i][j] = '\0';
		i++;
	}
}

int	check_lenght(char **txt)
{
	int len;
	int y;

	y = 0;
	remove_n(txt);
	len = ft_strlen(txt[y]);
	while (txt[y])
	{
		if (ft_strlen(txt[y]) != len)
			return (0);
		y++;
	}
	return (len);
}

int	is_map_framed(char **txt)
{
	int	x;
	int	y;
	int	len;

	len = check_lenght(txt);
	if (!len)
		return (-2);
	x = 0;
	y = -1;
	while (txt[++y])
	{
		if (y == 0 || !txt[y + 1])
		{
			while (txt[y][x])
			{
				if (txt[y][x] != '1')
					return (-3);
				x++;
			}
		}
		else
			if (txt[y][0] != '1' || txt[y][len - 1] != '1')
				return (-1);
	}
	return (1);
}

int	parsing(char **txt)
{
	int	error;

	error = is_map_framed(txt);
	if (error == -2)
	{
		printf("❌ The length of one of your line is uncorrect, please verify your map.");
		return (0);
	}
	else if (error == -1)
	{
		printf("❌ The frame of your map aren't good. Fix it and try again.\n");
		return (0);
	}
	else if (error == -3)
	{
		printf("❌ The top side or bottom side of your map are not valid ");
		return (0);
	}
	else
	{
		printf("✅ your map is perfect, nothing to say ! good job !");
		return (1);
	}
}
