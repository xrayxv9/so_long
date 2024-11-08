/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:03:49 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/08 13:00:57 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

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
	int			len;
	int			y;
	t_checks	*check;
	int			save;

	y = -1;
	check = ft_create();
	remove_n(txt);
	len = ft_strlen(txt[0]);
	save = len;
	while (txt[++y])
	{
		if (ft_strlen(txt[y]) != len)
			return (0);
		while (len)
		{
			ft_find(check, txt[y][len])->value = 1;
			len--;
		}
		len = save;
	}
	if (!check_truth(check))
		len = -4;
	free(check);
	return (len);
}

int	is_map_framed(char **txt)
{
	int	x;
	int	y;
	int	len;

	len = check_lenght(txt);
	if (len == 0)
		return (-2);
	if (len == -4)
		return (-4);
	x = 0;
	y = -1;
	while (txt[++y])
	{
		if (y == 0 || !txt[y + 1])
		{	
			while (txt[y][x])
				if (txt[y][x++] != '1')
					return (-3);
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
	int	err;

	error = is_map_framed(txt);
	if (error > 0)
			err = certificate_map(txt);
	if (error == -2)
		ft_printf("Error\n❌ The length of one of your line is uncorrect, please verify your map.");
	else if (error == -1)
		ft_printf("Error\n❌ The frame of your map aren't good. Fix it and try again.\n");
	else if (error == -3)
		ft_printf("Error\n❌ The top side or bottom side of your map are not valid ");
	else if (error == -4)
		ft_printf("Error\n❌ The map miss an element out of one of those : P C E 0 1");
	else if (err == -5)
		ft_printf("Error\n❌ The map doesn't have a way to the end from the starting point");
	else
	{
		ft_printf("✅ your map is perfect, nothing to say ! good job !");
		return (1);
	}
	return (0);
}
