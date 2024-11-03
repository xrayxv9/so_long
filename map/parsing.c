// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   parsing.c                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2024/10/31 21:18:50 by xray              #+#    #+#             //
//   Updated: 2024/11/03 19:16:24 by xray             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include "get_next_line.h"
#include "parsing.h"

/*
	 il faut que je fasse un tableau de toutes les lignes que j'ai recup
	 grace a ca je pourrais en suite  faire un backtracking
	 le backtracking me servira a check que oui ou non il y a bien un chemin qui existe 
	 pour finir la map
*/


int parse(t_checks *tab, char *line)
{
	int			i;
	t_checks	*tmp;
	
	i = 0;
	while (line[i])
	{
		tmp = find(tab, line[i]);
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
	while (*txt)
		free(*txt++);
	free(txt);
}

// fill the tmp with txt + line = NULL
char **fill(char **txt, char *line, int i)
{
	char	**tmp;

	tmp = malloc(sizeof(char *) * (i + 1));
	while (*txt)
	{
		printf("test \n");
		*tmp = ft_strdup(*txt);
		tmp++;
		txt++;
	}
	*tmp = ft_strdup(line);
	tmp++;
	*tmp = NULL;
	free_all(txt);
	return (tmp);
}

char	**parsing(int fd, char **txt)
{
	char		*line;
	t_checks	*tab;
	int			i;

	i = 1;
	line = get_next_line(fd);
	tab = create();
	while (line)
	{
		txt = fill(txt, line, i);
		printf("passage n %d\n", i);
		free(line);
		printf("oh non..\n");
		line = get_next_line(fd);
		printf("pitie pas mon gnl\n");
		if (!parse(tab, line))
		{
			free(tab);
			free(line);
			free_all(txt);
			return (NULL);
		}
	}
	free(line);
	return (txt);
}
