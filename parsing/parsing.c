/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:03:49 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/22 12:37:40 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

void	remove_n(char **txt)
{
	int	i;
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
					return (-2);
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
		ft_printf("Error\n❌ Incorrect line lenght, please verify your map.\n");
	else if (error == -1)
		ft_printf("Error\n❌ Your map isn't framed correctlty.\n");
	else if (error == -4)
		ft_printf("Error\n❌ The map miss an element between : P C E 0 1.\n");
	else if (err == -5)
		ft_printf("Error\n❌ There are to valid path to the end.\n");
	else if (err == -6)
		ft_printf("Error\n❌ The map miss/can't reach, collectibles.\n");
	else
	{
		ft_printf("✅ Congratulations ! yout map has everything required !\n");
		return (1);
	}
	return (0);
}
