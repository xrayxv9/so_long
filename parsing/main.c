/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:35:38 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/25 11:22:53 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../graphics/graphics.h"
#include "parsing.h"

int	main(int argc, char **argv)
{
	const char	*path;
	int			fd;
	int			result;
	char		**txt;

	if (argc != 2)
	{
		ft_printf("Error\n One map is expected.");
		return (0);
	}
	path = argv[1];
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\n The map didn't open please check if the map exists.");
		return (-1);
	}
	txt = malloc (1 * sizeof(char *));
	txt[0] = NULL;
	txt = get_text(fd, txt);
	result = parsing(txt);
	if (result)
		core(txt);
	free_all(txt);
}
