#include "parsing.h"
#include "get_next_line.h"

void	remove_n(char **txt)
{
	int	len;
	int i;

	i = 0;
	while (txt[i])
	{
		len = ft_strlen(txt[i]);
		if (txt[i][len] == '\n')
			txt[i][len] = '\0';
		i++;
	}
}

int	check_lenght(char **txt)
{
	int len;
	int y;

	y = 0;
	len = ft_strlen(txt[y]);
	if (txt[y][len] == '\n')
		len--;
	while (txt[y])
	{
		y++;
		if (ft_strlen(txt[y]) != len)
			return (0);
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
		return (0);
	x = 0;
	y = 0;
	while (txt[y])
	{
		if (y == 0 || !txt[y + 1])
		{
			while (txt[y][x] && txt[y][x] != '\n')
			{
				if (txt[y][x] != '1')
					return (0);
				x++;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
			}
		}
		else
			if (txt[y][0] != '1' || txt[y][len] != '1')
				return (0);
	}
	return (1);
}

int path_finder(char **txt, int main, int sub)
{
	return (0);	
}


int	parsing(int fd)
{
	char	**txt;
	int		res;

	txt = malloc(sizeof(char *) * 1);
	txt[0] = NULL;
	txt = get_text(fd, txt);
	res = path_finder(txt, 0, int sub)
	free_all(txt);
	return (1);
}
