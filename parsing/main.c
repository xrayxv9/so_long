/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:35:38 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/29 09:59:46 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../graphics/graphics.h"
#include "parsing.h"
#include <fcntl.h>

int	check_file(char *s)
{
	int		i;
	char	*t;
	int		j;

	i = 0;
	j = 0;
	t = "ber";
	while (s[i] && s[i] != '.')
		i++;
	if (s[i] == '.')
		i++;
	while (s[i + j])
	{
		if (s[i + j] != t[j])
		{
			ft_printf("Error\n Only the .ber is accepted for the map.");
			return (0);
		}
		j++;
	}
	return (1);
}

int	tests(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n The map couldn'r be opened.");
		return (0);
	}
	return (fd);
}

int	double_exit(char **map)
{
	int	i;
	int	j;
	int	exit;

	i = 0;
	exit = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				if (exit)
				{
					ft_printf("Error\n Only one exit is expected");
					return (0);
				}
				exit = 1;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	error(void)
{
	ft_printf("Error\n The map has an unexpected character");
	return (-1);
}

int	main(int argc, char **argv)
{
	int			fd;
	int			result;
	char		**txt;

	if (argc != 2)
	{
		ft_printf("Error\n One map is expected.");
		return (0);
	}
	if (!check_file(argv[1]))
		return (-1);
	fd = tests(argv[1]);
	if (fd < 0)
		return (-1);
	txt = malloc (1 * sizeof(char *));
	txt[0] = NULL;
	txt = get_text(fd, txt);
	if (!txt)
		return (error());
	result = parsing(txt);
	if (result && double_exit(txt))
		core(txt);
	free_all(txt);
}
