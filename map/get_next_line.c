/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:22:39 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/03 21:13:20 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
static int	fill(char **buffer, int fd)
{
	int	run;

	run = 0;
	*buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (-2);
	run = read(fd, *buffer, BUFFER_SIZE);
	return (run);
}

static char	*read_line(int fd, char *buffer)
{
	int		run;
	char	*line;
	char	*tmp;

	run = 1;
	while (run > 0)
	{
		run = fill(&line, fd);
		if (run < 0)
		{
			if (run != -2)
				free(line);
			free(buffer);
			return (NULL);
		}
		tmp = ft_strdup(buffer);
		free(buffer);
		buffer = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
		if (ft_strchr('\n', buffer))
			break ;
	}
	return (buffer);
}

static char	*check_line(char *buffer)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	new_line = ft_calloc(i + 1, sizeof(char));
	if (!new_line)
		return (NULL);
	while (buffer[j] && buffer[j] != '\n')
	{
		new_line[j] = buffer[j];
		j++;
	}
	if (buffer[j] == '\n' && buffer[j])
		new_line[j] = '\n';
	return (new_line);
}

static char	*clean_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*save;

	i = 0;
	if (!buffer[0])
	{
		free(buffer);
		return (NULL);
	}
	while (buffer[i] != '\n' && buffer[i])
		i++;
	save = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!save)
	{
		free(buffer);
		return (NULL);
	}
	j = -1;
	if (buffer[i])
		i++;
	while (buffer[i + (++j)])
		save[j] = buffer[i + j];
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	if (buffer[0])
		line = check_line(buffer);
	buffer = clean_buffer(buffer);
	return (line);
}
