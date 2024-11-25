/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:35:38 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/25 17:29:20 by cmorel           ###   ########.fr       */
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
	while (s[i] && s[i] == '.')
		i++;
	while (s[i + j])
	{
		if (s[i + j] != t[j])
			return (0);
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
		ft_printf("Error\n The map didn't open please check if the map exists.");
		return (0);
	}
	return (fd);
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
	if (check_file(argv[1]))
		return (-1);
	fd = tests(argv[1]);
	if (fd < 0)
		return (-1);
	txt = malloc (1 * sizeof(char *));
	txt[0] = NULL;
	txt = get_text(fd, txt);
	result = parsing(txt);
	if (result)
		core(txt);
	free_all(txt);
}
