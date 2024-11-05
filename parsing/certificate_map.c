/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   certificate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:31:07 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/05 13:53:28 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "parsing.h"

void	find_p(char **txt, int *x, int *y)
{
	while (txt[*x])
	{
		(*x)++;

	}
}


int check_directions(char **txt, )
{

}


int	certificate_map(int fd)
{
	char	**txt;
	int		x;
	int		y;

	x = 0;
	y = 0;
	txt = malloc(1);
	txt[0] = NULL;
	txt = get_text(fd, txt);
	if (!txt)
		return (0);
	if (!parsing(txt))
	{
		free_all(txt);
		return (0);
	}
	find_p(txt, &x, &y);




	return (1);

}

*/
