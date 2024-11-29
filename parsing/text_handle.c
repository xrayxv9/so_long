/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:12:46 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/29 09:39:59 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

int	pre_check(t_checks *tab, char *line)
{
	int			i;
	t_checks	*tmp;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		tmp = ft_find(tab, line[i]);
		if (tmp)
			tmp->value = 1;
		else
			return (0);
		i++;
	}
	return (1);
}

void	free_all(char **txt)
{
	char	**tmp;

	tmp = txt;
	while (*txt)
		free(*txt++);
	free(tmp);
}

char	**fill(char **txt, char *line, int i)
{
	char	**tmp;
	int		j;

	j = 0;
	tmp = malloc(sizeof(char *) * (i + 1));
	while (txt[j])
	{
		tmp[j] = ft_strdup(txt[j]);
		j++;
	}
	tmp[j] = ft_strdup(line);
	j++;
	tmp[j] = NULL;
	free_all(txt);
	return (tmp);
}

char	**get_text(int fd, char **txt)
{
	char		*line;
	t_checks	*tab;
	int			i;

	i = 1;
	line = get_next_line(fd, 0);
	tab = ft_create();
	while (line)
	{
		txt = fill(txt, line, i);
		if (!pre_check(tab, line))
		{
			free(tab);
			free(line);
			get_next_line(fd, 1);
			free_all(txt);
			return (NULL);
		}
		free(line);
		line = get_next_line(fd, 0);
		i++;
	}
	free(line);
	free(tab);
	return (txt);
}
